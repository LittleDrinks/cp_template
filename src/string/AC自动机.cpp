struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;   // 此处的字符串长度
        int link;  // 失效指针
        int old;   // 该节点对应的下一个
        int num;   // 该节点是哪一个模式串的结尾
        array<int,ALPHABET> next;
    };
    vector<Node> t;
    AhoCorasick(): t(2, Node()) {
        t[0].next.fill(1);
        t[0].len = -1;
    }
    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }
    int add(const string &a, int dir) {
        int p = 1;
        for (auto c: a) {
            int x = c-'a';
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        t[p].num = dir;
        return p;
    }
    void build() {
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < ALPHABET; ++i) {
                int &u = t[x].link;
                int &v = t[x].next[i];
                if (v == 0) {
                    v = t[u].next[i];
                } else {
                    t[v].link = t[u].next[i];
                    t[v].old = t[t[v].link].num ? t[v].link : t[t[v].link].old;
                    q.push(v);
                }
            }
        }
    }
    int next(int p, int x) { return t[p].next[x]; }
    int link(int p) { return t[p].link; }
    int old(int p) { return t[p].old; }
    int num(int p) { return t[p].num; }
    int size() { return t.size(); }
};

void solve() {
    ac.add();  // 插入若干模式串
    ac.build();
    string s; cin >> s;
    int p = 1;
    for (int i = 1; i <= n; ++i) {
        int x = s[i-1] - 'a';
        p = ac.next(p, x);
        for (int j = p; j; j=ac.old(j)) {
            if (ac.num(j)) {
                // ...
            }
        }
    }
}