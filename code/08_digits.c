/* 基础拆位：输入一个三位数，纯计算求各个位数
 * 核心：整数除法 / 丢位数，取余 % 拿尾数
 */
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int bai = n / 100;        /* 整数除法丢掉后两位：358/100 = 3 */
    int shi = n / 10 % 10;    /* 先丢个位(358/10=35)，再取尾(35%10=5) */
    int ge  = n % 10;         /* 取余直接拿个位：358%10 = 8 */

    printf("百位=%d 十位=%d 个位=%d\n", bai, shi, ge);
    printf("验证：%d*100 + %d*10 + %d = %d\n", bai, shi, ge, bai*100 + shi*10 + ge);
    return 0;
}
