#include<stdio.h>
typedef struct 
{
    float Kp, Ki, Kd;
    float error,last_error;
    float integral,max_intergral;
    float output,max_output;
}PID;

void PID_Init(PID *pid,float Kp,float Ki,float Kd,float max_output,float max_intergral)
{
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->max_output = max_output;
    pid->max_intergral = max_intergral;
}

float PID_Calc(PID *pid,float setpoint,float feedback)
{
    pid->last_error = pid->error;
    pid->error = setpoint - feedback;
    pid->integral += pid->error;
    if(pid->integral > pid->max_intergral)
    {
        pid->integral = pid->max_intergral;
    }
    else if(pid->integral < -pid->max_intergral)
    {
        pid->integral = -pid->max_intergral;
    }
    pid->output = pid->Kp * pid->error + pid->Ki * pid->integral + pid->Kd * (pid->error - pid->last_error);
    if(pid->output > pid->max_output)
    {
        pid->output = pid->max_output;
    }
    else if(pid->output < -pid->max_output)
    {
        pid->output = -pid->max_output;
    }
    return pid->output;
}

//一阶滤波算法
float Filter(float input,float output,float alpha)
{
    return alpha * input + (1 - alpha) * output;
}
PID my_pid={0};
/*int main()
{
    PID_Init(&my_pid,0.5,0.5,0.5,100,100);
    while(1)
    {
        float setpoint=scanf("%f",&setpoint);
        float feedback=scanf("%f",&feedback);
        float output=PID_Calc(&my_pid,setpoint,feedback);
        printf("%f\n",output);
    }
    return 0;
}*/


//串级pid
typedef struct
{
    PID inner;
    PID outer;
    float output;
}CascadePID;

void PID_Cascade_Calculate(CascadePID *pid , float outerReference,float outerfeedback,float innerfeedback)
{
    PID_Calc(&pid->outer,outerReference,outerfeedback);
    PID_Calc(&pid->inner,pid->outer.output,innerfeedback);
    pid->output = pid->inner.output;
}

//模拟设定执行器输出大小的函数
void set_output(float output)
{
    printf("output:%f\n",output);
}
//模拟获取反馈值函数
float get_feedback()
{
    float feedback;
    scanf("%f",&feedback);
    return feedback;
}
//模拟获取目标值函数
float get_reference()
{
    float reference;
    scanf("%f",&reference);
    return reference;

}
//创建PID结构体变量
CascadePID MY_pid={0};

int main()
{
    //初始化内环PID
    PID_Init(&MY_pid.inner,0.5,0.5,0.5,100,100);
    //初始化外环PID
    PID_Init(&MY_pid.outer,0.5,0.5,0.5,100,100);
    while(1)
    {
        float outer_reference=get_reference();
        float outer_feedback=get_feedback();
        float inner_feedback=get_feedback();
        PID_Cascade_Calculate(&MY_pid,outer_reference,outer_feedback,inner_feedback);
        set_output(my_pid.output);
    }
    return 0;
}