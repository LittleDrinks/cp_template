#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using i128 = __int128;

const int L=18;
int a[L+5];
ll f[L+5][15]
ll dfs(int p, bool limit, bool lead0, int last)
{
	if (!p) { return 1; }
	auto& now = f[p][last];
	if (!limit && !lead0 && ~now) {
		return now;
	}
	int up = limit ? a[p] : 9;
	ll res = 0;
	for (int i = 0; i <= up; ++i) {
		if (!lead0 && abs(last-i) < 2) { continue; }
		res += dfs(p-1, limit&&(i==up), lead0&&(i==0), i);
	}
	if (!limit && !lead0) {
		now = res;
	}
	return res;
}
ll query(ll x)
{
	int len = 0;
	for (; x; x /= 10) {
		a[++len] = x % 10;
	}
	return dfs(len, true, true, 0);
}

void solve()
{
	ll a, b;
	cin >> a >> b;
	cout << query(b) - query(a-1) << "\n";
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	memset(f, -1, sizeof(f));  // 不要忘记设为 -1
	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
}