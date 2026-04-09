// 求平面点集的凸包，conv[0]是最左下角的点，逆时针顺序
// Andrew 算法，时间复杂度 O(nlogn)
vector<Point> toConvex(vector<Point> po) {
	if (po.empty()) { return {}; }
	sort(po.begin(), po.end());
    vector<Point> conv;
	auto check = [&](Point u){
		Point p1=conv.back(), p2=conv[conv.size()-2];
		return sgn((p1-p2)^(u-p1))<=0;
	};
	for (const Point &u: po) {
		while (conv.size()>1 && check(u)) { conv.pop_back(); }
		conv.push_back(u);
	}
	size_t k = conv.size();
	po.pop_back();
    reverse(po.begin(),po.end());
	for (const Point &u: po) {
		while (conv.size()>k && check(u)) { conv.pop_back(); }
		conv.push_back(u);
	}
	conv.pop_back();
    return conv;
}
// 判断点集是不是凸包
// 不能直接叉积符号相加，因为可能绕了多圈
bool isConvex(const vector<Point> &po) {
	if (po.size() < 3) { return false; }
	vector<Point> conv = toConvex(po);
	if (conv.size() != po.size()) { return false; }
	int n = (int)po.size();
	for (int st = 0; st < n; ++st) {
		if (!(conv[st] == po[0])) { continue; }
		for (int dir : {1, -1}) {
			bool ok = true;
			for (int i = 0; i < n; ++i) {
				int idx = (st + dir * i) % n;
				if (idx < 0) { idx += n; }
				if (!(po[i] == conv[idx])) {
					ok = false;
					break;
				}
			}
			if (ok) { return true; }
		}
	}
	return false;
}
// 判断点是否在凸包内
bool inConvex(const vector<Point> &conv, Point p) {
	int cnt = 0;
	for (size_t i = 0; i < conv.size(); ++i) {
		Point p1 = conv[i], p2 = conv[(i + 1) % conv.size()];
		if (Line(p1,p2).onSegment(p)) { return true; }
		cnt += toLeft(p1, p2, p);
	}
	if (abs(cnt) == conv.size()) { return true; }
	else { return false; }
}