/* 力扣核心代码模式提交版：非零数字拼接 × 数字和
 * 只写 class Solution，不要 main（平台会拼它自己的调用代码）
 * 方法名必须跟平台要求一致：sumAndMultiply
 */
#include <cstdio>       /* C++ 里 sprintf 在这；比 C 的 stdio.h 换了个马甲 */
#include <cstring>

class Solution {
public:
    long long sumAndMultiply(long long n) {
        char buf[32];
        sprintf(buf, "%lld", n);        /* 整数转字符串（g++ 原生支持 %lld，不用 MinGW 宏） */

        long long x = 0, sum = 0;
        for (int i = 0; buf[i] != '\0'; i++) {   /* 遍历到 \0 停 */
            if (buf[i] == '0') continue;          /* 跳过 0，只收非零数字 */
            int d = buf[i] - '0';                 /* 字符变数字 */
            x = x * 10 + d;                       /* 拼接 */
            sum += d;                             /* 数字和 */
        }
        return x * sum;    /* n=0 时 x=0,sum=0，返回 0 正好 */
    }
};
