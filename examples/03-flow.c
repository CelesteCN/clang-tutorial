/* ============================================================
 * 03 - 流程控制：if / for / while
 * 对应章节：docs/1.07-flow-control.md
 *
 * 编译：clang 03-flow.c -o 03-flow
 * 运行：./03-flow
 * ============================================================ */

#include <stdio.h>

int main(void)
{
    int i;
    int score = 85;

    /* ---------- if / else ---------- */
    if (score >= 60) {
        printf("分数 %d：及格了\n", score);
    } else {
        printf("分数 %d：没及格\n", score);
    }

    /* ---------- for 循环 ---------- */
    printf("数到 5: ");
    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* ---------- while 循环 ---------- */
    int n = 3;
    printf("倒计时: ");
    while (n > 0) {
        printf("%d ", n);
        n--;
    }
    printf("发射!\n");

    /* ---------- 九九乘法表（嵌套循环） ---------- */
    printf("\n九九乘法表（前 3 行）:\n");
    for (i = 1; i <= 3; i++) {
        int j;
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%-3d", j, i, i * j);  /* %-3d 左对齐占 3 格 */
        }
        printf("\n");
    }

    return 0;
}