template <typename T>
struct ST {
    int n=0, I=0;
    vector<int> Log;
    vector<vector<T>> st;
	function<T(T,T)> op;
	ST() { }
	ST(const vector<T>& a, function<T(T,T)> op): n(a.size()), Log(vector<int>(n+1)), op(op) {
		for (int i = 2; i <= n; ++i) {
        	I=Log[i]=Log[i/2]+1;
        }
        st.assign(I+1, vector<T>(n));
        copy(a.begin(), a.end(), st[0].begin());
        for (int i = 1; i <= I; ++i) {
            for (int j = 0; j+(1<<(i-1)) < n; ++j) {
                st[i][j] = op( st[i-1][j], st[i-1][j+(1<<(i-1))] );
            }
        }
    }
    T query(int l, int r) {
    	assert(l <= r);  // l > r 时的返回值需要特殊定义
        int s = Log[r-l+1];
        return op( st[s][l], st[s][r-(1<<s)+1] );
    }
	int find(int l, int x) {  // 第一个区间 [l,r] 最值大于等于 x 的 r
	    assert(l < n);
	    if (st[0][l] < x) { return l; }
	    if (query(l, n-1) >= x) { return n; }
	    int ans = l, g = st[0][l];
	    for (int i = I; i >= 0; --i) {
	        if (ans+(1<<i) < n && gcd(g, st[i][ans]) >= x) {
	            g = max(g, st[i][ans]);
	            ans += 1 << i;
	        }
	    }
	    return ans;
	}
};