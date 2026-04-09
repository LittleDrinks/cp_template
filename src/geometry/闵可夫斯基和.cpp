// a, b 在调用前必须 toConvex，保证逆时针顺序且没有重复点
vector<Point> minkowski_sum(const vector<Point> &a, const vector<Point> &b) {
    int n = a.size(), m = b.size();
    if (n == 0) return b;
    if (m == 0) return a;
    auto nxt = [&](int i, int sz) { return i + 1 == sz ? 0 : i + 1; };

    vector<Point> e1(n), e2(m);
    for (int i = 0; i < n; ++i) e1[i] = a[(i+1)%n] - a[i];
    for (int i = 0; i < m; ++i) e2[i] = b[(i+1)%m] - b[i];

    rotate(e1.begin(), min_element(e1.begin(), e1.end(), argcmp{}), e1.end());
    rotate(e2.begin(), min_element(e2.begin(), e2.end(), argcmp{}), e2.end());

    vector<Point> edge(n + m);
    merge(e1.begin(), e1.end(), e2.begin(), e2.end(), edge.begin(), argcmp{});

    vector<Point> res;
    res.reserve(n + m);
    Point cur = a[0] + b[0];
    auto check = [&](const Point &u) {
        if (res.size() < 2) return false;
        Point p1 = res.back(), p2 = res[res.size() - 2];
        return sgn((p1 - p2) ^ (u - p1)) == 0 && (p1 - p2) * (u - p1) >= 0;
    };

    for (const Point &v : edge) {
        while (check(cur)) res.pop_back();
        res.push_back(cur);
        cur = cur + v;
    }
    if (res.size() > 1 && check(res[0])) res.pop_back();
    return res;
}