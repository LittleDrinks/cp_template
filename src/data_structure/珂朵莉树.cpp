map<int,pair<int,int>> seg;
auto split(int p) {
    auto it = seg.upper_bound(p);
    if (it == seg.begin()) { return it; }
    --it;
    auto l = it->first;
    auto [r, d] = it->second;
    if (l > p || r < p) { return seg.end(); }
    if (l == p) { return it; }
    it->second.first = p - 1;
    seg[p] = { r, d+p-l };
    return seg.find(p);
}