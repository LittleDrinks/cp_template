#define m ((l+r)>>1)
#define lson (p << 1)
#define rson (p << 1 | 1)
int sum[N<<2], tag[N<<2];
void pushup(int p, int l, int r) {
    sum[p] = (sum[lson] + sum[rson]) % MOD;
}
void apply(int p, int l, int r, int dt) {
    sum[p] = (sum[p] + 1LL * (r - l) * dt) % MOD;
    tag[p] = (tag[p] + dt) % MOD;
}
void pushdown(int p, int l, int r) {
    apply(lson, l, m, tag[p]);
    apply(rson, m, r, tag[p]);
    tag[p] = 0;
    pushup(p, l, r);
}
void build(int p, int l, int r) {
    if (l == r - 1) {
        sum[p] = a[seq[l]] % MOD;
        return;
    }
    build(lson, l, m);
    build(rson, m, r);
    pushup(p, l, r);
}
void modify(int p, int l, int r, int x, int y, int v) {
    if (r <= x || y <= l) return;
    if (x <= l && r <= y) { apply(p, l, r, v); return; }
    pushdown(p, l, r);
    modify(lson, l, m, x, y, v);
    modify(rson, m, r, x, y, v);
    pushup(p, l, r);
}
int query(int p, int l, int r, int x, int y) {
    if (r <= x || y <= l) return 0;
    if (x <= l && r <= y) return sum[p];
    int res = 0;
    pushdown(p, l, r);
    res = (res + query(lson, l, m, x, y)) % MOD;
    res = (res + query(rson, m, r, x, y)) % MOD;
    pushup(p, l, r);
    return res;
}
#undef m
#undef lson
#undef rson