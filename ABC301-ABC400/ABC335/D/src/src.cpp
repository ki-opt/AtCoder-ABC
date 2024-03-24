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
	int N; cin >> N;
	vector<vector<int>> ans(N,vector<int>(N,-1));
	int x = 0, y = 0;
	int dir = 0;	// 0→ , 1↓, 2←, 3↑
	vector<vector<bool>> seen(N,vector<bool>(N,false));
	seen[0][0] = true;
	ans[0][0] = 1;
	rep(cnt,N*N-2) {
		if (dir == 0) {
			if (x + 1 < N && !seen[x+1][y]) x++;
			else y++, dir = 1;
		} else if (dir == 1) {
			if (y + 1 < N && !seen[x][y+1]) y++;
			else x--, dir = 2;
		} else if (dir == 2) {
			if (x - 1 >= 0 && !seen[x-1][y]) x--;
			else y--, dir = 3;
		} else if (dir == 3) {
			if (y - 1 >= 0 && !seen[x][y-1]) y--;
			else x++, dir = 0;
		}
		ans[x][y] = cnt + 2;
		seen[x][y] = true;
	}

	rep(i,N) {
		rep(j,N) {
			if (ans[i][j] != -1) cout << ans[i][j] << " ";
			else cout << "T" << " ";
		}
		cout << endl;
	}

	return 0;
}