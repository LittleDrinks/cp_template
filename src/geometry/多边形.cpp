// 面积 * 2
T area(const vector<Point> &po) {
	T s = 0;
	int n = po.size();
	for (size_t i = 0; i < n; ++i) {
		s += (po[i] ^ po[(i + 1) % n]);
	}
	return abs(s);
}
// 周长
db circ(const vector<Point> &po) {
    db s = 0;
    int n = po.size();
    for (int i = 0; i < n; ++i) {
        s += (po[i] - po[(i + 1) % n]).len();
    }
    return s;
}
// Sunday's algorithm 光线回转法
// 在整数范围内判断一个点是否在多边形（不保证凸包）内部
// 亦可用于求某点相对于该多边形的回转数
pair<bool,int> winding(const vector<Point> &po, Point p) {
    int wn = 0, n = po.size();
    for (int i = 0; i < n; ++i) {
        if (Line(po[i], po[(i+1)%n]).onSegment(p)) {
            return { true, -inf };
        }
        int k = Line(po[i], po[(i+1)%n]).toLeft(p);
        int d1 = sgn(po[i].y - p.y);
        int d2 = sgn(po[(i + 1) % n].y - p.y);
        if (k>0 && d1<=0 && d2>0) { wn++; }
        if (k<0 && d2<=0 && d1>0) { wn--; }
    }
    return { wn!=0, wn };
}