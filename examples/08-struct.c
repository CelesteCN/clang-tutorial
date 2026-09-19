/* ============================================================
 * 08 - 结构体
 * 对应章节：docs/2.06-struct.md
 *
 * 编译：clang 08-struct.c -o 08-struct
 * 运行：./08-struct
 * ============================================================ */

#include <stdio.h>
#include <string.h>

/* ---------- 定义结构体 ---------- */
struct Student {
    char   name[32];
    int    age;
    double score;
};

/* 参数用指针，避免复制整个结构体；const 表示不修改它 */
void print_student(const struct Student *s)
{
    /* 指针访问成员用 -> */
    printf("  %-8s %d 岁  %.1f 分\n", s->name, s->age, s->score);
}

int main(void)
{
    int i;

    /* ---------- 初始化方式一：花括号 ---------- */
    struct Student a = {"小明", 18, 92.5};

    /* ---------- 初始化方式二：逐个赋值 ---------- */
    struct Student b;
    strcpy(b.name, "小红");     /* 字符数组不能用 = 直接赋值，要用 strcpy */
    b.age   = 19;
    b.score = 88.0;

    printf("学生列表:\n");
    print_student(&a);
    print_student(&b);

    /* ---------- 修改成员 ---------- */
    a.score = 95.0;
    printf("\n改了 a 的分数后:\n");
    print_student(&a);

    /* ---------- 结构体数组 ---------- */
    struct Student class[] = {
        {"张三", 20, 76.5},
        {"李四", 21, 88.5}
    };
    int count = (int)(sizeof(class) / sizeof(class[0]));

    printf("\n班级（%d 人）:\n", count);
    for (i = 0; i < count; i++) {
        print_student(&class[i]);
    }

    /* ---------- 用 typedef 起别名（写法更短） ---------- */
    typedef struct Student Stu;
    Stu x = {"王五", 22, 90.0};
    printf("\ntypedef 别名写法:\n");
    print_student(&x);

    return 0;
}