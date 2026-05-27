=== 常用公式速查

- 连续幂和
  $
    sum_(i=1)^n i^2 = n(n+1)(2n+1)/6
  $
  $
    sum_(i=1)^n i^3 = (n(n+1)/2)^2
  $
  $
    sum_(i=1)^n i (n-i) = n(n-1)(n+1)/6 = binom(n+1, 3)
  $

- 组合数
  $
    binom(n, k) = n!/(k!(n-k)!)
  $
  $
    binom(n, m) = binom(n-1, m) + binom(n-1, m-1)
  $
  $
    sum_(k=r)^n binom(k, r) = binom(n+1, r+1)
  $
  $
    sum_(i=0)^n binom(n, i) = 2^n
  $

- 几何级数
  $
    1/(1-x) = sum_(k=0)^oo x^k
  $
  $
    x/(1-x)^2 = sum_(k=1)^oo k x^k
  $

- 不定方程 $sum_(i=1)^m x_i = n$
  正整数解个数：
  $
    binom(n-1, m-1)
  $
  非负整数解个数：
  $
    binom(n+m-1, m-1)
  $

- 前缀异或和
  令 $S(n)=1 xor 2 xor dots.c xor n$，则
  $
    n mod 4 = 0 => S(n)=n
  $
  $
    n mod 4 = 1 => S(n)=1
  $
  $
    n mod 4 = 2 => S(n)=n+1
  $
  $
    n mod 4 = 3 => S(n)=0
  $

- 多重排列
  $
    n! / product_i (k_i!)
  $

- 错位排列
  $
    D(n) = (n-1) (D(n-1) + D(n-2))
  $

- 网格路径计数：从 $(1,1)$ 到 $(n,m)$
  $
    binom(n+m-2, n-1)
  $

- 切比雪夫距离、曼哈顿距离
  $
    max(a,b) = (a+b)/2 + abs((a-b)/2), a,b >= 0
  $
  $
    max(abs(x-a), abs(y-b)) = abs((x+y)/2 - (a+b)/2) + abs((x-y)/2 - (a-b)/2)
  $
  $
    abs(x-a)+abs(y-b) = max(abs((x+y)-(a+b)), abs((x-y)-(a-b)))
  $

- 弧微分公式
  二维一般形式：
  $
    integral_L "d" s = integral_L sqrt(("d" x)^2 + ("d" y)^2)
  $
  直角坐标：若 $L: y=y(x), a <= x <= b$，则
  $
    L = integral_a^b sqrt(1 + (y'(x))^2) "d" x
  $
  参数方程：若 $L: x=x(t), y=y(t), alpha <= t <= beta$，则
  $
    L = integral_alpha^beta sqrt((x'(t))^2 + (y'(t))^2) "d" t
  $
  极坐标：若 $L: r=r(theta), alpha <= theta <= beta$，则
  $
    L = integral_alpha^beta sqrt((r(theta))^2 + (r'(theta))^2) "d" theta
  $
