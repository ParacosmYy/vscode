//#include <stdio.h>
//#include <string.h>
//int compareReturn(char str1) {
//    if (str1 == '#') {
//        return 0;
//    } else if (str1 == '+' || str1 == '-') {
//        return 1;
//    } else if (str1 == '*' || str1 == '/') {
//        return 2;
//    } else {
//        printf("输入了无效符号");
//        return -1;
//    }
//}
//int jisuan(int x, char str1, int y) {
//    int ans = 0;
//    if (str1 == '+') {
//        ans = x + y;
//    } else if (str1 == '-') {
//        ans = x - y;
//    } else if (str1 == '*') {
//        ans = x * y;
//    } else if (str1 == '/') {
//        ans = x / y;
//    } else {
//        ;
//    }
//    return ans;
//}
//int main(int argc, const char * argv[]) {
//    // 初始化两个栈
//    // 第一个栈为数字栈
//    // 第二个栈为符号栈
//    int firstStack [100] = {0};
//    int firstTop = -1;
//    char secondStack [100] = {'#'};
////    printf("%c", secondStack[0]);
//    int secondTop = 0;
//    char str[100];
//    int flag = -1;
////    printf("请输入待计算的算术表达式:\n");
//    scanf("%s", str);
//    // 表达式长度
//    int x = 0;
//    int length = (int)strlen(str);
//    for (int i = 0; i < length;) {
//        if (str[i] >= '0' && str[i] <= '9') {
//            x *= 10;
//            x += str[i++] - '0';
//            flag=1;
//        } else {
//            if(flag==1)
//            {
//            firstStack[++firstTop] = x;
//            x = 0;
//            flag=-1;
//            }
//            if (compareReturn(secondStack[secondTop]) < compareReturn(str[i])) {
//                secondStack[++secondTop] = str[i++];
//            } else {
//                int b = firstStack[firstTop--];
//                int a = firstStack[firstTop--];
//                firstStack[++firstTop] = jisuan(a, secondStack[secondTop], b);
//                secondTop--;
//                if (str[i] == '#' && secondTop == 0) {
//                    break;
//                }
//            }
//        }
//    }
//    printf("%d", firstStack[firstTop]);
//}


#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
// 函数声明  
int compareReturn(char str1);  
int jisuan(int x, char str1, int y);  
void evaluateExpression(const char* str);  
  
int main() {  
    char str[100];  
    printf("请输入待计算的算术表达式（支持+,-,*,/,()）：\n");  
    scanf("%s", str);  
    evaluateExpression(str);  
    return 0;  
}  
  
int compareReturn(char str1) {  
    if (str1 == '#') {  
        return 0;  
    } else if (str1 == '(') {  
        // 左括号，不比较优先级，仅作为标记  
        return -1;  
    } else if (str1 == '+' || str1 == '-') {  
        return 1;  
    } else if (str1 == '*' || str1 == '/') {  
        return 2;  
    } else if (str1 == ')') {  
        // 右括号，用于结束括号内的计算  
        return 3;  
    } else {  
        printf("输入了无效符号: %c\n", str1);  
        exit(EXIT_FAILURE);  
    }  
}  
  
int jisuan(int x, char str1, int y) {  
    int ans = 0;  
    if (str1 == '+') {  
        ans = x + y;  
    } else if (str1 == '-') {  
        ans = x - y;  
    } else if (str1 == '*') {  
        ans = x * y;  
    } else if (str1 == '/') {  
        if (y == 0) {  
            printf("错误：除以零\n");  
            exit(EXIT_FAILURE);  
        }  
        ans = x / y;  
    }  
    return ans;  
}  
  
void evaluateExpression(const char* str) {  
    // 初始化两个栈  
    int firstStack[100] = {0};  
    int firstTop = -1;  
    char secondStack[100] = {'#'};  
    int secondTop = 0;  
    int x = 0;  
    int length = strlen(str);  
    int i = 0;  
  
    while (i < length) {  
        if (str[i] >= '0' && str[i] <= '9') {  
            x *= 10;  
            x += str[i++] - '0';  
        } else {  
            if ((str[i] >= '0' && str[i] <= '9') == 0 && x != 0) {  
                firstStack[++firstTop] = x;  
                x = 0;  
            }  
  
            if (str[i] == '(') {  
                // 遇到左括号，压入符号栈（这里简化为不压，但记录一个“进入括号”的状态）  
                secondStack[++secondTop] = str[i++];  
            } else if (str[i] == ')') {  
                // 遇到右括号，计算括号内的表达式  
                while (secondTop > 0 && secondStack[secondTop] != '(') {  
                    int b = firstStack[firstTop--];  
                    int a = firstStack[firstTop--];  
                    char op = secondStack[secondTop--];  
                    firstStack[++firstTop] = jisuan(a, op, b);  
                }  
                // 弹出左括号  
                secondTop--;  
                i++;  
            } else {  
                // 处理运算符  
                while (secondTop > 0 && compareReturn(secondStack[secondTop]) >= compareReturn(str[i])) {  
                    int b = firstStack[firstTop--];  
                    int a = firstStack[firstTop--];  
                    char op = secondStack[secondTop--];  
                    firstStack[++firstTop] = jisuan(a, op, b);  
                }  
                secondStack[++secondTop] = str[i++];  
            }  
        }  
    }  
  
    // 如果还有数字在栈中，说明是最后一个数字（没有后续运算符）  
    if (x != 0) {  
        firstStack[++firstTop] = x;  
    }  
  
    // 弹出所有剩余的运算符并计算结果  
    while (secondTop > 0) {  
        int b = firstStack[firstTop--];  
        int a = firstStack[firstTop--];  
        char op = secondStack[secondTop--];  
        firstStack[++firstTop] = jisuan(a, op, b);  
    }  
  
    // 输出最终结果  
    printf("%d\n", firstStack[firstTop]);  
}
