#import "template.typ": *

#show: template.with(
  title: "算法模板",
  team: "LittleDrinks",
  school: "Shanghai University",
  authors: ("Shijie Chen",),
  logo: "头像.jpg",
  header: [
    _Shijie Chen \@ Shanghai University_#h(1fr)#context counter(page).display("1 / 1", both: true)
  ],
  preview: sys.inputs.at("x-preview", default: none) != none,
  commit: sys.inputs.at("x-git-commit", default: none),
)

#block(height: 68em, columns(2, outline(depth: 2, indent: 1em)))

= 赛前准备
== template
#import_code("src/pre/template.cpp")
== run.py
#import_code("src/pre/run.py")
== 土质 cph
#import_code("src/pre/土质cph.py")
== 随机数
#import_code("src/pre/随机数.cpp")
== 对拍
#import_code("src/pre/check.py")


= 杂项
== 模数类
#import_code("src/pre/模数类.cpp")
== i128 流重载
#import_code("src/misc/__int128流重载.cpp")
== 运行时间
#import_code("src/misc/运行时间.cpp")
== 火车头
#import_code("src/misc/火车头.cpp")
== 二进制相关库函数
#import_code("src/misc/二进制相关库函数.cpp")
== 子集枚举
#import_code("src/misc/子集枚举.cpp")
== 整数域三分
#import_code("src/misc/整数域三分.cpp")

= 计算几何
== 向量
#import_code("src/geometry/向量.cpp")
== 极角排序
#import_code("src/geometry/极角排序.cpp")
== 点线操作
#import_code("src/geometry/点线操作.cpp")
== 多边形
#import_code("src/geometry/多边形.cpp")
== 凸包
#import_code("src/geometry/凸包.cpp")
=== 旋转卡壳
#import_code("src/geometry/旋转卡壳.cpp")
=== 闵可夫斯基和
#import_code("src/geometry/闵可夫斯基和.cpp")
== 三维向量
#import_code("src/geometry/三维向量.cpp")

= 数据结构
== 对顶multiset
#import_code("src/data_structure/对顶multiset.cpp")
== 带权并查集
#import_code("src/data_structure/带权并查集.cpp")
== Trie
#import_code("src/data_structure/Trie.cpp")
=== 可持久化Trie
#import_code("src/data_structure/可持久化Trie.cpp")
== ST表
#import_code("src/data_structure/ST表.cpp")
== 树状数组
#import_code("src/data_structure/树状数组.cpp")
== 线段树
=== 懒标记线段树
#import_code("src/data_structure/懒标记线段树.cpp")
=== 可持久化线段树
#import_code("src/data_structure/可持久化线段树.cpp")
=== 吉司机线段树
#import_code("src/data_structure/吉司机线段树.cpp")
== 笛卡尔树
#import_code("src/data_structure/笛卡尔树.cpp")
== 珂朵莉树
#import_code("src/data_structure/珂朵莉树.cpp")
== 分块
#import_code("src/data_structure/分块.cpp")
== 手写bitset
#import_code("src/data_structure/手写bitset.cpp")
== 莫队
#import_code("src/data_structure/莫队.cpp")
== LCT
#import_code("src/data_structure/LCT.cpp")

= 图论
== bitset优化传递闭包
#import_code("src/graph/bitset优化传递闭包.cpp")
== 有向图上找最小环
#import_code("src/graph/有向图上找最小环.cpp")
== spfa判断负环
#import_code("src/graph/spfa判断负环.cpp")
== 最小生成树
#import_code("src/graph/最小生成树.cpp")
== 拓扑排序
#import_code("src/graph/拓扑排序.cpp")
== LCA
=== 倍增O(LogN)求LCA
#import_code("src/graph/倍增O(LogN)求LCA.cpp")
=== 欧拉序+ST表O(1)求LCA
#import_code("src/graph/欧拉序+ST表O(1)求LCA.cpp")
== 树的直径与中心
#import_code("src/graph/树的直径与中心.cpp")
== 点分治与树的重心
#import_code("src/graph/点分治与树的重心.cpp")
== 树链剖分
#import_code("src/graph/树链剖分.cpp")
== DSU on tree
#import_code("src/graph/DSU on tree.cpp")
== 树哈希
#import_code("src/graph/树哈希.cpp")
== 基环树
#import_code("src/graph/基环树.cpp")
== Hierholzer求欧拉路
#import_code("src/graph/Hierholzer求欧拉路.cpp")
== 强连通分量（SCC）
#import_code("src/graph/强连通分量（SCC）.cpp")
== 割边与边双连通分量（EBCC）
#import_code("src/graph/割边与边双连通分量（EBCC）.cpp")
== 割点与点双连通分量（PBCC）
#import_code("src/graph/割点与点双连通分量（PBCC）.cpp")
== 二分图最大匹配
#import_code("src/graph/二分图最大匹配.cpp")
== 最大流
#import_code("src/graph/最大流.cpp")

= 数学
== 常用公式速查
#include "src/math/常用公式速查.typ"
== 卡特兰数
#import_code("src/math/卡特兰数.cpp")
== 因数
#import_code("src/math/因数.cpp")
== O(1)gcd
#import_code("src/math/O(1)gcd.cpp")
== 质因数分解
#import_code("src/math/质因数分解.cpp")
== 线性筛
#import_code("src/math/线性筛.cpp")
== 欧拉函数
#import_code("src/math/欧拉函数.cpp")
== Min_25筛
#import_code("src/math/Min_25筛.cpp")
== 数论分块
#import_code("src/math/数论分块.cpp")
== 扩展欧几里得算法
#import_code("src/math/扩展欧几里得算法.cpp")
== 中国剩余定理
#import_code("src/math/中国剩余定理.cpp")
== 扩展中国剩余定理
#import_code("src/math/扩展中国剩余定理.cpp")
== 排列组合数
#import_code("src/math/排列组合数.cpp")
== Lucas
#import_code("src/math/Lucas.cpp")
== 高斯消元
#import_code("src/math/高斯消元.cpp")
== 线性基
#import_code("src/math/线性基.cpp")
== 矩阵快速幂
#import_code("src/math/矩阵快速幂.cpp")
== 自适应辛普森法
#import_code("src/math/自适应辛普森法.cpp")
== 阶和原根
#import_code("src/math/阶和原根.cpp")
== 离散对数
#import_code("src/math/离散对数.cpp")
== 多项式暴力乘除
#import_code("src/math/暴力乘除.cpp")
== FFT
#import_code("src/math/FFT.cpp")
== NTT
#import_code("src/math/NTT.cpp")

= 字符串
== 前缀函数与KMP
#import_code("src/string/前缀函数与KMP.cpp")
== 扩展KMP
#import_code("src/string/扩展KMP.cpp")
== Manacher
#import_code("src/string/Manacher.cpp")
== 字符串哈希
#import_code("src/string/字符串哈希.cpp")
== AC自动机
#import_code("src/string/AC自动机.cpp")
== 后缀自动机SAM
#import_code("src/string/后缀自动机SAM.cpp")

= DP
== 数位 DP
#import_code("src/dp/数位DP.cpp")
== 单调队列优化
#import_code("src/dp/单调队列优化.cpp")
== SOSDP
#import_code("src/dp/SOSDP.cpp")

= 烂掉啦
#include "src/fuck/fuck.typ"
