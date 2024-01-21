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
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	vector<vector<vector<pair<int,int>>>> g(H,vector<vector<pair<int,int>>>(W));
	rep(i,H) rep(j,W) {
		if (i-1>=0 && S[i-1][j] == '.') g[i][j].push_back({i-1,j});
		if (i+1<H && S[i+1][j] == '.') g[i][j].push_back({i+1,j});
		if (j-1>=0 && S[i][j-1] == '.') g[i][j].push_back({i,j-1});
		if (j+1<W && S[i][j+1] == '.') g[i][j].push_back({i,j+1});
	}

	int ans = -1;
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] == '#') continue;
			queue<pair<int,int>> que;
			vector<vector<int>> seen(H,vector<int>(W,-1));
			seen[i][j] = 0;
			for (auto p : g[i][j]) { que.push(p); seen[p.first][p.second] = 1;}
			while (!que.empty()) {
				pair<int,int> tmp = que.front(); que.pop();
				for (auto p : g[tmp.first][tmp.second]) {
					if (seen[p.first][p.second] != -1) continue;
					que.push(p);
					seen[p.first][p.second] = seen[tmp.first][tmp.second] + 1;
				}
			}
			rep(k,H) rep(l,W) ans = max(ans,seen[k][l]);
		}
	}
	cout << ans << endl;

	return 0;
}