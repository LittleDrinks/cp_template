struct Line {
    Point a, b;
    Vector v;
	Line(Point a, Point b): a(a), b(b) { v = b - a; }
	int toLeft(Point p) { return sgn(v^(p-a)); }
    // 判断点 p 是否在线段 AB 上
	bool onSegment(Point p) { return (toLeft(p)==0) && ((p-a)*(p-b)<=0); }
    // 点 p 到直线 AB 的距离
	db distToLine(Point p) { return fabs((v^(p-a))/v.len()); }
    // 点 p 到线段 AB 的距离
    db distToSeg(Point p) {
        if(a == b) return (p-a).len();
        Point v1=b-a, v2=p-a, v3=p-b;
        if(sgn(v1*v2) < 0) return v2.len();
        if(sgn(v1*v3) > 0) return v3.len();
        return distToLine(p);
    }
    // 点 p 在直线上的投影
	Point proj(Point p) { return a+v*((v*(p-a))/(v*v)); }
	// 用整数操作判断直线与点 C 的距离是否小于（等于）某个值 r
	// 常见于判断直线与圆的位置关系
	// 注意叉乘再相乘可能会爆 ll，所以这里用 __int128
	bool disLess(Point p, i128 r) {
	    i128 xmult = (v^(p-a));
	    return xmult*xmult <= r*r*v.len2();
	}
};

// 判断两条直线是否平行
bool isParallel(Line l1, Line l2) {
	return sgn(l1.v^l2.v)==0 && sgn(l1.v^(l1.a-l2.a))!=0;
}

// 判断两条线段是否相交
// 先做两次跨立实验判断是否规范相交，再特判至少三点共线的情况
bool hasIntersection(Line L1, Line L2) {
	// 特判三点共线的情况
    if (L1.onSegment(L2.a)) { return true; }
    if (L1.onSegment(L2.b)) { return true; }
    if (L2.onSegment(L1.a)) { return true; }
    if (L2.onSegment(L1.b)) { return true; }
    // 跨立实验判断两直线是否规范相交
    // 线段端点分布在直线两侧，“线段与线段/线段与直线/直线与直线”是否相交对应修改即可
	function<bool(Line,Point,Point)> crossStanding = [](Line L, Point a, Point b){
        return L.toLeft(a) * L.toLeft(b) == -1;
    };
    return crossStanding(L1, L2.a, L2.b) && crossStanding(L2, L1.a, L1.b);
}

// 求两直线交点
// 求之前应该先判断有没有交点，避免精度误差，同时还要特判共线的情况
Point getIntersection(Line L1, Line L2) {
    Point P1=L1.a, P2=L2.a;
    Point v1=L1.v, v2=L2.v;
    return P1 + v1 * ( (v2^(P1-P2)) / (v1^v2) );
}

// 求线段到线段的距离
db dist(Line L1, Line L2) {
    if (hasIntersection(L1, L2)) { return 0; }
    return min({L1.distToSeg(L2.a), L1.distToSeg(L2.b), L2.distToSeg(L1.a), L2.distToSeg(L1.b)});
}