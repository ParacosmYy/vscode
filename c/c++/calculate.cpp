#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 100 // 栈的最大长度

typedef struct calculate { // 定义栈
    char data[maxsize]; // 栈的元素
    int top; // 栈顶指针
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

char *transform(char *str) {  
    stack value; // 存放操作数栈区
    stack oper;  // 存放运算符栈区  
    initstack(&value);  
    initstack(&oper);  
    char *postfix = (char*)malloc(maxsize * sizeof(char)); // 存放后缀表达式  
    int i = 0, j = 0;  
    if (!postfix) {  
        printf("内存分配失败\n");  
        exit(1); // 检查内存分配是否成功  
    }  
  
    while (str[i] != '\0') {  
        if (str[i] == ' ') { // 如果当前字符是空格，则跳过  
            i++;  
        } else if (str[i] >= '0' && str[i] <= '9') { // 如果当前字符是数字，则数字入栈
            while (str[i] >= '0' && str[i] <= '9') {  
                postfix[j++] = str[i++];  
            }  
            postfix[j++] = ' '; // 数字之间用空格隔开（为了后续解析方便）  
            postfix[j] = '\0'; // 临时添加字符串结束符以检查（稍后会被覆盖）  
            j--; // 移除刚才添加的字符串结束符  
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
            char topOper = '\0';  
            while (!isempty(&oper) && (topOper = gettop(&oper)) != '\0' && getpriority(topOper) >= getpriority(str[i]))/* 从运算符栈oper中弹出所有优先级高于或等于当前遇到的新运算符的运算符，并将它们追加到后缀表达式中。 */
            {  
                postfix[j++] = pop(&oper);  
                postfix[j++] = ' ';  
            }  
            push(&oper, str[i++]);  
        }  
    }  
  
    // 将输入的表达式遍历完毕后，将剩余的运算符从运算符栈中弹出  
    while (!isempty(&oper)) {  
        postfix[j++] = pop(&oper);  
        postfix[j++] = ' ';  
    }  
  
    postfix[j] = '\0'; // 在字符串末尾添加结束符  
  
    return postfix;  
}

int main() {
    char infix[] = "101 + 2 * (3 + 4) * 5 - 1 / 2";
    char *postfix;
    postfix = transform(infix);
    printf("后缀表达式: %s\n", postfix);
    free(postfix); // 释放分配的内存
    return 0;
}
