const int X=1e5;
vector<int> fac[X+5];
for (int i = 1; i <= X; ++i) {
    for (int j = i; j <= X; j += i) {
        fac[j].push_back(i);
    }
}