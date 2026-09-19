# 手机上学 C：环境搭建指南

本指南帮你在一部 **Android 手机**上，从零搭好 C 语言的「写代码 + 编译运行」完整环境。

跟着做，大约 10 分钟。

---

## 一、你需要什么

| 项目 | 要求 |
|---|---|
| 手机 | Android 7.0 或更高 |
| 存储 | 约 200 MB 空闲（编译器工具链） |
| 网络 | 第一次需要联网下载工具链 |
| 两个 App | **Acode**（写代码）+ **Termux**（编译） |

> **为什么是两个 App？**
> 手机上没有一个"全能 C IDE"，但把「写」和「跑」分开，反而更清爽：
> **Acode** 负责好看的编辑体验，**Termux** 负责真正的 gcc/clang。

---

## 二、安装 Acode（负责写代码）

### 从哪装（三选一）

1. **F-Droid**（推荐，开源商店）
   `https://f-droid.org/packages/com.foxdebug.acode/`
2. **GitHub Releases**
   `https://github.com/Acode-Foundation/Acode/releases`
3. **Google Play**：搜索 `Acode`

### 装完简单设置

打开 Acode → 左上角 **☰** → **设置**：

- **字体大小**：调到顺手
- **自动补全**（Editor → Auto completion）：三个开关全部打开
  - Live auto completion
  - Local word completion
  - Language completion

（可选）想要更多代码片段，可以装 **Acode Snippets** 插件。

---

## 三、安装 Termux（负责编译）

> ⚠️ **重要：不要从 Google Play 装！**
> 商店里那个版本 2019 年就废弃了，装不了软件包。

正确来源（二选一）：

1. **F-Droid**（推荐）：`https://f-droid.org/packages/com.termux/`
2. **GitHub Releases**：`https://github.com/termux/termux-app/releases`
   选 `universal` 或 `arm64-v8a` 的 APK

---

## 四、装编译器（两条命令）

打开 **Termux**，输入：

```bash
pkg update && pkg upgrade -y
```

> 如果一直卡在 `Downloading` 或超时（国内网络常见），先换镜像源：
> ```bash
> termux-change-repo
> ```
> 用方向键选择，空格勾选，回车确认 → 选一个国内镜像（清华 / 中科大 / 阿里）

然后安装 clang：

```bash
pkg install clang -y
```

验证：

```bash
clang --version
```

**出来版本号（Clang 17.x 之类）就成功了 ✅**

> **clang 还是 gcc？**
> Termux 上推荐 **clang**（LLVM 官方移植，维护更及时）。它同时支持 C 和 C++，
> 编译命令和 gcc 基本一样。想用 gcc 也行：`pkg install gcc`。

---

## 五、跑通第一个程序 🎉

### 1. 建文件

```bash
mkdir -p ~/code && cd ~/code
nano hello.c
```

粘贴：

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, 手机写 C!\n");
    return 0;
}
```

nano 保存：`Ctrl + O` → 回车 → `Ctrl + X` 退出

### 2. 编译

```bash
clang hello.c -o hello
```

### 3. 运行

```bash
./hello
```

看到 `Hello, 手机写 C!` —— **恭喜，你的手机现在是一台 C 开发机了** 🎉

---

## 六、Acode + Termux 配合（日常写法）

推荐工作流：

1. **Acode 里写代码**，保存到 `/sdcard/code/hello.c`（外部存储，Acode 能直接访问）
2. **切到 Termux**，进入同一目录编译运行：

```bash
cd /sdcard/code
clang hello.c -o hello && ./hello
```

3. 报错了 → 切回 Acode 改 → 再跑

> **小技巧**：Termux 里按 **↑** 能调出上一条命令，不用重复敲。

---

## 七、常见问题（FAQ）

**Q1. `pkg update` 一直超时 / 失败？**
国内访问 Termux 官方源不稳。解决：`termux-change-repo` 换清华 / 中科大 / 阿里镜像。

**Q2. 手机上找不到 Tab 键，怎么缩进？**
- C 语言**不在乎缩进**（不像 Python），用空格完全没问题
- Acode 会自动保持上一行的缩进
- 想要真的 Tab 键：装 **Unexpected Keyboard**（开源，带 Tab / Ctrl / Esc / 方向键）

**Q3. `clang: command not found`？**
没装成功。重新 `pkg install clang`，注意看有没有报错信息。

**Q4. 运行提示 `Permission denied`？**
`./hello` 前面的 `./` 不能少。还不行就 `chmod +x hello`。

**Q5. 中文输出乱码？**
Termux 默认 UTF-8，一般没问题。Acode 保存时确保编码是 **UTF-8**。

**Q6. 手机内存不够？**
GCC/Clang 工具链约 150–200 MB，装在 App 内部存储里。装完可以删掉不再需要的包。

---

## 八、下一步

环境好了 → 翻开 **[教程正文](../docs/1.01-intro.md)**，从 `1.01` 开始读。

每一章的示例，建议自己在 `code/` 目录里敲一遍 —— **敲比看有用十倍**。

配套示例见 **[`examples/`](../examples/)**。

---

*本指南是「手机学 C」项目的一部分。踩到新坑？欢迎提 Issue 补充。*
