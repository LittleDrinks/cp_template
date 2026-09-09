struct Line {
    ll k, b;
    int id;
    Line(ll k=0, ll b=0, int id=0): k(k), b(b), id(id) {}
    ll y(ll x) const { return k*x+b; }
};
bool LineLess(const Line &a, const Line &b, ll x) {
    auto y1=a.y(x);
    auto y2=b.y(x);
    return make_pair(y1, a.id) < make_pair(y2, b.id);
}
#define m ((l+r)>>1)
template<auto better>
struct LiChao {
    struct node { int lson=0, rson=0, id=0; };
    vector<node> a;
    vector<Line> f;
    int root=0;
    ll L, R;

    LiChao(ll L, ll R, int cap = 1): L(L), R(R), a(1), f(1) {
        f.reserve(cap);
        a.reserve(cap*20);
    }
    int newNode() {
        a.push_back({});
        return a.size()-1;
    }
    int insert(int p, ll l, ll r, int id) {
        if (!p) p = newNode();
        if (!a[p].id) { a[p].id=id; return p; }

        bool bl = better(f[id], f[a[p].id], l);
        bool br = better(f[id], f[a[p].id], r-1);
        if (bl && br) {
            a[p].id = id; return p;
        }
        if (!bl && !br) {
            return p;
        }
        if (better(f[id], f[a[p].id], m)){
            swap(id, a[p].id);
        }
        if (better(f[id], f[a[p].id], l)) {
            a[p].lson = insert(a[p].lson, l, m, id);
        } else {
            a[p].rson = insert(a[p].rson, m, r, id);
        }
        return p;
    }
    int update(int p, ll l, ll r, ll x, ll y, int id) {
        if (x <= l && r <= y) return insert(p, l, r, id);
        if (!p) p = newNode();

        if (x < m) a[p].lson = update(a[p].lson, l, m, x, y, id);
        if (m < y) a[p].rson = update(a[p].rson, m, r, x, y, id);
        return p;
    }
    int query(int p, ll l, ll r, ll x) const {
        if (x+1 <= l || r <= x) return 0;
        if (!p) return 0;
        int res = a[p].id;
        if (l == r-1) return res;
        int q = (x < m ? query(a[p].lson, l, m, x): query(a[p].rson, m, r, x));
        if (q && (!res || better(f[q], f[res], x))) {
            res = q;
        }
        return res;
    }
    void add(Line g, ll x, ll y) {
        f.push_back(g);
        root = update(root, L, R, x, y, f.size()-1);
    }
    void add(Line g) { add(g, L, R); }
    pair<bool, Line> query(ll x) const {
        int p = query(root, L, R, x);
        return {p>0, p?f[p]:Line{}};
    }
};
#undef m
