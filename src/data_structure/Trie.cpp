int tot, trie[N][62], val[N];
int newNode() {
    ++tot;
    fill(trie[tot], trie[tot]+62, 0);
    val[tot] = 0;
    return tot;
}
void add(string s) {
    int now = 0;
    for (auto c: s) {
        int v;
        if ('a' <= c && c <= 'z') { v = c - 'a'; }
        if ('A' <= c && c <= 'Z') { v = c - 'A' + 26; }
        if ('0' <= c && c <= '9') { v = c - '0' + 52; }
        if (!trie[now][v]) {
            trie[now][v] = newNode();
        }
        now = trie[now][v];
        ++val[now];
    }
}
int query(string s) {
    int now = 0;
    for (auto c: s) {
        int v;
        if ('a' <= c && c <= 'z') { v = c - 'a'; }
        if ('A' <= c && c <= 'Z') { v = c - 'A' + 26; }
        if ('0' <= c && c <= '9') { v = c - '0' + 52; }
        if (!trie[now][v]) {
            return 0;
        }
        now = trie[now][v];
    }
    return val[now];
}