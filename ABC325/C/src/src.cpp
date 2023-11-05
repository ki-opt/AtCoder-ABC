#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> S(H,vector<char>(W));
	rep(i,H) rep(j,W) cin >> S[i][j];

	int ans = 0;
	vector<vector<bool>> check(H,vector<bool>(W,false));
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] != '#') continue;
			if (check[i][j]) continue;
			ans++;
			queue<pair<int,int>> que;
			check[i][j] = true;
			que.push({i,j});
			while (!que.empty()) {
				auto tmp = que.front(); que.pop();
				int i_tmp = tmp.first, j_tmp = tmp.second;
				repp(i_dash,i_tmp-1,i_tmp+2) {
					if (i_dash < 0 || i_dash >= H) continue;
					repp(j_dash,j_tmp-1,j_tmp+2) {
						if (j_dash < 0 || j_dash >= W) continue;
						if (S[i_dash][j_dash] != '#') continue;
						if (check[i_dash][j_dash]) continue;
						que.push({i_dash,j_dash});
						check[i_dash][j_dash] = true;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}