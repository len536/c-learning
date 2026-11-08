/*
 * Day 17 · 手写字符串库函数 · ⭐⭐
 * 不调 <string.h>，手写 my_strlen / my_strcpy / my_strcmp / my_strcat
 *
 * 练习方式：先自己写一遍，再对照文末「关键点 / 易错点」复盘
 */
#include <stdio.h>

/* ---------- 手写工具函数 ---------- */

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

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
    return s1[i] - s2[i];
}

void my_strcat(char *dst, const char *src) {
    int i = 0, j = 0;
    while (dst[i] != '\0') i++;        /* 走到 dst 的 \0 位置 */
    while (src[j] != '\0') {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';                      /* 补新的 \0 */
}

/* ---------- 主函数测试 ---------- */

int main(void) {
    int n;
    char s1[200], s2[200], op[10];

    scanf("%d", &n);
    getchar();  /* 吃掉 scanf 残留的换行 */

    for (int t = 0; t < n; t++) {
        /*
         * 每行格式：op s1 s2
         * op: COPY / CMP / CAT
         * s1 s2: 两个字符串（不含空格）
         */
        scanf("%s %s %s", op, s1, s2);

        if (my_strcmp(op, "COPY") == 0) {
            char dst[200];
            my_strcpy(dst, s1);
            printf("%s\n", dst);
        } else if (my_strcmp(op, "CMP") == 0) {
            int diff = my_strcmp(s1, s2);
            if (diff == 0)
                printf("EQUAL\n");
            else if (diff > 0)
                printf("GREATER\n");
            else
                printf("LESS\n");
        } else if (my_strcmp(op, "CAT") == 0) {
            /* s1 实际上需要够大来容纳拼接结果
             * 这里 s1[200] 足够 */
            my_strcat(s1, s2);
            printf("%s\n", s1);
        }
    }

    return 0;
}

/*
 * ========== 测试用例 ==========

 * 用例 1（COPY）:
 * 输入:
3
Copy hello world
 * 输出:
hello

 * 用例 2（CMP 相等）:
 * 输入:
1
CMP abc abc
 * 输出:
EQUAL

 * 用例 3（CMP 大于）:
 * 输入:
1
CMP abd abc
 * 输出:
GREATER

 * 用例 4（CAT 拼接）:
 * 输入:
1
CAT hello world
 * 输出:
helloworld

 * 用例 5（边界：空串 COPY）:
 * 输入:
1
COPY a b
 * 输出:
a

 * ========== 关键点 ==========
 * 1. strcpy 循环只拷到 src[i] != '\0'，\0 本身没进循环 → 必须手动 dst[i]='\0' 补上
 * 2. strcmp 返回的是 s1[i]-s2[i] 的差值，不是 -1/0/1；只看正负判断大小
 * 3. strcat 先 while(dst[i]) 走到 \0 位置（那是接续的起点），再从那儿开始拷 src
 *
 * ========== 易错点 ==========
 * - 忘补 \0：打印越界读乱码（strcpy / strcat 都会中招）
 * - strcmp 拿去比长度：C 的 strcmp 从头逐字符比 ASCII，不是比谁长
 * - strcat 的 dst 不够大：缓冲区溢出（经典安全漏洞）
 * - scanf("%s") 读不了空格，字符串带空格要换 fgets
 *
 * ========== 拓展问题 ==========
 * 把 my_strcpy 改成指针写法：while (*src) *dst++ = *src++; *dst='\0';
 * 区别在哪？（提示：指针版省了 i++ 的下标计算，但逻辑完全等价）
 */
