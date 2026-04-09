int n, deg[N<<1], cur[N<<1];
bool vis[N];
vector<int> ans;
vector<pair<int,int>> G[N<<1];

void dfs(int u)
{
    for (int &j = cur[u]; j < G[u].size(); ++j) {
        auto [v, i] = G[u][j];
        if (!vis[i]) {
            vis[i] = true;
            dfs(v);
            ans.push_back(i);
        }
    }
}

int main()
{
	int s = 1;
	while (s <= 2*n && deg[s] % 2 == 0) { ++s; }
	if (s > 2 * n) {
	    s = 1;
	    while (!deg[s]) { ++s; }
	}

	int cnt = 0;
	for (int i = 1; i <= 2*n; ++i) {
	    cnt += deg[i] % 2;
	}
	if (cnt > 2) {
	    cout << "NO\n"; return;
	}

	dfs(s);

	if (ans.size() != n) {
	    cout << "NO\n";
	} else {
	    cout << "YES\n";
	    for (auto x: ans) {
	        cout << x << " \n"[x == ans.back()];
	    }
	}
}