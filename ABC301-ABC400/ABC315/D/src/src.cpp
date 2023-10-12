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
	int H, W;
	cin >> H >> W;
	vector<vector<char>> c(H,vector<char>(W));
	rep(i,H) {
		rep(j,W) {
			cin >> c[i][j];
		}
	}


	int ans = H * W;
	int flag = 1;
	while(flag == 1) {
		flag = 0;
		vector<unordered_map<char,vector<int>>> row(H), column(W);
		// mark
		rep(i,H) {
			rep(j,W) {
				if (c[i][j] >= 'a' && c[i][j] <= 'z') {
					row[i][c[i][j]].push_back(j);
				}
			}
		}
		rep(j,W) {
			rep(i,H) {
				if (c[i][j] >= 'a' && c[i][j] <= 'z') {
					column[j][c[i][j]].push_back(i);
				}
			}
		}

		// erase
		rep(i,H) {
			for (char moji = 'a'; moji <= 'z'; moji++) {
				if (row[i][moji].size() >= 2) {
					flag = 1;
					rep(cnt,row[i][moji].size()) {
						int j = row[i][moji][cnt];
						c[i][j] = '.';
						ans--;
					}
				}
			}
		}
		rep(j,W) {
			for (char moji = 'a'; moji <= 'z'; moji++) {
				flag = 1;
				if (column[j][moji].size() >= 2) {
					rep(cnt,column[j][moji].size()) {
						int i = column[j][moji][cnt];
						c[i][j] = '.';
						ans--;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}