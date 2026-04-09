typedef long long ll;
ll Exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = Exgcd(b, a % b, y, x);
	y -= a / b * x;
    return d;
}