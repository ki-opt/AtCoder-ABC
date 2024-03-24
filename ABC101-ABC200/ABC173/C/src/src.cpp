#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W, K; cin >> H >> W >> K;
	vector<string> c(H);
	rep(i,H) cin >> c[i];

	int ans = 0;
	for (int h = 0; h < (1 << H); h++) {
		for (int w = 0; w < (1 << W); w++) {
			int b = 0;
			rep(i,H) {
				if ((h >> i) & 0x01) continue;
				rep(j,W) {
					if ((w >> j) & 0x01) continue;
					if (c[i][j] == '#') b++;
				}
			}
			if (b == K) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}