# tarjen cp template

[![Build Typst document](https://github.com/tarjen/tarjen_cp_template/actions/workflows/build.yml/badge.svg)](https://github.com/tarjen/tarjen_cp_template/actions/workflows/build.yml)

特此鸣谢cubercsl提供的typst模板

= 第零章

- 安装 `typst`:
  - Linux, macOS, WSL

    ```bash
    curl -fsSL https://typst.community/typst-install/install.sh | sh
    ```
  - Windows

    ```ps1
    irm https://typst.community/typst-install/install.ps1 | iex
    ```

- 安装 VSCode 插件 `tinymist`:
  - 打开 VSCode
  - 搜索 `tinymist` 安装插件

- 编译 PDF:

  ```bash
  typst compile main.typ main.pdf
  ```

- 字体与上游 `wf-trd` 保持相同风格：正文使用 `Libertinus Serif`（Typst 自带）和 `Noto Serif CJK SC`（中文宋体）；代码使用 `DejaVu Sans Mono` 和 `Noto Sans Mono CJK SC`。

- Ubuntu / WSL 安装与 CI 相同的字体并编译：

  ```bash
  sudo apt-get update
  sudo apt-get install --yes --no-install-recommends fonts-dejavu-core fonts-noto-cjk
  typst compile main.typ main.pdf --font-path /usr/share/fonts/opentype/noto
  ```

- 若中文显示为方块，请用 `typst fonts` 检查上述中文字体是否可见；字体安装在其他目录时，用 `--font-path` 指定该目录。不要通过把正文字体换成黑体来修复缺字。
