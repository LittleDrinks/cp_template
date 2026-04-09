vector<int> G[N], cycle;
void dfs(int u, int fa)
{
    cycle.push_back(u);
    if (u == t) {
        sort(cycle.begin(), cycle.end());
        for (int x: cycle) { cout << x << " "; }
        exit(0);
    }
    for (int v: G[u]) {
        if (v != fa) { dfs(v, u); }
    }
    cycle.pop_back();
}
int main()
{
	dsu d(n);  // 见并查集板子
	for (int i = 1; i <= n; ++i) {
	    int u, v;
	    cin >> u >> v;
	    G[u].push_back(v);
	    G[v].push_back(u);
	    if (d.same(u, v)) { s=u; t=v; }
	    d.merge(u, v);
	}
	dfs(s, 0);
}