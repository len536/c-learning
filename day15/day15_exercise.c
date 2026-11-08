/* Day 15 · 指针 + 结构体入门
 * 题目：定义 Student 结构体 (name / age / score)，
 *       写 print_student 函数接收 Student 指针，
 *       在 main 里定义一个学生并调用 print_student 打印。
 *
 * 关键点：
 *   - struct 像「打包」：把多个不同类型的数据装在同一个类型里
 *   - 结构体指针用 -> 访问成员：ps->age 是 (*ps).age 的语法糖
 *   - 函数接 Student *ps 而不是 Student s：
 *       传结构体 = 复制整个盒子（慢）；
 *       传指针   = 给一张纸条（轻），
 *       改外面 (*ps).age = 20 也方便（直接动原件）
 *
 * 易错点：
 *   - *ps.age 优先级坑：会被解析成 *(ps.age) → ps 是指针没 .age → 编译报错
 *   - char name[20] 别忘了给 \0 留位置 (19 字符 + 1 个 \0)
 *   - 结构体指针必须先初始化 (&stu 或 malloc)，野指针直接段错误
 */

#include <stdio.h>
#include <string.h>     /* strcpy */

/* 先定义结构体类型 —— 像「设计一张学生卡片有几个格子」*/
typedef struct {
    char name[20];      /* 姓名：留 19 字符 + 1 个 \0 */
    int  age;           /* 年龄 */
    float score;        /* 分数 */
} Student;

/* 函数接 Student *ps —— 给门牌号，不复制整个卡片 */
void print_student(Student *ps) {
    printf("name : %s\n", ps->name);    /* 等价于 (*ps).name */
    printf("age  : %d\n", ps->age);
    printf("score: %.2f\n", ps->score);
}

int main(void) {
    Student s;          /* 在栈上划一张卡片 */

    /* name 是字符数组，不能直接 = "Tom"；用 strcpy 把字符串拷进去 */
    strcpy(s.name, "Tom");
    s.age = 19;
    s.score = 92.5f;    /* f 后缀告诉编译器这是 float 不是 double */

    /* 调用：传 &s（s 的门牌号），函数里用 ps 这个指针接 */
    print_student(&s);

    return 0;
}