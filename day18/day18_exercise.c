/*
 * Day 18 · 字符串综合：字符分类统计 · ⭐⭐
 * 用 fgets 读一行，ctype.h 判断字符类型
 */
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[105];
    int upper = 0, lower = 0, digit = 0, space = 0, other = 0;

    fgets(s, sizeof(s), stdin);            /* 读一整行，含空格 */

    /* fgets 会把末尾的回车 \n 也读进来，统计前把它抹掉 */
    int len = 0;
    while (s[len] != '\0') len++;
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i]))
            upper++;
        else if (islower(s[i]))
            lower++;
        else if (isdigit(s[i]))
            digit++;
        else if (isspace(s[i]))
            space++;
        else
            other++;
    }

    printf("%d %d %d %d %d\n", upper, lower, digit, space, other);
    return 0;
}

/*
 * ========== 测试用例 ==========
 *
 * 用例 1（常规混合）:
 * 输入:
Hello World 123!
 * 输出:
2 8 3 2 1
 *
 * 用例 2（只有字母和数字）:
 * 输入:
abcABC789
 * 输出:
3 3 3 0 0
 *
 * 用例 3（只有空格）:
 * 输入:
   
 * 输出:
0 0 0 3 0
 *
 * 用例 4（只有其他字符）:
 * 输入:
!!!@#
 * 输出:
0 0 0 0 5
 *
 * 用例 5（空行，直接回车）:
 * 输入:

 * 输出:
0 0 0 0 0
 *
 * ========== 关键点 ==========
 * 1. fgets 能读空格，但会把行尾 \n 一起收进来，统计前通常要换成 \0
 * 2. ctype.h 的 isupper / islower / isdigit / isspace 返回值：是真返回非 0，假返回 0
 * 3. 用 if-else if 链实现「每个字符只进一个桶」，避免重复计数
 *
 * ========== 易错点 ==========
 * - 忘了去 \n：空行或末尾会多算 1 个空格
 * - 把 isspace 写成 s[i]==' '：漏掉制表符、换行等空白
 * - 数组开太小：fgets 第二个参数是最大容量，实际最多读 size-1 个字符 + \0
 * - 多个 if 不用 else if：一个字符可能同时满足 isupper 和 isalpha，会重复计数
 *
 * ========== 拓展问题 ==========
 * 如果要把连续数字当成一个「整数」来统计个数（例如 "Hello123World456" 算 2 个数字），
 * 该怎么改？提示：用一个 flag 标记「当前是否正在数字段里」，遇到非数字就把 flag 清零。
 */
