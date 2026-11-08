/* Day 14 · 二级指针入门
 * 题目：输入 n 和 n 个整数，用指针数组 + 二级指针解引用求所有元素和
 *
 * 关键点：
 *   - 主函数里的 int *ptrs[n] 是「指针数组」(n 个 int* 拼起来)
 *   - 函数参数 int **ptrs 跟主函数的 int *ptrs[] 等价 (编译器自动 decay)
 *   - 解引用层数：ptrs 是 int**、*ptrs / ptrs[i] 是 int*、**ptrs / *ptrs[i] 是 int
 *
 * 易错点：
 *   - 函数签名少写一个 * (写成 int *ptrs, sum += *ptrs[i] 会越界访问)
 *   - 忘 ptrs[i] = &arr[i] 直接用 (段错误)
 *   - ptrs[i][j] = ptrs[i] 解到的 int* 再 [j] → 越界
 */

#include <stdio.h>

/* 函数形参 int **ptrs 对应主函数里的 int *ptrs[] (数组名 decay 成首元素地址) */
int sum_by_ptrs(int **ptrs, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *ptrs[i];             /* 等价于 sum += **(ptrs + i) */
    }
    return sum;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int arr[100];
    int *ptrs[100];                  /* 指针数组：每个元素都是一个 int* */

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        ptrs[i] = &arr[i];           /* 第 i 个指针指向 arr 的第 i 项 */
    }

    int total = sum_by_ptrs(ptrs, n);
    printf("%d\n", total);
    return 0;
}
