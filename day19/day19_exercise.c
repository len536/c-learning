/*
 * Day 19 · 结构体定义与嵌套 · ⭐⭐
 *
 * 题目：学生成绩管理
 *
 * 定义一个学生结构体 Student，包含：
 *   - 姓名 char name[20]
 *   - 学号 int id
 *   - 成绩 float score
 *   - 入学日期 Date enroll（嵌套结构体，含 year / month / day）
 *
 * 输入格式：
 *   第一行一个整数 n（1 ≤ n ≤ 100），表示学生数量
 *   接下来 n 行，每行格式：
 *   姓名 学号 成绩 年 月 日
 *   （姓名不含空格，成绩保留 1 位小数）
 *
 * 输出格式：
 *   输出所有学生中成绩最高的那个学生的信息，格式：
 *   姓名 学号 成绩 入学年-入学月-入学日
 *   （成绩保留 1 位小数）
 *   如果有多个并列最高分，输出第一个出现的。
 *
 * 输入样例 1:
 *   3
 *   Tom 1001 88.5 2024 9 1
 *   Jerry 1002 92.0 2024 9 1
 *   Alice 1003 92.0 2024 3 1
 *
 * 输出样例 1:
 *   Jerry 1002 92.0 2024-9-1
 *
 * 输入样例 2:
 *   1
 *   Bob 2001 60.0 2025 2 15
 *
 * 输出样例 2:
 *   Bob 2001 60.0 2025-2-15
 *
 * 输入样例 3（边界：n=1，成绩 0 分）:
 *   1
 *   Zero 3001 0.0 2024 1 1
 *
 * 输出样例 3:
 *   Zero 3001 0.0 2024-1-1
 *
 * 输入样例 4（边界：满分）:
 *   2
 *   Full 4001 100.0 2024 9 1
 *   Low 4002 59.5 2024 9 1
 *
 * 输出样例 4:
 *   Full 4001 100.0 2024-9-1
 *
 * 输入样例 5（并列最高取第一个）:
 *   3
 *   Aa 5001 85.0 2024 9 1
 *   Bb 5002 85.0 2024 8 1
 *   Cc 5003 70.0 2024 7 1
 *
 * 输出样例 5:
 *   Aa 5001 85.0 2024-9-1
 */

#include <stdio.h>

/* 定义日期结构体 */
typedef struct {
    int year;
    int month;
    int day;
} Date;

/* 定义学生结构体，嵌套日期 */
typedef struct {
    char name[20];
    int  id;
    float score;
    Date enroll;
} Student;

int main(void) {
    int n;
    Student stu[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d %f %d %d %d",
              stu[i].name,
              &stu[i].id,
              &stu[i].score,
              &stu[i].enroll.year,
              &stu[i].enroll.month,
              &stu[i].enroll.day);
    }

    /* 找成绩最高的学生（并列取第一个） */
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (stu[i].score > stu[max_idx].score) {
            max_idx = i;
        }
    }

    /* 输出 */
    printf("%s %d %.1f %d-%d-%d\n",
           stu[max_idx].name,
           stu[max_idx].id,
           stu[max_idx].score,
           stu[max_idx].enroll.year,
           stu[max_idx].enroll.month,
           stu[max_idx].enroll.day);

    return 0;
}

/*
 * ========== 关键点 ==========
 * 1. 结构体定义放 main 外面（全局），这样整个文件都能用；放 main 里面也行但作用域受限
 * 2. 嵌套结构体的初始化和赋值：用 stu[i].enroll.year 逐级访问，连续两个点
 * 3. scanf 读结构体成员：name 是数组名（本身就是地址，不加 &），id/score/enroll.xxx 是普通变量（必须加 &）
 * 4. 找最大值套路：用一个变量 max_idx 记下标，遇到更大的就更新——和之前找数组最大值完全一样
 *
 * ========== 易错点 ==========
 * - scanf 读 name 时多加了 &：stu[i].name 已经是 char[20] 的地址，加 & 变成「地址的地址」→ 类型错误
 * - 并列最高分输出最后一个：if 写成 >= 而不是 >，导致后面的覆盖前面的——题目要求取第一个，用严格 > 即可
 * - 结构体数组大小开太小：n 可能到 100，数组至少开 100
 * - 嵌套初始化忘加内层花括号：Student s = {"Tom", 1001, 88.5, 2024, 9, 1} 也行（按顺序拍平），
 *   但 Student s = {"Tom", 1001, 88.5, {2024, 9, 1}} 更清晰——编译器两种都认
 *
 * ========== 拓展问题 ==========
 * 如果题目改成「按成绩从高到低排序后输出全部学生」，你会怎么改？
 * 提示：对结构体数组做排序，用冒泡或选择排序，交换时直接交换整个 Student 变量（结构体可以直接赋值）。
 */
