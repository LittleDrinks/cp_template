void add(int p) {
}
void del(int p) {
}
void solve() {
    vector<tuple<int, int, int>> qu(q);
    for (int i = 0; i < q; ++i) {
        auto &[l, r, id] = qu[i];
        id = i;
        cin >> l >> r;
    }
    sort(qu.begin(), qu.end(), [&](auto qa, auto qb){
        auto &[l1, r1, id1] = qa;
        auto &[l2, r2, id2] = qb;
        int b1 = l1 / siz;
        int b2 = l2 / siz;
        if (b1 == b2) {
            return b1 & 1 ? r1 < r2 : r1 > r2;
        }
        return b1 < b2;
    });
    vector<ll> ans(q);
    for (auto &[l, r, id]: qu) {
        while (R < r) { add(++R); }
        while (L > l) { add(--L); }
        while (R > r) { del(R--); }
        while (L < l) { del(L++); }
        ans[id] = res;
    }
    for (auto x: ans) {
        cout << x << "\n";
    }
}