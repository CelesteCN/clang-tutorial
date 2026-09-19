/* ============================================================
 * 06 - 指针（C 语言的分水岭）
 * 对应章节：docs/2.01-pointer.md
 *
 * 编译：clang 06-pointer.c -o 06-pointer
 * 运行：./06-pointer
 * ============================================================ */

#include <stdio.h>

/* 交换两个数 —— 必须用指针，才能改到函数外面的变量 */
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void)
{
    int  n = 42;
    int *p = &n;            /* p 存的是 n 的地址 */

    printf("n 的值   = %d\n", n);
    printf("n 的地址 = %p\n", (void *)&n);
    printf("p 指向的值 = %d\n", *p);        /* *p 是"解引用" */

    *p = 100;               /* 通过指针改 n */
    printf("改完后 n = %d\n", n);

    /* ---------- 传址调用 ---------- */
    int a = 1, b = 2;
    printf("\n交换前: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("交换后: a=%d, b=%d\n", a, b);

    /* ---------- 用指针遍历数组 ---------- */
    int arr[4] = {10, 20, 30, 40};
    int *q = arr;           /* 数组名就是首元素地址，等价于 &arr[0] */
    int i;

    printf("\n用指针遍历数组: ");
    for (i = 0; i < 4; i++) {
        printf("%d ", *(q + i));
    }
    printf("\n");

    /* ---------- 指针的运算 ---------- */
    printf("\n*q     = %d\n", *q);
    printf("*(q+1) = %d\n", *(q + 1));
    printf("q 移动前后差 %d 字节\n", (int)(sizeof(int)));

    return 0;
}