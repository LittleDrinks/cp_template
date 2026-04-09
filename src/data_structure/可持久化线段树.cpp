#define m ((l+r)>>1)
const int N=1e6, M=1e6;
int root[M+5];
struct segmentTree {
    int cnt;
    struct node {
        int lson, rson, s;
    } a[N*40+5];
    void build(int &rt, int l, int r, const vector<int>& val) {
        rt = ++cnt;
        if (l == r - 1) { a[rt].s = val[l]; return; }
        build(a[rt].lson, l, m, val);
        build(a[rt].rson, m, r, val);
    }
    void update(int &rt, int l, int r, int p, int x) {
        a[++cnt] = a[rt]; rt = cnt;
        if (l == r - 1) { a[rt].s = x; return; }
        if (p < m) { update(a[rt].lson, l, m, p, x); }
        else       { update(a[rt].rson, m, r, p, x); }
    }
    int query(int rt, int l, int r, int p) {
        if (l == r - 1) { return a[rt].s; }
        if (p < m) { return query(a[rt].lson, l, m, p); }
        else       { return query(a[rt].rson, m, r, p); }
    }
} t;
#undef m

void solve()
{
	int n, m;
	cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) { cin >> a[i]; }
    t.build(root[0], 0, n+1, a);
    for (int i = 1; i <= m; ++i) {
        int v, op; cin >> v >> op;
        root[i] = root[v];
        if (op == 1) {
            int p, c;
            cin >> p >> c;
            t.update(root[i], 0, n+1, p, c);
        } else {
            int p; cin >> p;
            cout << t.query(root[i], 0, n+1, p) << "\n";
        }
    }
}