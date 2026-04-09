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
  typst compile main.typ main.pdf --font-path ~/.fontist/fonts
  ```

- 若中文显示为方块（乱码），请先安装 CJK 字体（例如 `Noto Serif CJK SC` / `Noto Sans CJK SC` / `Noto Sans Mono CJK SC`），再重新编译。
