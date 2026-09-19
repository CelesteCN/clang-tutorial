# 手机学 C语言（仅供个人学习）

> 用一部 Android 手机，从零学会 C 语言。

本仓库提供三件东西：

1. **一套完整的 C 语言教程**（22 篇正文 + 标准库参考）
2. **手机环境搭建指南**（怎么写、怎么编译、怎么跑）
3. **8 个可直接运行的示例** + 一键配置脚本

---

## ⚡ 快速开始（手机，约 10 分钟）

**第一步** · 搭环境
看 👉 [**手机环境搭建指南**](guides/mobile-setup.md)
装 **Acode**（写代码）+ **Termux**（编译），有现成一键脚本。

**第二步** · 跑通第一个程序

```bash
cd /sdcard/code
clang 01-hello.c -o 01-hello
./01-hello
```

**第三步** · 开始学
翻开 👉 [**1.01 C 语言简介、编译环境**](docs/1.01-intro.md)

---

## 📁 目录结构

```
├── docs/                  教程正文（22 篇）
│   └── lib/               C 标准库参考（20 篇）
├── guides/
│   └── mobile-setup.md    ★ 手机环境搭建指南
├── examples/              ★ 配套示例（8 个，可直接编译运行）
├── scripts/
│   └── setup-termux.sh    ★ Termux 一键配置脚本
├── NOTICE.md              版权与来源说明
└── README.md
```

---

## 📖 教程目录

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
- [assert.h](docs/lib/assert.h.md) · [ctype.h](docs/lib/ctype.h.md) · [errno.h](docs/lib/errno.h.md) · [float.h](docs/lib/float.h.md) · [inttypes.h](docs/lib/inttypes.h.md) · [iso646.h](docs/lib/iso646.h.md) · [limits.h](docs/lib/limits.h.md) · [locale.h](docs/lib/locale.h.md)
- [math.h](docs/lib/math.h.md) · [signal.h](docs/lib/signal.h.md) · [stdarg.h](docs/lib/stdarg.h.md) · [stdbool.h](docs/lib/stdbool.h.md) · [stddef.h](docs/lib/stddef.h.md) · [stdint.h](docs/lib/stdint.h.md) · [stdio.h](docs/lib/stdio.h.md) · [stdlib.h](docs/lib/stdlib.h.md)
- [string.h](docs/lib/string.h.md) · [time.h](docs/lib/time.h.md) · [wchar.h](docs/lib/wchar.h.md) · [wctype.h](docs/lib/wctype.h.md)

---

## 🛠 本仓库做了什么

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
6. **【新增】手机环境搭建指南**（`guides/`）—— 补上"怎么在手机上真的跑起来"
7. **【新增】配套示例**（`examples/`）—— 8 个可直接编译运行的例子
8. **【新增】一键配置脚本**（`scripts/`）—— Termux 里跑一条命令配好环境

---

## 💡 学习建议

- 按编号顺序读；**每章示例亲手敲一遍**，别只看
- `examples/` 里有配套示例，改改参数看看输出怎么变
- 指针（2.01）与内存管理（2.05）是 C 语言的分水岭，建议多花时间、多画图
- 附录的标准库参考不必通读，用到时查阅即可
- **报错不是失败** —— 编译器会精确告诉你第几行、缺什么，被它骂几次就记住了

---

## 📄 版权

详见 [NOTICE.md](NOTICE.md)。

简要说明：
- **教程正文**（`docs/`、`lib/`）来自 [wangdoc/clang-tutorial](https://github.com/wangdoc/clang-tutorial)（阮一峰），版权归原作者所有
- **新增内容**（`guides/`、`examples/`、`scripts/`）为原创，欢迎自由使用

---

*用手机学 C，从这一页开始。*
