vector<int> stk;
vector<int> L(n+1), R(n+1);
for (int i = 1; i <= n; ++i) {
	int flag = 0;
	while (!stk.empty()) {
		if (a[stk.back()] > a[i]) {  // 小根堆
			flag = stk.back(); stk.pop_back();
		} else {
			break;
		}
	}
	if (flag) { L[i] = flag; }
	if (!stk.empty()) { R[stk.back()] = i; }
	stk.push_back(i);
}
function<void(int)> dfs = [&](int x){
	cerr << "now node " << x << "\n";
	cerr << ":: L = " << L[x] << "\n";
	cerr << ":: R = " << R[x] << "\n";
	if (L[x]) dfs(L[x]);
	if (R[x]) dfs(R[x]);
};
dfs(stk[0]);