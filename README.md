# C 语言 30 天打卡

计算机专业自学 C 语言的完整学习仓库：每天的学习笔记 + 课堂示例代码。
目标：30 天从入门到能独立写小项目。

## 学习进度

| Day | 主题 | 日期 | 笔记 |
|-----|------|------|------|
| Day 8 | 指针基础（`&` 取地址 / `*` 解引用） | 08-13 | [笔记](notes/2026-08-13-day8-10-指针核心.md) |
| Day 9 | 指针与函数（传值 vs 传址） | 08-13 | [笔记](notes/2026-08-13-day8-10-指针核心.md) |
| Day 10 | 指针与数组（指针算术 / 遍历三写法） | 08-13 | [笔记](notes/2026-08-13-day8-10-指针核心.md) |
| Day 11 | 字符串与指针（`char str[]` vs `char *p`） | 08-17 | [笔记](notes/2026-08-17-day11-字符串指针.md) |
| Day 12 | 字符串库函数（strcpy / strcmp / strcat） | 08-18 | [笔记](notes/2026-08-18-day12-字符串库函数.md) |
| Day 13 | _（缺记录，待补） | - | - |
| Day 14 | 二级指针（指针数组 + `int **` 解引用求和） | 09-08 | 代码 [day14_double_pointer.c](day14/day14_double_pointer.c) |
| Day 15 | 指针 + 结构体入门（`typedef` / `->` / 传指针） | 09-09 | [笔记](notes/2026-09-10-day15-结构体指针.md) · 代码 [day15_exercise.c](day15/day15_exercise.c) |
| Day 16 | 字符串主线回归：字符串逆序（不调库） | 09-10 | [笔记](notes/2026-09-10-day16-字符串逆序.md) · 代码 [day16_exercise.c](day16/day16_exercise.c) |
| Day 17 | 手写字符串库函数（my_strcpy / my_strcmp / my_strcat） | **09-14 学习中** | [笔记](notes/2026-09-11-day17-手写字符串库函数.md) · 代码 [day17_exercise.c](day17/day17_exercise.c) |
| Day 18 | 字符串综合：字符分类统计（fgets + ctype.h） | 已推送 09-12 ·**未学** | [笔记](notes/2026-09-12-day18-字符串综合.md) · 代码 [day18_exercise.c](day18/day18_exercise.c) |
| Day 19 | 结构体定义与嵌套（typedef / 嵌套 / 初始化） | 已推送 09-13 ·**未学** | [笔记](notes/2026-09-13-day19-结构体定义与嵌套.md) · 代码 [day19_exercise.c](day19/day19_exercise.c) |
| Day 20 | 结构体数组（批量管理 / 遍历统计） | 已推送 09-14 ·**未学** | [笔记](notes/2026-09-14-day20-结构体数组.md) · 代码 [day20_exercise.c](day20/day20_exercise.c) |

> **当前实际进度：Day 17（09-14 冷回复 day17 开始学习）**。Day 18-20 已生成资料但冷未学；推送必须跟随此行，不超前。

## 目录结构

```
c-learning/
├── README.md        # 仓库说明（本文件）
├── notes/           # 每日知识点笔记
└── code/            # 课堂示例代码（可编译运行）
```

## 怎么运行代码

需要 GCC 环境（Windows 用 MinGW）：

```bash
gcc code/04_string_pointer.c -o test && ./test
```

## 打卡规矩

- 每天学完更新笔记，commit message 用规范格式（`feat:` / `fix:` / `docs:` / `refactor:` / `chore:`）
- 每周日晚做一次本周复习汇总
