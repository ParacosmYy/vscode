#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define size 25

int stack[size];
int top=-1;

void push(int a)//入栈
{
    if(size-1==top)
    {
        printf("栈区已满");
        return ;
    }
    top=top+1;
    stack[top]=a;
}
void pop(int a)//出栈
{
    if(top==-1)
    {
        printf("栈区已空");
        return ;
    }
    top=top-1;
}

int arr[size]={0};
int front=0;
int rear=0;

void queen_en(int value)//入队
{
    if(rear==size)
    {
        printf("队列已满");
        return ;
    }
    else
    {   printf("入队元素为：%d",value);
        arr[rear]=value;
        rear++;
    }

}
void queen_de(int value)//出队
{
    if(front==rear)
    {
        printf("队列已空");
        return ;
    }
    else 
    {
        printf("出队元素为：%d",arr[front]);
        front++;
    }
}

/* 两栈共享空间 */
# define maxsize 10
typedef struct 
{
    int data[maxsize];
    int top1;
    int top2;
} double_stack;
bool push(double_stack *s,int value,int flag)
{
    if(s->top1+1==s->top2)
    {
        printf("栈区已满");
        return false;
    }
    if(flag==1)
    {
        s->data[++s->top1]=value;//入栈1
    }
    else if(flag==2)
    {
        s->data[--s->top2]=value;//入栈2
    }
    return true;
}
bool pop(double_stack *s,int *value,int flag)
{
    if(flag==1)
    {
        if(s->top1==-1)
        {
            printf("栈1已空");
            return false;
        }
        *value=s->data[s->top1--];
    }
    else if(flag==2)
    {
        if(s->top2==maxsize)
         {
            printf("栈2已空");
            return false;
         }
         *value=s->data[s->top2++];
    }
    return true;
}

/* 链式存储栈区 */
typedef struct stacknode
{
    int data;
    struct stacknode *next;
}stacknode , *linkstack_ptr;
typedef struct linkstack
{
    linkstack_ptr top;
    int count;
}linkstack;
/* 进栈操作 */
bool push(linkstack *s,int value)
{
    linkstack_ptr p=(linkstack_ptr)(malloc(sizeof(stacknode)));
    p->data=value;
    p->next=s->top;
    s->top=p;
    s->count++;
    return true;
}
/* 出栈操作 */
bool pop(linkstack *s,int *value)
{
    linkstack_ptr p;
    if(s->top==NULL)
    {
        printf("栈区已空");
        return false;
    }
    *value = s->top->data;
    p=s->top;
    s->top=s->top->next;
    free(p);
    s->count--;
    return true;
}
/* 斐波那契数列（递归） */
int fibonacci(int n)
{
    if(n<2)
    {
        return n==0 ? 0 : 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}


/* 括号匹配 */
//定义栈结构
typedef struct 
{
    char data[maxsize];
    int top;
}sqstack;
//初始化栈
void initstack(sqstack *s)
{
    s->top=-1;
}
//入栈
bool push(sqstack *s,char value)
{
    if(s->top==maxsize-1)
    {
        printf("栈区已满");
        return false;
    }
    s->data[++s->top]=value;
    return true;
}
//出栈
bool pop(sqstack *s,char value)
{
    if(s->top==-1)
    {
        printf("栈区已空");
        return false;
    }
    value=s->data[s->top--];
    return true;
}
//判断栈区是否为空
bool isempty(sqstack *s)
{
    if(s->top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//括号匹配检查
bool bracketcheck (char str[],int length)
{
    sqstack q;
    initstack(&q);
    for(int i = 0;i<length;i++)
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
            push(&q,str[i]);
        }
        else if(str[i]==')'||str[i]==']'||str[i]=='}')
        {
            if(isempty(&q))
            {
                return false;
            }
        }
        char topvalue;
        pop(&q,topvalue);
        switch(str[i])
        {
            case ')':
                if(topvalue!='(')
                {
                    return false;
                }
            case ']':
                if(topvalue!='[')
                {
                    return false;
                }
            case '}':
                if(topvalue!='{')
                {
                    return false;
                } 
        }
    }
    return isempty(&q);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//队列开头
int a[10]; //定义一个数组
//循环队列
typedef struct
{
    int data[maxsize];
    int front;
    int rear;
}sqqueue;
//初始化队列
void initqueue(sqqueue *q)
{
    q->front=q->rear=0;
}
//求队列长度
int queue_length(sqqueue q)
{
    return (q.rear+maxsize-q.front);
}
//入队
bool enqueue(sqqueue *q,int value)
{
    if((q->rear+1)%maxsize==q->front)
    {
        printf("队列已满");
        return false;
    }
    else 
    {
        q->data[q->rear]=value;
        q->rear=(q->rear+1)%maxsize;
        return true;
    }
}
//出队
bool dequeue(sqqueue *q,int *value)
{
    if(q->rear==q->front)
    {
        printf("队列为空");
        return false;
    }
    else 
    {
        *value=q->data[q->front];
        q->front=(q->front+1)%maxsize;
        printf("出队元素为 %d\n",*value);
        return true;
    }
}
//链式存储
typedef struct Qnode
{
    int data;
    struct Qnode *next;
}Qnode, *qnode_ptr

typedef struct
{
    qnode_ptr front;
    qnode_ptr rear;
}linkqueue;
//初始化队列
void initqueue(linkqueue *q)
{
    q->front=q->rear=(qnode_ptr)malloc(sizeof(Qnode));
    q->front->next=NULL;
}
//入队
bool enqueue(linkqueue *q,int value)
{
    qnode_ptr p;
    p=(qnode_ptr)malloc(sizeof(Qnode));
    if(!p)
    {
        printf("内存分配失败");
    }
    p->data=value;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return true;
}
//出队
bool dequeue(linkqueue *q,int *value)
{
    qnode_ptr p;//定义一个指针
    if(q->front==q->rear)
    {
        printf("队列为空");
        return false;
    }
    p=q->front->next;
    *value=p->data;
    q->front->next=p->next;//将队头指针指向下一个元素
    if(q->rear==p)
    {
        q->rear=q->front;
    }
    free(p);
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    return 0;
}