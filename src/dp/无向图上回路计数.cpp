// CF11D
for (int i = 1; i <= n; ++i) {
	f[1<<(i-1)][i] = 1;
}
for (int s = 0; s < (1<<n); ++s) {
	for (int i = 1; i <= n; ++i) {
		if (!f[s][i]) { continue; }
		for (int j = 1; j <= n; ++j) {
			if (!G[i][j]) { continue; }
			if ((s&-s) > 1<<(j-1)) { continue; }  // 起点不能改
			if(s>>(j-1)&1) {
				if ((s&-s) == 1<<(j-1)) {  // 走回起点
					ans += f[s][i];
				}
			} else {
				f[s|(1<<(j-1))][j] += f[s][i];
			}
		}
	}
}
cout << (ans-m)/2 << "\n";  // 去除无向边，环正走反走算一个