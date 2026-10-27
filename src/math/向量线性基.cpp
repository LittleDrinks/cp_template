struct LinearBasis {
    static constexpr db eps=1e-7L;
    int m, rk=0;
    vector<vector<db>> b;
    LinearBasis(int m): m(m), b(m) { }

    bool insert(vector<db> a) {
        for (int i = 0; i < m; ++i) {
            if (abs(a[i]) < eps) continue;
            if (b[i].empty()) {
                b[i] = move(a);
                rk++;
                return true;
            }
            db t = a[i] / b[i][i];
            for (int j = i+1; j < m; ++j) {
                a[j] -= t * b[i][j];
            }
            a[i] = 0;
        }
        return false;
    }
};