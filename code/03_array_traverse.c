/*
 * Day 10 指针与数组：数组遍历三写法
 * arr[i] ≡ *(arr+i)，数组下标就是指针偏移的语法糖
 */
#include <stdio.h>

int main() {
    int nums[5] = {10, 20, 30, 40, 50};
    int len = 5;

    /* 写法1：下标法（最直观） */
    printf("写法1 下标法   : ");
    for (int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    printf("\n");

    /* 写法2：偏移法（nums+i 是指针，* 解引用） */
    printf("写法2 偏移法   : ");
    for (int i = 0; i < len; i++)
        printf("%d ", *(nums + i));
    printf("\n");

    /* 写法3：移动指针法（p++ 跳 1 个元素，int 是 4 字节） */
    printf("写法3 移动指针 : ");
    for (int *p = nums; p < nums + len; p++)
        printf("%d ", *p);
    printf("\n");

    return 0;
}
