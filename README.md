# C 语言练习仓库

计算机专业在读，系统练习 C 语言的学习记录。每天一个主题，每个主题包含**可编译运行的代码**和**手写笔记**。

练习重点放在指针、内存与字符串这些 C 的核心机制上，尽量不依赖标准库现成函数，自己实现一遍再对照理解。

## 环境与验证

| 项目 | 说明 |
| --- | --- |
| 编译器 | gcc 8.1.0 (MinGW-w64, x86_64-posix-seh) |
| 编译选项 | `-std=c11 -Wall -Wextra` |
| 状态 | 仓库内全部 `.c` 文件均可编译通过，无错误 |

```bash
gcc -std=c11 -Wall -Wextra day17/day17_exercise.c -o test && ./test
```

## 技术覆盖

| 主题 | 关键内容 | 对应代码 |
| --- | --- | --- |
| 指针基础 | 取地址 `&` 与解引用 `*`、指针与数组、指针算术、三种遍历写法 | [`code/01`](code/01_pointer_basic.c) [`code/03`](code/03_array_traverse.c) |
| 指针与函数 | 传值 vs 传址、用指针在函数内修改调用方变量 | [`code/02_swap.c`](code/02_swap.c) |
| 二级指针 | 指针数组、`int **` 与 `int *[]` 的等价性、多级解引用 | [`day14`](day14/day14_double_pointer.c) |
| 字符串与指针 | `char s[]` vs `char *p` 的内存布局差异 | [`code/04`](code/04_string_pointer.c) [`code/05`](code/05_string_funcs.c) |
| 手写字符串库函数 | 不调 `<string.h>` 实现 `strlen` / `strcpy` / `strcmp` / `strcat` | [`day17`](day17/day17_exercise.c) |
| 字符串处理 | 原地逆序（双指针）、字符分类统计、数字与字符串互转 | [`day16`](day16/day16_exercise.c) [`day18`](day18/day18_exercise.c) [`code/08`](code/08_digits.c) [`code/09`](code/09_int_to_string.c) |
| 结构体 | `typedef`、成员访问 `->`、结构体指针传参、嵌套定义 | [`day15`](day15/day15_exercise.c) [`day19`](day19/day19_exercise.c) |
| 结构体数组 | 批量存储、遍历统计、数组传参退化为结构体指针 | [`day20`](day20/day20_exercise.c) |
| 输入处理 | `scanf` 与 `fgets` 的区别、缓冲区残留换行的处理 | 散见各练习 |

## 重点：手写标准库字符串函数

这是本仓库最核心的一组练习——不看 `<string.h>` 的实现，只按行为描述自己写一遍，再回头对照差异。

```c
void my_strcpy(char *dst, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';   /* 手动补终止符 */
}

int my_strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];   /* 返回差值，不是 -1/0/1 */
}

void my_strcat(char *dst, const char *src) {
    int i = 0, j = 0;
    while (dst[i] != '\0') i++;    /* 先走到 dst 的 \0 位置 */
    while (src[j] != '\0') {
        dst[i] = src[j];
        i++; j++;
    }
    dst[i] = '\0';
}
```

写这几段时踩过的坑，笔记里都记了：

- **忘记补 `\0`**：循环条件是 `src[i] != '\0'`，终止符本身不进循环，必须手动补，否则打印时越界读到乱码
- **误解 `strcmp` 返回值**：它返回的是首个不同字符的 ASCII 差值，不能假设是 `-1 / 0 / 1`，判断大小只能看正负
- **`strcat` 的缓冲区溢出**：目标数组容量不足时没有任何保护，这是 C 里最经典的安全漏洞
- **`scanf("%s")` 读不了空格**：含空格的输入必须换 `fgets`，且要注意末尾的 `\n` 也会被读进来

同一个函数的**指针写法**也单独练过：

```c
while (*src) *dst++ = *src++;
*dst = '\0';
```

指针版省掉了下标计算，逻辑与下标版完全等价——这个对照练习对理解"数组下标本质是指针算术"帮助很大。

## 目录结构

```
c-learning/
├── code/       # 基础示例代码（指针、数组、字符串函数用法）
├── day14/      # 二级指针与指针数组
├── day15/      # 指针 + 结构体入门
├── day16/      # 字符串原地逆序
├── day17/      # 手写字符串库函数
├── day18/      # 字符串综合：字符分类统计
├── day19/      # 结构体定义与嵌套
├── day20/      # 结构体数组
└── notes/      # 每日手写笔记（Markdown）
```

每个练习文件顶部都写了**题目要求、思路、关键点、易错点**，文末附自测用例，可以直接对照输入输出验证。

## 学习方式

- 每天固定一个主题，先自己写，卡住了再看笔记
- 写完把**踩过的坑**记进 `notes/`，不记"知识点罗列"，只记自己真正错过的
- 代码注释里保留思考过程，而不是只写"这里做了什么"
- 提交信息按 `feat:` / `fix:` / `docs:` 分类

## 进度记录

| 日期 | 主题 | 代码 | 笔记 |
| --- | --- | --- | --- |
| 08-13 | 指针基础 / 指针与函数 / 指针与数组 | [`code/01`](code/01_pointer_basic.c) [`code/02`](code/02_swap.c) [`code/03`](code/03_array_traverse.c) | [笔记](notes/2026-08-13-day8-10-指针核心.md) |
| 08-17 | 字符串与指针 | [`code/04`](code/04_string_pointer.c) | [笔记](notes/2026-08-17-day11-字符串指针.md) |
| 08-18 | 字符串库函数用法 | [`code/05`](code/05_string_funcs.c) | [笔记](notes/2026-08-18-day12-字符串库函数.md) |
| 09-08 | 二级指针与指针数组 | [`day14`](day14/day14_double_pointer.c) | — |
| 09-09 | 指针 + 结构体入门 | [`day15`](day15/day15_exercise.c) | [笔记](notes/2026-09-10-day15-结构体指针.md) |
| 09-10 | 字符串原地逆序 | [`day16`](day16/day16_exercise.c) | [笔记](notes/2026-09-10-day16-字符串逆序.md) |
| 09-11 | 手写字符串库函数 | [`day17`](day17/day17_exercise.c) | [笔记](notes/2026-09-11-day17-手写字符串库函数.md) |
| 09-12 | 字符串综合：字符分类统计 | [`day18`](day18/day18_exercise.c) | [笔记](notes/2026-09-12-day18-字符串综合.md) |
| 09-13 | 结构体定义与嵌套 | [`day19`](day19/day19_exercise.c) | [笔记](notes/2026-09-13-day19-结构体定义与嵌套.md) |
| 09-14 | 结构体数组 | [`day20`](day20/day20_exercise.c) | [笔记](notes/2026-09-14-day20-结构体数组.md) |

---

后续计划：动态内存管理（`malloc` / `free` / 内存泄漏排查）、文件操作、链表实现。
