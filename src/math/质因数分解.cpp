typedef pair<int, int> pii;
vector<pii> divide(int n) {
	vector<pii> primes;
	int cnt = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		cnt = 0;
		while (n % i == 0)n /= i, cnt++;
		if (cnt)primes.push_back(make_pair(i, cnt));
	}
	if (n > 1)primes.push_back(make_pair(n, 1));
	return primes;
}
//注意1要特判，n==1时会返回空集