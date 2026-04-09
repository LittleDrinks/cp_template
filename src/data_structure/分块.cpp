const int N = 1e5 + 5, S = 500;
int n, siz, B;

// arr 1-index <-> bk 1-index
inline int bk(int i) { return i / siz + 1; }
inline int bkl(int b) { return max(1, (b - 1) * siz); }
inline int bkr(int b) { return min(b * siz - 1, n); }

void solve(int l, int r) {
    siz = sqrt(n) + 1;
    B = bk(n);
    for (int b = bk(l); b <= bk(r); ++b) {
        int L = max(l, bk_l(b)), R = min(r, bk_r(b));
        if (b != bk(l) && b != bk(r)) {
            // 处理整块
        } else {
            // 处理散块
        }
    }
}