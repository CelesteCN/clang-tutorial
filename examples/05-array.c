/* ============================================================
 * 05 - 数组
 * 对应章节：docs/2.02-array.md
 *
 * 编译：clang 05-array.c -o 05-array
 * 运行：./05-array
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    int i;

    /* ---------- 三种初始化方式 ---------- */
    int a[5] = {10, 20, 30, 40, 50};
    int b[]  = {1, 2, 3};      /* 长度自动推断为 3 */
    int c[4] = {0};            /* 全部初始化为 0 */

    /* ---------- 遍历 ---------- */
    printf("a: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("b: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("c: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    /* ---------- 求和、平均 ---------- */
    int sum = 0;
    for (i = 0; i < 5; i++) {
        sum += a[i];
    }
    printf("\n总和 = %d，平均 = %.1f\n", sum, (double)sum / 5);

    /* ---------- 二维数组 ---------- */
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("\n矩阵:\n");
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    /* ---------- 求数组长度 ---------- */
    printf("\nsizeof(a) = %d 字节（5 个 int）\n", (int)sizeof(a));
    printf("元素个数 = %d\n", (int)(sizeof(a) / sizeof(a[0])));

    return 0;
}