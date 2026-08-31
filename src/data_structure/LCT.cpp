const int N = 2e5 + 5;

struct LCT {
    int son[N][2], fa[N], rev[N], siz[N];

    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            son[i][0] = son[i][1] = fa[i] = rev[i] = 0;
            siz[i] = 1;
        }
        siz[0] = 0;
    }

    void reverse(int u) {
        if (u) {
            swap(son[u][0], son[u][1]);
            rev[u] ^= 1;

            // ===== 有方向信息时在这里魔改 =====
        }
    }

    void push(int u) {
        if (rev[u]) {
            reverse(son[u][0]);
            reverse(son[u][1]);
            rev[u] = 0;
        }
    }

    void pull(int u) {
        siz[u] = siz[son[u][0]] + 1 + siz[son[u][1]];

        // ===== 路径信息主要在这里魔改 =====
    }

    bool isroot(int u) {
        return !fa[u] ||
            (son[fa[u]][0] != u && son[fa[u]][1] != u);
    }

    int pos(int u) {
        return son[fa[u]][1] == u;
    }

    void pushAll(int u) {
        if (!isroot(u)) {
            pushAll(fa[u]);
        }
        push(u);
    }

    void rotate(int u) {
        int p = fa[u];
        int x = !pos(u);

        son[p][!x] = son[u][x];

        if (son[u][x]) {
            fa[son[u][x]] = p;
        }

        fa[u] = fa[p];

        if (!isroot(p)) {
            son[fa[p]][pos(p)] = u;
        }

        son[u][x] = p;
        fa[p] = u;

        pull(p);
    }

    void splay(int u) {
        pushAll(u);

        while (!isroot(u)) {
            if (!isroot(fa[u])) {
                if (pos(u) == pos(fa[u])) {
                    rotate(fa[u]);
                } else {
                    rotate(u);
                }
            }

            rotate(u);
        }

        pull(u);
    }

    void access(int u) {
        for (int x = u, y = 0; x; y = x, x = fa[x]) {
            splay(x);

            // ===== 维护虚子树时在这里魔改 =====

            son[x][1] = y;
            pull(x);
        }

        splay(u);
    }

    void makeroot(int u) {
        access(u);
        reverse(u);
    }

    int findroot(int u) {
        access(u);

        while (1) {
            push(u);

            if (!son[u][0]) {
                break;
            }

            u = son[u][0];
        }

        splay(u);
        return u;
    }

    bool connected(int u, int v) {
        return findroot(u) == findroot(v);
    }

    void link(int u, int v) {
        makeroot(u);

        if (findroot(v) != u) {
            fa[u] = v;
        }
    }

    // split(u, v) 后：
    // v 所在 Splay 的中序就是 u -> v 路径
    // 并且 v 是这棵辅助 Splay 的根
    void split(int u, int v) {
        makeroot(u);
        access(v);
    }

    void cut(int u, int v) {
        split(u, v);

        // 保证 u-v 真的是原树中的直接边才删除
        if (son[v][0] == u && son[u][1] == 0) {
            son[v][0] = fa[u] = 0;
            pull(v);
        }
    }

    // 仅在 u,v 连通时调用
    int dist(int u, int v) {
        split(u, v);
        return siz[v] - 1;
    }

    // 必须在正式 init(n) 之前调用
    // 只检查纯 LCT 骨架，不检查任何题目魔改信息
    void self_test() {
        static const ll STC = 998244353;

        init(8);

        link(1, 2);
        link(2, 3);
        link(2, 4);
        link(4, 5);
        link(5, 6);
        link(3, 7);
        link(7, 8);

        ll tmp = 0;

        auto H = [&](ll x) {
            tmp = (tmp * 131 + x) % STC;
        };

        H(dist(1, 6));
        H(dist(8, 6));
        H(connected(1, 8));

        link(1, 8);           // 已连通，不应改变
        H(dist(1, 8));

        cut(1, 3);            // 不是直接边，不应改变
        H(dist(1, 6));
        H(connected(1, 8));

        cut(2, 4);            // 真正删边
        H(connected(1, 6));
        H(connected(4, 6));
        H(dist(4, 6));

        link(6, 8);           // 换一种方式接回来
        H(dist(1, 5));

        cut(6, 8);
        H(connected(1, 5));

        link(4, 3);
        H(dist(1, 6));

        assert("LCT Self Test Failed" && tmp == 589276135);

        cerr << "LCT Self Test Passed.\n";

        init(8);
    }
} lct;