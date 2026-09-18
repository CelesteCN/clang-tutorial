# C 语言教程

> 本仓库 fork 自 [wangdoc/clang-tutorial](https://github.com/wangdoc/clang-tutorial)（原作者：阮一峰）。
> 教程原文版权归原作者所有。原仓库未附 LICENSE 文件，授权声明以原项目及其发布站点（wangdoc.com）为准；使用请遵守原授权。

## 本仓库做了什么

在保留原文内容的前提下（仅修正 1 处失效引用），做了以下整理：

1. **重排学习顺序**，让它符合"先修课"逻辑：
   - **指针**提前到数组、字符串、结构体之前 —— 这些章节大量使用指针语法（`int* p`、`char* s`、`->`），先把指针学了才读得懂；
   - **动态内存（malloc / free）** 提前到结构体之前 —— 结构体的链表示例需要它；
   - **I/O（printf / scanf）** 提前到基础篇第 1.8 节（原教程排在倒数第 6 位，太晚）；
   - **流程控制** 放在 I/O 之前 —— I/O 章节的示例里用了循环。
2. **文件名规范化**：全部文档加编号前缀（与学习顺序一致），并去掉文件名中的空格。
3. **恢复标准库附录**：补回原仓库 `docs/lib/` 下的 C 标准库参考（20 篇）。
4. **修正交叉引用**：修正因顺序调整而失效的章节引用（1 处）。
5. 移除原仓库的网站构建配置，仅保留教程文档。

## 目录

### 一、基础篇
- [1.01 C 语言简介、编译环境](docs/1.01-intro.md)
- [1.02 基础语法](docs/1.02-syntax.md)
- [1.03 基础数据类型](docs/1.03-types.md)
- [1.04 变量与常量](docs/1.04-variable.md)
- [1.05 运算符](docs/1.05-operator.md)
- [1.06 变量说明符](docs/1.06-specifier.md)
- [1.07 流程控制（if / for / while / switch）](docs/1.07-flow-control.md)
- [1.08 输入输出（printf / scanf）](docs/1.08-io.md)
- [1.09 自定义函数](docs/1.09-function.md)
- [1.10 预处理（#define / #include）](docs/1.10-preprocessor.md)

### 二、指针与复合数据
- [2.01 指针](docs/2.01-pointer.md)
- [2.02 数组](docs/2.02-array.md)
- [2.03 字符串](docs/2.03-string.md)
- [2.04 枚举 enum](docs/2.04-enum.md)
- [2.05 内存管理 malloc / free](docs/2.05-memory.md)
- [2.06 结构体 struct](docs/2.06-struct.md)
- [2.07 typedef 类型别名](docs/2.07-typedef.md)
- [2.08 共用体 union](docs/2.08-union.md)

### 三、进阶
- [3.01 多文件编译、头文件](docs/3.01-multifile.md)
- [3.02 文件读写](docs/3.02-file.md)
- [3.03 命令行参数](docs/3.03-cli.md)
- [3.04 多字节字符](docs/3.04-multibyte.md)

### 附录：C 标准库参考
- [assert.h](docs/lib/assert.h.md)
- [ctype.h](docs/lib/ctype.h.md)
- [errno.h](docs/lib/errno.h.md)
- [float.h](docs/lib/float.h.md)
- [inttypes.h](docs/lib/inttypes.h.md)
- [iso646.h](docs/lib/iso646.h.md)
- [limits.h](docs/lib/limits.h.md)
- [locale.h](docs/lib/locale.h.md)
- [math.h](docs/lib/math.h.md)
- [signal.h](docs/lib/signal.h.md)
- [stdarg.h](docs/lib/stdarg.h.md)
- [stdbool.h](docs/lib/stdbool.h.md)
- [stddef.h](docs/lib/stddef.h.md)
- [stdint.h](docs/lib/stdint.h.md)
- [stdio.h](docs/lib/stdio.h.md)
- [stdlib.h](docs/lib/stdlib.h.md)
- [string.h](docs/lib/string.h.md)
- [time.h](docs/lib/time.h.md)
- [wchar.h](docs/lib/wchar.h.md)
- [wctype.h](docs/lib/wctype.h.md)

## 学习建议

- 按编号顺序读；每章示例代码建议亲手敲一遍（手机端可用 Acode 等编辑器 + 编译环境）。
- 指针（2.1）与内存管理（2.5）是 C 语言的分水岭，建议多花时间。
- 附录的标准库参考不必通读，用到时查阅即可。
