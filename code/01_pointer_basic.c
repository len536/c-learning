/*
 * Day 8 指针基础：& 取地址 / * 解引用
 * 类比：变量是房子，& 是问门牌号，* 是按门牌号找到房子
 */
#include <stdio.h>

int main() {
    int age = 20;
    int *p = &age;          // p 存的是 age 的门牌号（地址）

    printf("age 的值    : %d\n", age);
    printf("&age 的地址 : %p\n", &age);
    printf("p 的值(地址): %p\n", p);
    printf("*p 解引用   : %d\n", *p);

    *p = 21;                // 通过指针改房子里的值
    printf("改后 age    : %d\n", age);

    return 0;
}
