/* 整数转字符串：sprintf 一行流 + 手写 my_itoa 原理版
 * 配套知识点：printf 家族 + '0'+d 数字变字符 + 手动反转
 */
#define __USE_MINGW_ANSI_STDIO 1   /* MinGW 用 C99 版 printf，%lld 不报警告 */
#include <stdio.h>
#include <string.h>                /* strcmp */

/* 手写 itoa：返回字符串长度
 * 思路：n%10 从个位往外薅，'0'+d 变字符存进 buf，最后反转 */
int my_itoa(long long n, char buf[]) {
    int len = 0;
    if (n == 0) {                 /* 特例：0 没法进循环，单独补 */
        buf[len++] = '0';
    }
    while (n > 0) {
        buf[len++] = '0' + n % 10;  /* 数字变字符（跟 c-'0' 正好反向） */
        n /= 10;                    /* 丢掉个位，继续薅 */
    }
    buf[len] = '\0';                /* 别忘了终止符！ */

    /* 刚才薅出来是倒的（102030 → "030201"），头尾交换反转 */
    for (int i = 0; i < len / 2; i++) {
        char t = buf[i];
        buf[i] = buf[len - 1 - i];
        buf[len - 1 - i] = t;
    }
    return len;
}

int main(void) {
    long long tests[] = {102030, 7, 0, 123456789012LL};
    char a[32], b[32];

    for (int i = 0; i < 4; i++) {
        sprintf(a, "%lld", tests[i]);   /* 一行流：printf 往 buf 打 */
        my_itoa(tests[i], b);           /* 手写原理版 */
        printf("n=%-12lld sprintf:\"%s\"  my_itoa:\"%s\"  %s\n",
               tests[i], a, b,
               /* strcmp 逐字符比，相同返回 0，==0 即一致 */
               strcmp(a, b) == 0 ? "一致✓" : "不一致✗");
    }
    return 0;
}
