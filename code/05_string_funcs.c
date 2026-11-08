/* MinGW 8.x 的 printf 默认不带 C99 的 %zu 修饰符，需要打开 ANSI stdio */
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>

// 示例：常用字符串库函数用法对比
int main() {
    char s1[100] = "Hello";
    char s2[100] = "World";
    char s3[100];

    // strlen: 求长度
    printf("s1 长度: %zu\n", strlen(s1));  // 5

    // strcpy: 复制
    strcpy(s3, s1);
    printf("复制后 s3: %s\n", s3);  // Hello

    // strcat: 拼接
    strcat(s1, " ");
    strcat(s1, s2);
    printf("拼接后 s1: %s\n", s1);  // Hello World

    // strcmp: 比较
    int cmp = strcmp("apple", "banana");
    if (cmp < 0) {
        printf("apple < banana\n");
    } else if (cmp > 0) {
        printf("apple > banana\n");
    } else {
        printf("相等\n");
    }

    // strlen vs sizeof 区别
    char msg[] = "Hello";
    printf("strlen(msg) = %zu\n", strlen(msg));  // 5，只看内容
    printf("sizeof(msg) = %zu\n", sizeof(msg));  // 6，包含 \0

    return 0;
}
