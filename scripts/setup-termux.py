#!/data/data/com.termux/files/usr/bin/bash
# ============================================================
#  手机学 C —— Termux 环境一键配置脚本
#  用法：把本文件放到手机里，然后在 Termux 中执行：
#        bash setup-termux.sh
# ============================================================

echo "=========================================="
echo "  手机学 C · Termux 环境一键配置"
echo "=========================================="
echo

# --- 0. 必须在 Termux 里运行 ---
if [ ! -d /data/data/com.termux ]; then
    echo "❌ 请在 Termux App 内运行本脚本"
    exit 1
fi

# --- 1. 网络提示 ---
echo "[1/5] 检查网络..."
if ! ping -c 1 -W 3 www.baidu.com >/dev/null 2>&1; then
    echo "  ⚠️  网络似乎不通，请先联网"
fi
echo "  ✓"

# --- 2. 更新包列表 ---
echo "[2/5] 更新软件包列表（可能较慢，请耐心等）..."
if ! pkg update -y; then
    echo
    echo "  ❌ 更新失败。国内网络建议先换镜像源："
    echo "     termux-change-repo"
    echo "     然后重新运行本脚本。"
    exit 1
fi
echo "  ✓"

# --- 3. 安装 clang ---
echo "[3/5] 安装 clang 编译器..."
if ! pkg install -y clang; then
    echo "  ❌ 安装失败，请检查网络后重试"
    exit 1
fi
echo "  ✓"

# --- 4. 创建工作目录 ---
echo "[4/5] 创建工作目录..."
mkdir -p ~/code 2>/dev/null
mkdir -p /sdcard/code 2>/dev/null
echo "  ✓ ~/code 和 /sdcard/code"

# --- 5. 写入示例程序 ---
echo "[5/5] 写入示例程序 hello.c ..."
cat > ~/code/hello.c << 'EOF'
#include <stdio.h>

int main(void)
{
    printf("Hello, 手机写 C!\n");
    return 0;
}
EOF
cp ~/code/hello.c /sdcard/code/hello.c 2>/dev/null

echo
echo "=========================================="
echo "  ✅ 配置完成！"
echo "=========================================="
echo
echo "编译器版本："
clang --version 2>/dev/null | head -1
echo
echo "跑个测试："
cd ~/code && clang hello.c -o hello && ./hello
echo
echo "------------------------------------------"
echo "以后写代码的流程："
echo "  1) 用 Acode 编辑 /sdcard/code/xxx.c"
echo "  2) 回到 Termux："
echo "     cd /sdcard/code"
echo "     clang xxx.c -o xxx && ./xxx"
echo "------------------------------------------"
