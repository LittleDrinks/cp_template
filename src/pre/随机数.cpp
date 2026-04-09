mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int x, int y) {
	return uniform_int_distribution<int>(x, y)(rng);
}
shuffle(a.begin(), a.end(), rng);