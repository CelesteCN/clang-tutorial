/* ============================================================
 * 04 - 输入与输出：printf / scanf
 * 对应章节：docs/1.08-io.md
 *
 * 编译：clang 04-io.c -o 04-io
 * 运行：./04-io
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    int a, b;

    printf("请输入两个整数（用空格分开）: ");

    /* 注意：scanf 里取变量的"地址"，所以前面要加 &    */
    /* 但是数组名本身已经是地址，不需要加 &            */
    if (scanf("%d %d", &a, &b) != 2) {
        printf("输入格式不对，应该是两个整数\n");
        return 1;
    }

    printf("\n%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);

    if (b != 0) {
        printf("%d / %d = %.2f\n", a, b, (double)a / b);  /* 转成小数再除 */
    } else {
        printf("除数不能为 0\n");
    }

    return 0;
}