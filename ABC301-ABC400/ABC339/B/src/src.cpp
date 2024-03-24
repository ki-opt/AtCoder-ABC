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
	int H, W, N; cin >> H >> W >> N;
	vector<vector<char>> ans(H,vector<char>(W,'.'));
	int x = 0, y = 0;
	int dir = 0;
	rep(i,N) {
		if (ans[y][x] == '.') {
			ans[y][x] = '#';
			dir++;
			if (dir == 4) dir = 0;
		} else {
			ans[y][x] = '.';
			dir--;
			if (dir == -1) dir = 3;
		}
		if (dir == 0) y--;
		else if (dir == 1) x++;
		else if (dir == 2) y++;
		else if (dir == 3) x--;
		if (x == W) x = 0;
		if (x == -1) x = W-1;
		if (y == H) y = 0;
		if (y == -1) y = H-1;
	}
	rep(i,H) {
		rep(j,W) {
			cout << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}