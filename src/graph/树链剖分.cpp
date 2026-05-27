const int N = 1e5 + 5;
int n, q, root;
int a[N];
int cur, parent[N], siz[N], dep[N], in[N], out[N], top[N], seq[N];
vector<int> G[N];
void dfs1(int u)
{
    if (parent[u]) {
        G[u].erase(find(G[u].begin(), G[u].end(), parent[u]));
    }

    dep[u] = dep[parent[u]] + 1;
    siz[u] = 1;
    for (auto &v: G[u]) {
        parent[v] = u;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[G[u][0]]) {
            swap(G[u][0], v);
        }
    }
}
void dfs2(int u)
{
    in[u] = cur++;
    seq[in[u]] = u;
    for (auto v: G[u]) {
        top[v] = (v == G[u][0] ? top[u] : v);
        dfs2(v);
    }
    out[u] = cur;
}

/*
遍历 u,v 之间的路径，都可以套用板子
*/
void path(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            // 修改 u 到 top[u] 的路径
            u = parent[top[u]];
        } else {
            // 修改 v 到 top[v] 的路径
            v = parent[top[v]];
        }
    }
    u = in[u];
    v = in[v];
    if (u > v) swap(u, v);
    // 修改 u 到 v 的路径
}
void solve() {
    dfs1(root);
    dfs2(root);
    // ...
}