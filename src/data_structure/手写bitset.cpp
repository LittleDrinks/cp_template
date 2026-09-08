using u64 = uint64_t;
using u128 = __uint128_t;
u64 rev64(u64 x) {
    x = ((x>>1 )&0x5555555555555555ULL) | ((x&0x5555555555555555ULL)<<1);
    x = ((x>>2 )&0x3333333333333333ULL) | ((x&0x3333333333333333ULL)<<2);
    x = ((x>>4 )&0x0f0f0f0f0f0f0f0fULL) | ((x&0x0f0f0f0f0f0f0f0fULL)<<4);
    x = ((x>>8 )&0x00ff00ff00ff00ffULL) | ((x&0x00ff00ff00ff00ffULL)<<8);
    x = ((x>>16)&0x0000ffff0000ffffULL) | ((x&0x0000ffff0000ffffULL)<<16);
    return (x>>32) | (x<<32);
}
u64 lowmask(int k) {
    return k==64? ~0ULL: (k? (1ULL<<k)-1: 0); 
}
struct FastBitset {
    int n, B;
    vector<u64> a;
    FastBitset(int n): n(n), B((n+63)>>6), a(B) {}
    u64 read64(int p) const {
        if (p >= n || p <= -64) return 0;
        if (p < 0) return read64(0) << (-p);
        int b = p>>6, o = p&63;
        u64 x = a[b]>>o;
        if (o && b+1<B) x |= a[b+1]<<(64-o);
        return x & lowmask(min(64, n-p));
    }
    void write64(int p, u64 x, int len=64) {
        if (p < 0 || p >= n || len <= 0) return;
        len = min({len, 64, n-p});
        int b = p>>6;
        int o = p&63;
        int t = min(len, 64-o);
        u64 m = lowmask(t) << o;
        a[b] = (a[b]&~m) | ((x<<o)&m);
        if (t < len) {
            u64 m = lowmask(len-t);
            a[b+1] = (a[b+1]&~m) | ((x>>t)&m);
        }
    }
    void trim() { if (!a.empty() && (n&63)) a.back() &= lowmask(n&63); }
    void set(int p) { write64(p,1,1); }
    void reset(int p) { write64(p,0,1); }
    bool test(int p) const { return read64(p)&1; }
    void modify(int l, int r, bool v) {
        for (int p = l; p <= r; p += 64) {
            int len = min(64, r-p+1);
            write64(p, (v?lowmask(len): 0), len);
        }
    }
    FastBitset& operator&= (const FastBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < B; ++i) a[i]&=o.a[i];
        return *this;
    }
    FastBitset& operator|= (const FastBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < B; ++i) a[i]|=o.a[i];
        return *this;
    }
    FastBitset& operator^= (const FastBitset &o) {
        assert(n == o.n);
        for (int i = 0; i < B; ++i) a[i]^=o.a[i];
        return *this;
    }
    friend FastBitset operator& (FastBitset x, const FastBitset &y) { return x&=y; }
    friend FastBitset operator| (FastBitset x, const FastBitset &y) { return x|=y; }
    friend FastBitset operator^ (FastBitset x, const FastBitset &y) { return x^=y; }
    FastBitset slice(int l, int r) const {
        FastBitset res(r-l+1);
        for (int i = 0; i < res.B; ++i) {
            res.a[i] = read64(l+(i<<6));
        }
        res.trim();
        return res;
    }
    FastBitset& operator<<= (int k) {
        if (k <= 0) return *this;
        if (k >= n) { fill(a.begin(), a.end(), 0); return *this; }
        for (int i = B-1; i >= 0; --i) {
            a[i] = read64((i<<6)-k);
        }
        trim();
        return *this;
    }
    FastBitset& operator>>= (int k) {
        if (k <= 0) return *this;
        if (k >= n) { fill(a.begin(), a.end(), 0); return *this; }
        for (int i = 0; i < B; ++i) {
            a[i] = read64((i<<6)+k);
        } 
        trim();
        return *this;
    }
    friend FastBitset operator<< (FastBitset x, int k) { return x<<=k; }
    friend FastBitset operator>> (FastBitset x, int k) { return x>>=k; }

    FastBitset& rev() {
        reverse(a.begin(), a.end());
        for (auto &x: a) x = rev64(x);
        int s = (64-(n&63))&63;
        if (s) {
            for (int i = 0; i < B; ++i) {
                a[i] = (a[i]>>s) | (i+1<B? a[i+1]<<(64-s): 0); 
            }
        }
        trim();
        return *this;
    }
};