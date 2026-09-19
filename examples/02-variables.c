/* ============================================================
 * 02 - 变量与数据类型
 * 对应章节：docs/1.04-variable.md
 *
 * 编译：clang 02-variables.c -o 02-variables
 * 运行：./02-variables
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    int    age      = 18;      /* 整数 */
    double height   = 1.75;    /* 小数（双精度） */
    char   grade    = 'A';     /* 单个字符，用单引号 */
    char   name[]   = "小明";  /* 字符串，用双引号 */

    /* 格式符：%d 整数、%f 小数、%c 字符、%s 字符串 */
    printf("姓名: %s\n", name);
    printf("年龄: %d\n", age);
    printf("身高: %.2f\n", height);   /* .2 表示保留两位小数 */
    printf("等级: %c\n", grade);

    /* 类型大小：不同平台可能略有差异 */
    printf("\nsizeof(int)    = %d 字节\n", (int)sizeof(int));
    printf("sizeof(double) = %d 字节\n", (int)sizeof(double));
    printf("sizeof(char)   = %d 字节\n", (int)sizeof(char));

    return 0;
}