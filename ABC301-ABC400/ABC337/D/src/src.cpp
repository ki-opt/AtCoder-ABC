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
	vector<string> S(H), s(H);
	rep(i,H) {
		cin >> S[i];
		s[i] = S[i];
		rep(j,W) if (s[i][j] == '.') s[i][j] = 'o';
	}

	vector<vector<int>> row(H,vector<int>(W,-1)), row_dot(H,vector<int>(W,-1)), 
		col(H,vector<int>(W,-1)), col_dot(H,vector<int>(W,-1));
	if (W >= K) {
		rep(i,H) {
			int cnt = 0, cnt_dot = 0;
			rep(j,K) {
				if (s[i][j] == 'o') cnt++;
				if (S[i][j] == '.') cnt_dot++;
			}
			rep(j,W) {
				row[i][j] = cnt; row_dot[i][j] = cnt_dot;
				if (s[i][j] == 'o') cnt--;
				if (S[i][j] == '.') cnt_dot--;
				if (j+K < W) {
					if (s[i][j+K] == 'o') cnt++;
					if (S[i][j+K] == '.') cnt_dot++;
				} else break;
			}
		}
	}
	if (H >= K) {
		rep(i,W) {
			int cnt = 0, cnt_dot = 0;
			rep(j,K) {
				if (s[j][i] == 'o') cnt++;
				if (S[j][i] == '.') cnt_dot++;
			}
			rep(j,H) {
				col[j][i] = cnt; col_dot[j][i] = cnt_dot;
				if (s[j][i] == 'o') cnt--;
				if (S[j][i] == '.') cnt_dot--;
				if (j+K < H) {
					if (s[j+K][i] == 'o') cnt++;
					if (S[j+K][i] == '.') cnt_dot++;
				} else break;
			}
		}
	}

	int ans = INT_MAX;
	rep(i,H) {
		rep(j,W) {
			if (row[i][j] == K) {
				ans = min(ans,row_dot[i][j]);
			}
			if (col[i][j] == K) {
				ans = min(ans,col_dot[i][j]);
			}
		}
	}
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}