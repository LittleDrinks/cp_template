const int N = 1e6 + 1;
vector<int>check(N);
void solve() {
	int n, g= -1;
	cin >> n;
	if (!check[n]) {
		cout << "0\n\n";
		return;
	}
	int phi_n = euler_phi(n);
	auto order = [&](int x) {//求x的阶
		int ord = 0, tmp = 1;
		while (1) {
			ord++;
			tmp *= x;
			tmp %= n;
			if (tmp == 1)return ord;
		}
		};
	for (int a = 1; a <= n; a++) {
		if (gcd(a,n) ==1 && order(a) == phi_n) {
			g = a;
			break;
		}
	}
	vector<int> ans;
	if (g != -1) {
		int tmp = 1;
		for (int i = 1; i <= phi_n; i++) {
			tmp *= g;
			tmp %= n;
			if (gcd(phi_n, i) == 1)ans.push_back(tmp);
		}
	}
}

//check数组构造
check[2] = 1;
check[4] = 1;
vector<int> prime = getPrime(N);
for (auto p : prime) 
	if (p % 2 == 1) {
		long long tmp = p;
		while (tmp < N) {
			check[tmp] = 1;
			if (2 * tmp < N)check[2 * tmp] = 1;
			tmp *= p;
		}
	}