/* ============================================================
 * 07 - 字符串
 * 对应章节：docs/2.03-string.md
 *
 * 编译：clang 07-string.c -o 07-string
 * 运行：./07-string
 * ============================================================ */

#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;

    /* 字符串 = 以 '\0' 结尾的 char 数组 */
    char name[32] = "小明";
    char hello[]  = "Hello";

    printf("name = %s，长度 = %d\n", name, (int)strlen(name));

    /* ---------- 拼接 ---------- */
    strcat(hello, ", C!");
    printf("拼接后: %s（长度 %d）\n", hello, (int)strlen(hello));

    /* ---------- 比较：返回 0 表示相等 ---------- */
    if (strcmp(name, "小明") == 0) {
        printf("名字正确\n");
    } else {
        printf("名字不对\n");
    }

    /* ---------- 逐字符遍历 ---------- */
    printf("逐字符: ");
    for (i = 0; name[i] != '\0'; i++) {
        printf("[%c]", name[i]);
    }
    printf("\n");

    /* ---------- 安全读取一行（推荐 fgets） ---------- */
    char line[64];
    printf("\n随便输入一句话: ");
    if (fgets(line, sizeof(line), stdin)) {
        /* fgets 会把换行也读进来，这里去掉它 */
        line[strcspn(line, "\n")] = '\0';
        printf("你输入了: %s（长度 %d）\n", line, (int)strlen(line));
    }

    return 0;
}