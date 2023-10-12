#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> a(H,vector<char>(W));
	rep(i,H) rep(j,W) cin >> a[i][j];

	unordered_map<int,int> row, column;
	rep(i,H) {
		int sum = 0;
		rep(j,W) {
			if (a[i][j] == '.') sum++;
			else break;
		}
		if (sum == W) row[i] = 1;
	}
	rep(i,W) {
		int sum = 0;
		rep(j,H) {
			if (a[j][i] == '.') sum++;
			else break;
		}
		if (sum == H) column[i] = 1;
	}
			
	rep(i,H) {
		if (row.count(i) > 0) continue;
		rep(j,W) {
			if (column.count(j) > 0) continue;
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}