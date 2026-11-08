/* 力扣 1929 · 数组串联（C 语言 OJ 完整版）
 * 题意：ans 前 n 个 = nums，后 n 个 = nums 再来一遍
 * 输入：第一行 n，第二行 n 个整数
 * 输出：2n 个整数，空格分隔
 */
#include <stdio.h>
#include <stdlib.h>     /* malloc */

/* 力扣签名版：返回 malloc 出来的数组，长度通过 returnSize 带回去 */
int *getConcatenation(int *nums, int numsSize, int *returnSize) {
    /* 关键：2n 个 int 的空间必须 malloc 到堆上
     * —— 不能返回局部数组！局部数组在栈上，函数一结束就没了（Day 23 讲） */
    int *ans = (int *)malloc(2 * numsSize * sizeof(int));
    if (ans == NULL) return NULL;      /* malloc 失败返回 NULL，先判空（Day 22 铁规矩） */

    for (int i = 0; i < numsSize; i++) {
        ans[i] = nums[i];              /* 前半段：原样抄 */
        ans[i + numsSize] = nums[i];   /* 后半段：再抄一遍 */
    }
    *returnSize = 2 * numsSize;        /* 长度信息用指针带出去 = 函数"多返回一个值" */
    return ans;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int nums[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int returnSize;
    int *ans = getConcatenation(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf(i == returnSize - 1 ? "%d\n" : "%d ", *(ans + i));

    free(ans);          /* 堆上的内存用完要还（Day 24 讲野指针） */
    ans = NULL;
    return 0;
}
