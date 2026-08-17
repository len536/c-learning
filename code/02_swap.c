/*
 * Day 9 指针与函数：传值 vs 传址
 * 传值 = 给复印件（改不动原件）；传地址 = 给门牌号（能改原件）
 */
#include <stdio.h>

/* 传值：交换失败，a b 是 x y 的复印件 */
void swap_bad(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/* 传地址：交换成功，*a *b 直接改原件 */
void swap_good(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 3, y = 7;

    swap_bad(x, y);
    printf("传值后: x=%d y=%d  (没换，复印件改不动原件)\n", x, y);

    swap_good(&x, &y);
    printf("传址后: x=%d y=%d  (换了，门牌号直击原件)\n", x, y);

    return 0;
}
