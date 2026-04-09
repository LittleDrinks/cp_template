struct FastBitset {
    using u64 = uint64_t;
    int n;
    vector<u64> a;

    FastBitset(int n = 0): n(n), a((n + 63) >> 6) { }

    static u64 mask(int len) {
        return len == 64 ? ~0ULL : (1ULL << len) - 1;
    }

    void set(int p) { a[p >> 6] |= 1ULL << (p & 63); }
    void reset(int p) { a[p >> 6] &= ~(1ULL << (p & 63)); }
    bool test(int p) const { return (a[p >> 6] >> (p & 63)) & 1; }

    void modify(int l, int r, bool v) {
        if (l > r) return;
        int bl = l >> 6, br = r >> 6;
        int lo = l & 63, ro = r & 63;

        if (bl == br) {
            u64 m = mask(ro - lo + 1) << lo;
            v ? a[bl] |= m : a[bl] &= ~m;
        }
        else {
            u64 lm = mask(64 - lo) << lo;
            u64 rm = mask(ro + 1);
            v ? a[bl] |= lm : a[bl] &= ~lm;
            v ? a[br] |= rm : a[br] &= ~rm;
            fill(a.begin() + bl + 1, a.begin() + br, (v ? ~0ULL : 0));
        }
    }

    FastBitset& operator&= (const FastBitset &o) {
        size_t siz = min(a.size(), o.a.size());
        for (size_t i = 0; i < siz; ++i)
            a[i] &= o.a[i];
        return *this;
    }
    FastBitset operator& (const FastBitset &o) {
        FastBitset res(*this);
        res &= o;
        return res;
    }

    FastBitset& operator|= (const FastBitset &o) {
        size_t siz = min(a.size(), o.a.size());
        for (size_t i = 0; i < siz; ++i)
            a[i] |= o.a[i];
        return *this;
    }
    FastBitset operator| (const FastBitset &o) {
        FastBitset res(*this);
        res |= o;
        return res;
    }

    FastBitset& operator^=(const FastBitset &o) {
        size_t siz = min(a.size(), o.a.size());
        for (size_t i = 0; i < siz; ++i) a[i] ^= o.a[i];
        return *this;
    }
    FastBitset operator^(const FastBitset &o) const {
        FastBitset res(*this); res ^= o; return res;
    }

    bool any() const { for (u64 x : a) if (x) return true; return false; }
    bool none() const { return !any(); }

    int count() const {
        int c = 0;
        for (u64 x: a) c += std::popcount(x);
        return c;
    }

    // 提取 [l,r]，复杂度 O((r-l)/64)
    FastBitset slice(int l, int r) const {
        FastBitset res(r - l + 1);
        int bl = l >> 6, br = r >> 6, lo = l & 63, len = r - l + 1;
        if (bl == br) { res.a[0] = (a[bl] >> lo) & mask(len); return res; }
        if (lo == 0) { // 对齐直接拷贝
            for (int i = bl, j = 0; i <= br; ++i) res.a[j++] = a[i];
        } else { // 跨块拼接：当前块右部 + 下一块左部
            int j = 0;
            u64 cur = a[bl] >> lo;
            for (int i = bl; i < br; ++i) {
                u64 nxt = a[i + 1];
                res.a[j++] = cur | (nxt << ((-lo) & 63));  // (-lo)&63 == 64-lo
                cur = nxt >> lo;
            }
            res.a[j] = cur;
        }
        if (int rem = len & 63) res.a.back() &= mask(rem);
        return res;
    }

    // 左移 k 位，复杂度 O(n/64)
    FastBitset& operator<<=(int k) {
        if (k <= 0) return *this;
        if (k >= n) { fill(a.begin(), a.end(), 0); return *this; }
        int b = k >> 6, o = k & 63, sz = a.size();
        for (int i = sz - 1; i >= 0; --i) {
            u64 v = (i - b >= 0) ? a[i - b] << o : 0;
            if (o && i - b - 1 >= 0) v |= a[i - b - 1] >> ((-o) & 63);
            a[i] = v;
        }
        fill(a.begin(), a.begin() + b, 0);
        if (int rem = n & 63) a.back() &= mask(rem);
        return *this;
    }
    FastBitset operator<<(int k) const { FastBitset r(*this); r <<= k; return r; }

    // 右移 k 位，复杂度 O(n/64)
    FastBitset& operator>>=(int k) {
        if (k <= 0) return *this;
        if (k >= n) { fill(a.begin(), a.end(), 0); return *this; }
        int b = k >> 6, o = k & 63, sz = a.size();
        for (int i = 0; i < sz; ++i) {
            u64 v = (i + b < sz) ? a[i + b] >> o : 0;
            if (o && i + b + 1 < sz) v |= a[i + b + 1] << ((-o) & 63);
            a[i] = v;
        }
        fill(a.end() - b, a.end(), 0);
        return *this;
    }
    FastBitset operator>>(int k) const { FastBitset r(*this); r >>= k; return r; }
};