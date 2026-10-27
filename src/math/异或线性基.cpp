template<class T, int B>
struct LinearBasis {
    // T 使用有符号数, B < digits 避免 corner case
    // LinearBasis<ll, 62>

    array<T, B> a{};
    int tot = 0;
    bool dependent = false;

    void clear() {
        a.fill(0);
        tot = 0;
        dependent = false;
    }
    bool insert(T x) {
        assert(x >= 0 && x < (T(1)<<B));
        for (int i = B-1; i >= 0; --i) {
            if (!(x>>i&1)) continue;
            if (a[i]) {
                x ^= a[i];
                continue;
            }
            for (int j = i-1; j >= 0; --j) {
                if (a[j] && (x>>j&1)) x ^= a[j];
            }
            for (int j = i+1; j < B; ++j) {
                if (a[j]>>i&1) a[j] ^= x;
            }
            a[i] = x;
            ++tot;
            return true;
        }
        dependent = true;
        return false;
    }
    void merge(const LinearBasis &b) {
        bool dep = b.dependent;
        for (auto x: b.a) {
            if (x) insert(x);
        }
        dependent |= dep;
    }
    // 是否能由非空子集异或得到 x
    bool testNonEmpty(T x) const {
        T y = x;
        for (int i = B-1; i >= 0; --i) {
            if (y>>i&1) y ^= a[i];
        }
        return y == 0 && (x != 0 || dependent);
    }
    T queryMax(T x = 0) const {
        assert(x >= 0);
        for (int i = B-1; i >= 0; --i) {
            x = max(x, x^a[i]);
        }
        return x;
    }
    // 去重，包含 0，0-based 第 k 小
    T queryKthMin(T k) const {
        if (k < 0 || k >= (T(1)<<tot)) return -1;
        T res = 0;
        int j = 0;
        for (int i = 0; i < B; ++i) {
            if (!a[i]) continue;
            if (k>>j&1) res ^= a[i];
            ++j;
        }
        return res;
    }
    T queryKthMax(T k) const {
        T cnt = T(1)<<tot;
        if (k < 0 || k >= cnt) return -1;
        return queryKthMin(cnt-k-1);
    }
};
