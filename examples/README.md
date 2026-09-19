# 示例代码

这里是可以**直接编译运行**的 C 示例，按教程章节顺序排列。

## 怎么用

### 在手机上（推荐）

1. 把本目录的文件复制到手机的 `/sdcard/code/`
2. 打开 **Termux**：

```bash
cd /sdcard/code
clang 01-hello.c -o 01-hello
./01-hello
```

或者一次把当前目录所有示例都跑一遍：

```bash
cd /sdcard/code
for f in *.c; do
    out="${f%.c}"
    echo "=== $f ==="
    clang "$f" -o "$out" && "./$out"
done
```

### 在电脑上

```bash
clang 01-hello.c -o 01-hello && ./01-hello
```

## 清单

| 文件 | 内容 | 对应章节 |
|---|---|---|
| `01-hello.c` | 最小程序 | 1.01 |
| `02-variables.c` | 变量与数据类型 | 1.04 |
| `03-flow.c` | if / for / while | 1.07 |
| `04-io.c` | printf / scanf | 1.08 |
| `05-array.c` | 数组与二维数组 | 2.02 |
| `06-pointer.c` | 指针与传址 | 2.01 |
| `07-string.c` | 字符串与常用函数 | 2.03 |
| `08-struct.c` | 结构体 | 2.06 |

## 建议

1. **先自己敲一遍**，再看示例 —— 手比眼记得牢
2. 改一改参数，看看输出怎么变
3. 报错了别怕，编译器会告诉你第几行、缺了什么

## 更多示例

想要更多（小游戏、算法、图形化），推荐这个 **MIT 协议**的开源仓库：

- [`qaiu/c4droid-code`](https://github.com/qaiu/c4droid-code) —— C4droid 代码实例（含算法、小游戏）

> ⚠️ 引用他人代码时请遵守其许可证（保留版权声明）。

---

*本目录为「手机学 C」项目的一部分。*
