/*
#include<stdio.h>
int main()
{
	int m = 1, n = m ++, p = ++n, test = 0, i = 0;
	for(i = 0;i < 10; ++ i)
	{	
		++ test;
		if(p < 5){
			p += 2;
			(m > n) ? ++ m : -- n;
		}else{
			break;
            }
	}
    printf("%d\n",m);
    printf("%d\n",n);
    printf("%d\n",p);
    printf("%d\n",test);
    printf("%d\n",i);
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
	int i = 0, j = 1, k = 1;

	if(i && ++ j)printf("OK\n");

	if(i || ++ k)printf("OK\n");

	if(j == k)printf("T\n");

	else printf("F\n");

	return 0;
}
*/
/*#include<stdio.h>
int main()
{
	int a[10] = {3, 3, 2, 0, 0, 3, 3, 7, 5, 1};
	
	int b[5][2] = {{3, 3}, {2, 0}, {0, 3}, {3, 7}, {5, 1}};
	 *p = (a + 2);
	
	int
	int (*m)[2] = (b + 3);
	
	printf("%d %d", *p, (*m)[1]);
	
	return 0;
}*/
/*#include<stdio.h>

#define INT_PTR int* 

typedef int* int_ptr;

int main()
{
	INT_PTR a, b;

	int_ptr c,d;
	
	printf("sizeof a:%d\n", sizeof(a));
	printf("sizeof a:%d\n", sizeof(b));
	printf("sizeof a:%d\n", sizeof(c));
	printf("sizeof a:%d\n", sizeof(d));
	
	return 0;
}
*/
/*
#include<stdio.h>

int main()
{
	int a = 45, b = 37, c = 11;
	
	printf("%d", b >> 1 | c & (a ^ b));
	
	return 0;
}*/

// #include <stdio.h>

// int main()
// {
// 					int i;
// 					int a[5] = {1,2,3,4,5};

// 					for(int i = 0;i <= 7; ++i){
// 						a[i] = 0;
// 						printf("6");
// 					}

// 					return 0;
// }


#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <stdbool.h>  
  
#define MAX_STACK_SIZE 100  
  
typedef struct {  
    double data[MAX_STACK_SIZE];  
    int top;  
} Stack;  
  
void initStack(Stack *s) {  
    s->top = -1;  
}  
  
bool push(Stack *s, double value) {  
    if (s->top >= MAX_STACK_SIZE - 1) {  
        return false; // 栈满  
    }  
    s->data[++(s->top)] = value;  
    return true;  
}  
  
double pop(Stack *s) {  
    if (s->top < 0) {  
        exit(1); // 栈空  
    }  
    return s->data[(s->top)--];  
}  
  
bool isEmpty(Stack *s) {  
    return s->top < 0;  
}  
  
int charToDigit(char c) {  
    return c - '0';  
}  
  
double applyOperator(double a, double b, char op) {  
    switch (op) {  
        case '+': return a + b;  
        case '-': return a - b;  
        case '*': return a * b;  
        case '/':  
            if (b != 0) return a / b;  
            else {  
                printf("除数不能为0\n");  
                exit(1);  
            }  
        case '%':  
            if (b != 0) return (double)((int)a % (int)b); // 强制转换为int进行取余，然后转换回double  
            else {  
                printf("取余的除数不能为0\n");  
                exit(1);  
            }  
        default: return 0; // 不应该发生  
    }  
}  
  
double calculate(char *postfix) {  
    Stack valueStack;  
    initStack(&valueStack);  
  
    int i = 0;  
    while (postfix[i] != '\0') {  
        if (isspace(postfix[i])) {  
            i++;  
            continue;  
        }  
  
        if (isdigit(postfix[i])) {  
            double num = 0;  
            while (isdigit(postfix[i])) {  
                num = num * 10 + charToDigit(postfix[i]);  
                i++;  
            }  
            i--; // 因为while循环会多走一步，所以这里要减回来  
            push(&valueStack, num);  
        } else {  
            double b = pop(&valueStack);  
            double a = pop(&valueStack);  
            double result = applyOperator(a, b, postfix[i]);  
            push(&valueStack, result);  
            i++;  
        }  
    }  
  
    if (!isEmpty(&valueStack)) {  
        return pop(&valueStack);  
    } else {  
        printf("栈为空，无法计算结果\n");  
        exit(1);  
    }  
}  
  
int main() {  
    char postfix[] = "34 56 + 2 * 78 90 -";  
    printf("后缀表达式: %s\n", postfix);  
    double result = calculate(postfix);  
    printf("结果: %lf\n", result);  
    return 0;  
}


