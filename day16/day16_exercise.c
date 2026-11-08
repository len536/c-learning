/* Day 16 · 字符串逆序（不调库）
 * 输入：一个不含空格的字符串（长度 1~1000）
 * 输出：逆序后的字符串
 * 要求：原地逆序（不开第二个数组），不许用 strrev 等现成函数
 *
 * 思路：头尾双指针往中间走，边走边换（Day 14 的套路 + Day 6 的 swap）
 */
#include <stdio.h>

int main(void) {
    char s[1005];
    if (scanf("%s", s) != 1) return 1;   /* %s 遇空格/换行停，正好读一个词 */

    /* 不调库手数长度：从 s[0] 走到 \0 为止（strlen 内部就是这么干的） */
    int len = 0;
    while (s[len] != '\0') len++;

    /* 头尾双指针原地交换：left 从 0 出发，right 从最后一个字符出发 */
    for (int left = 0, right = len - 1; left < right; left++, right--) {
        char t = s[left];      /* 三步换位：跟 Day 6 swap 一模一样 */
        s[left] = s[right];
        s[right] = t;
    }
    /* left == right 时（奇数长度）中间字符不用动；\0 一直待在原地没被碰 */

    printf("%s\n", s);
    return 0;
}
