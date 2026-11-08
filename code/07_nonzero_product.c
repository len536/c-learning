/* 力扣 · 非零数字拼接 × 数字和（C 语言 OJ 完整版）
 * 题意：把 n 中所有非零数字按原始顺序连成 x（无非零数字则 x=0），
 *       sum = x 的数字和，返回 x * sum
 * 例：n = 102030 → 非零数字 1,2,3 按序连成 x = 123，
 *     sum = 1+2+3 = 6，答案 = 123 * 6 = 738
 *
 * 思路（字符串法，呼应 Day 16 主线）：
 *   把 n 转成字符串 → 逐字符扫，非 '0' 的字符一边拼 x 一边加 sum
 *   字符转数字的咒语：c - '0'（'7' 的 ASCII 减 '0' 的 ASCII = 7）
 *
 * 暗坑：x 最多可能接近 18~19 位 → int（32位，约 21 亿）装不下
 *   必须用 long long，否则溢出变成乱码答案
 */
/* MinGW 下 %lld 需要 C99 版 stdio：不加这行 gcc 会吐
 * "unknown conversion type character 'l'" 警告（Windows 开发专用坑） */
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>

long long calcProduct(long long n) {
    char buf[32];
    sprintf(buf, "%lld", n);        /* 整数转字符串，一步到位 */

    long long x = 0, sum = 0;
    for (int i = 0; buf[i] != '\0'; i++) {   /* while (buf[i]) 同款遍历 */
        if (buf[i] == '0') continue;          /* 非零才要：跳过 0 */
        int d = buf[i] - '0';                 /* 字符 → 数字 */
        x = x * 10 + d;                       /* 拼接：原数字整体左移一位再放新位 */
        sum += d;                             /* 数字和累加 */
    }
    /* n=0 或全是 0 时循环没拼任何东西：x=0, sum=0，返回 0 正好符合题意 */
    return x * sum;
}

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return 1;
    printf("%lld\n", calcProduct(n));
    return 0;
}
