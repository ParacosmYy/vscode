#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define maxsize 100 // 栈的最大长度

typedef struct calculate { // 定义栈
    char data[maxsize]; // 栈的元素
    int top; // 栈顶指针
    char str[maxsize];//存放double类型的小数
} stack;

void initstack(stack *s) { // 初始化栈
    s->top = -1;
}

void push(stack *s, char c) { // 入栈
    if (s->top == maxsize - 1) {
        printf("栈满\n");
    } else {
        s->data[++(s->top)] = c;
    }
}   


char pop(stack *s) { // 出栈
    if (s->top == -1) {
        printf("栈空\n");
        return '\0';
    } else {
        return s->data[(s->top)--];
    }
}


char gettop(stack *s) { // 取栈顶元素
    if (s->top == -1) {
        printf("栈空\n");
        return '\0';
    } else {
        return s->data[s->top];
    }
}

int isempty(stack *s) { // 判断栈是否为空
    return s->top == -1;
}

int getpriority(char c) { // 获取运算符的优先级
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
char *deleteSpace(char *str) { // 删除空格
    char *newstr = (char*)malloc(maxsize * sizeof(char)); // 分配内存
    if (newstr == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            newstr[j++] = str[i];
        }
        i++;
    }
    newstr[j] = '\0'; // 添加字符串结束符
    return newstr;
}

char *transform(char *str) {  
    stack oper; // 存放运算符栈区  
    initstack(&oper);  
    char *postfix = (char*)malloc(maxsize * sizeof(char)); // 存放后缀表达式  
    if (!postfix) {  
        printf("内存分配失败\n");  
        exit(1); // 检查内存分配是否成功  
    }  
    int i = 0, j = 0;  
    while (str[i] != '\0') {  
        if (str[i] == ' ') { // 如果当前字符是空格，则跳过  
            i++;  
        } else if (str[i] >= '0' && str[i] <= '9') { // 如果当前字符是数字  
            while (str[i] >= '0' && str[i] <= '9') {  
                postfix[j++] = str[i++];  
            }  
            postfix[j++] = ' '; // 数字后面加空格  
        } else if (str[i] == '(') { // 如果当前字符是左括号，则入栈  
            push(&oper, str[i++]);  
        } else if (str[i] == ')') { // 如果当前字符是右括号，则出栈直到遇到左括号  
            while (!isempty(&oper) && gettop(&oper) != '(') {  
                postfix[j++] = pop(&oper);  
                postfix[j++] = ' ';  
            }  
            if (!isempty(&oper) && gettop(&oper) == '(') {  
                pop(&oper); // 弹出左括号，但不添加到后缀表达式  
            }  
            i++; // 更新索引以跳过右括号  
        } else { // 如果当前字符是运算符  
            while (!isempty(&oper) && getpriority(gettop(&oper)) >= getpriority(str[i])) {  
                postfix[j++] = pop(&oper);  
                postfix[j++] = ' ';  
            }  
            push(&oper, str[i++]);  
        }  
    }  
  /* 将剩下的运算符全部出栈 */
    while (!isempty(&oper)) {  
        postfix[j++] = pop(&oper);  
        postfix[j++] = ' ';  
    }  
  
    postfix[j] = '\0'; // 在字符串末尾添加结束符  
  
    return (postfix);  
}
int charToDigit(char c)//将字符转换为数字
{  
    return c - '0';  
}
double apply_oprator(double a, double b, char op) //操作数计算
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0)
                return a / b;
            else
            {
                printf("除数不能为0\n");
                exit(1);
            }
        case '%':
            if (b != 0)
                return fmod(a, b); // 使用 fmod 函数进行浮点数取余
            else
            {
                printf("取余不能为0\n");
                exit(1);
            }
        default:
            return 0;
    }    
}
double calculate(char *postfix)//计算后缀表达式
{
    stack value;
    initstack(&value);
    int i = 0;
    double num = 0;
    int count = 0;
    int n = 0;
    while (postfix[i] != '\0') 
    {
        if (isspace(postfix[i])) 
        { // 跳过空格
            i++;
        } 
        else if (isdigit(postfix[i])) 
        { // 处理数字
            double tempNum = 0; // 使用临时变量存储数字
            while (isdigit(postfix[i])) 
            {
                tempNum = tempNum * 10 + charToDigit(postfix[i]);
                i++;
            }
        push(&value, tempNum); // 将完整的数字入栈
        }       
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%') 
        { // 处理运算符
            double b = pop(&value);
            printf("pop b=%f\n",b);//调试
            double a = pop(&value);
            printf("pop a=%f\n",a);//调试
            push(&value, apply_oprator(a, b, postfix[i]));
            printf("postfix的符号:%c\n",postfix[i]);
            printf("push %f\n",apply_oprator(a, b, postfix[i]));//调试
            i++;
        }
    }
    return pop(&value); // 返回最终结果
}

int main() {
    char infix[] = "10 + 2 * (3 + 4) * 5 - 2 / 6";
    char *postfix;
    printf("中缀表达式 : %s\n",infix);
    postfix = transform(infix);
    printf("后缀表达式(未处理版本): %s\n", postfix);
    printf("后缀表达式(处理后版本): %s\n", deleteSpace(postfix));
    double result = calculate(postfix);
    printf("计算结果: %f\n", result);
    free(postfix); // 释放分配的内存
    return 0;
}