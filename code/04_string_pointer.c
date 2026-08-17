/*
 * Day 11 字符串与指针
 * 1. 数组版 char arr[]：内容可改
 * 2. 指针版 char *p：指向只读字面量，改会段错误（下面注释里有演示）
 * 3. 手写 my_strlen：指针遍历，遇到 \0 停
 */
#include <stdio.h>

/* 手写 strlen：参数 const char* 表示「只读，不改内容」 */
int my_strlen(const char *s) {
    const char *p = s;
    while (*p)          /* 遇到 \0（ASCII=0，为假）自动停 */
        p++;
    return p - s;
}

int main() {
    /* 数组版：编译器划 6 个盒子，内容可以改 */
    char arr[] = "hello";
    arr[0] = 'H';
    printf("数组版改后: %s\n", arr);

    /* 指针版：指向程序只读区，下面这行会段错误（崩），先注释掉 */
    /* char *p = "hello"; */
    /* p[0] = 'H';  // 崩！只读区不能改 */

    /* my_strlen 测试 */
    char *msg = "hello world";
    printf("\"%s\" 长度 = %d\n", msg, my_strlen(msg));

    return 0;
}
