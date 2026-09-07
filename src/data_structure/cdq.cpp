auto cdq = [&](auto &&cdq, int l, int r, vector<int>&ord, vector<int>&tmp) -> void {
    if (l == r-1) {
        if (l) {
            f[l] = max(f[l], f[l-1]);
        }
        return;
    }
    int m = ((l + r) >> 1);
    const int nl = m-l;
    const int nr = r-m;
    auto lo = tmp.begin()+l;
    auto hi = tmp.begin()+m;
    partition_copy(ord.begin()+l, ord.begin()+r, lo, hi, [m](int x){ return x<m; });
    cdq(cdq, l, m, tmp, ord);
    int i=0;
    for (int j = 0; j < nr; ++j) {
        while (i < nl && sr[lo[i]]-sy[lo[i]] <= sr[hi[j]]-sy[hi[j]]) {
            t.modify(sr[lo[i]]-sb[lo[i]]+n+1, f[lo[i]]-lo[i]);
            ++i;
        }
        int fr = t.query(sr[hi[j]]-sb[hi[j]]+n+1);
        if (fr > -inf) {
            f[hi[j]] = max(f[hi[j]], fr + hi[j]);
        }
    }
    t.reset();
    cdq(cdq, m, r, tmp, ord);
    merge(lo, lo+nl, hi, hi+nr, ord.begin()+l, cmp);
};
vector<int> id(n+1), tmp(n+1);
iota(id.begin(), id.end(), 0);
sort(id.begin(), id.end(), cmp);
cdq(cdq, 0, n+1, id, tmp);