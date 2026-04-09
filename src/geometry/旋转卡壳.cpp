// 旋转卡壳
template<typename F>
void rotcaliper(const vector<Point> &conv, F&& func) {
	auto area = [](Point u, Point v, Point w){ return abs((w-u)^(w-v)); };
    int n = conv.size();
	for (size_t i=0, j=1; i < n; ++i) {
        // 边 (i, i+1) 的对踵点是 j
		func(conv[i], conv[(i+1)%n], conv[j]);
		while (area(conv[(j+1)%n],conv[i],conv[(i+1)%n]) >= area(conv[j],conv[i],conv[(i+1)%n])) {
			j = (j+1)%n;
			func(conv[i], conv[(i+1)%n], conv[j]);
		}
	}
}
// 旋转卡壳运用：求凸包直径
T diameter2(const vector<Point> &conv) {
	if (conv.size() == 1) { return 0; }
	if (conv.size() == 2) { return (conv[0]-conv[1]).len2(); }
	T ans = 0;
	rotcaliper(conv, [&](Point a, Point b, Point c){
		ans = max( { ans, (a-c).len2(), (b-c).len2() } );
	});
	return ans;
}