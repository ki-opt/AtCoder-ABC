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
	vector<string> S(H);
	rep(i,H) cin >> S[i];

	int col_min = INT_MAX, col_max = -1;
	rep(i,H) {
		rep(j,W) {
			if (S[i][j] == '#') {
				if (j < col_min) col_min = j;
				if (j > col_max) col_max = j;
			}
		}
	}
	int row_min = INT_MAX, row_max = -1;
	rep(j,W) {
		rep(i,H) {
			if (S[i][j] == '#') {
				if (i < row_min) row_min = i;
				if (i > row_max) row_max = i;
			}
		}
	}
	//cout << col_min << endl;
	//cout << col_max << endl;

	for(int i = row_min; i <= row_max; i++) {
		for (int j = col_min; j <= col_max; j++) {
			if (S[i][j] == '.') {
				cout << i + 1 << " " << j + 1 << endl;
				return 0;
			}
		}
	}

	return 0;
}