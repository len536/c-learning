/* Day 20 · 结构体数组：一摞学生卡片的批量管理
 * 题目：输入 n 个学生（姓名/年龄/成绩），输出全部信息 + 平均分 + 最高分学生
 * 知识点：结构体数组 / 遍历统计 / 数组传参退化为结构体指针
 */
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int  age;
    float score;
} Student;

/* 传整摞卡片：数组名退化成 Student*（Day 10 老话），n 单独传长度 */
void print_all(const Student *arr, int n) {
    printf("---- 全体学生 ----\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s age:%d score:%.2f\n", arr[i].name, arr[i].age, arr[i].score);
    }
}

int main(void) {
    Student stus[50];
    int n;
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%19s %d %f", stus[i].name, &stus[i].age, &stus[i].score);
    }

    print_all(stus, n);

    /* 统计：一趟循环求 总分 + 最高分下标 */
    float sum = 0.0f;
    int best = 0;                       /* 最高分学生的下标 */
    for (int i = 0; i < n; i++) {
        sum += stus[i].score;
        if (stus[i].score > stus[best].score) best = i;
    }
    printf("平均分: %.2f\n", sum / n);
    printf("最高分: %s (%.2f)\n", stus[best].name, stus[best].score);
    return 0;
}
