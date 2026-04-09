int d[N], mxd;
void dfs(int u, int fa)
{
	for (auto v: G[u]) {
		if (v != fa) {
			dfs(v, u);
			mxd = max(mxd, d[u]+d[v]+1);
			d[u] = max(d[u], d[v]+1);
		}
	}
}