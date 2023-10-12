#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];

	vector<vector<int>> ans(H,vector<int>(W,-1));
	int h = 0, w = 0;
	rep(i,N) {
		rep(j,a[i]) {
			//if ((h % 2 == 0 && w < W) || (h % 2 == 1 && w >= 0)) {}
			ans[h][w] = i + 1;
			if (h % 2 == 0) w++;
			else if (h % 2 == 1) w--;
			if (w == W) {
				h++;
				w = W - 1;
			} else if (w == -1) {
				h++;
				w = 0;
			}
		}
		/*
		if (w == W) {
			w = W - 1;
			h++;
		} else if (w == -1) {
			w = 0;
			h++;
		}*/
	}

	rep(i,H) {
		rep(j,W) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}