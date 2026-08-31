struct HLD {
    int n, cur=0;
    vector<int> siz, top, dep, parent, in, out, seq;
    vector<vector<int>> G;

    HLD(int n): 
        n(n), siz(n+1, 1), top(n+1), dep(n+1),
        parent(n+1), in(n+1), out(n+1), seq(n+1),
        G(n+1) {}
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void work(int rt) {
        top[rt] = rt;
        dep[rt] = 0;
        dfs1(rt);
        dfs2(rt);
    }
    void dfs1(int u) {
        if (parent[u]) {
            auto it = find(G[u].begin(), G[u].end(), parent[u]);
            G[u].erase(it);
        }
        for (auto &v: G[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[G[u][0]]) {
                swap(G[u][0], v);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v: G[u]) {
            top[v] = (v==G[u][0] ? top[u]: v);
            dfs2(v);
        }
        out[u] = cur;
    }
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    int jump(int u, int k) {
        if (dep[u] < k) {
            return 0;
        }
        int d = dep[u] - k;
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        return seq[in[u]-dep[u]+d];
    }
    int path(int u, int v, auto &&F) {
        // F = [&](int l, int r, bool rev)
        vector<pair<int,int>> R;
        while (top[u] != top[v]) {
            if (dep[top[u]] >= dep[top[v]]) {
                F(in[top[u]], in[u]+1, true);
                u = parent[top[u]];
            } else {
                R.push_back({in[top[v]], in[v]+1});
                v = parent[top[v]];
            }
        }
        int lca;
        if (dep[u] >= dep[v]) {
            lca = v;
            F(in[v], in[u]+1, true);
        } else {
            lca = v;
            R.emplace_back(in[u], in[v]+1);
        }
        reverse(R.begin(), R.end());
        for (auto [l, r]: R) {
            F(l, r, false);
        }
        return lca;
    }
    int lca(int u, int v) {
        return path(u, v, [](...){});
    }
    void rootedSubtree(int rt, int u, auto &&F) {
        if (rt == u) {
            F(0, n);
            return;
        }
        if (!isAncester(u, rt)) {
            F(in[u], out[u]);
            return;
        }
        int v = jump(rt, dep[rt]-dep[u]-1);
        if (in[v]) {
            F(0, in[v]);
        }
        if (out[v] < n) {
            F(out[v], n);
        }
    }
};
