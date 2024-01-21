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
	vector<vector<char>> A(H,vector<char>(W)), B(H,vector<char>(W));
	rep(i,H) rep(j,W) cin >> A[i][j];
	rep(i,H) rep(j,W) cin >> B[i][j];

	rep(s,H) {
		vector<vector<char>> tmp = A;
		rep(i,H) rep(j,W) {
			if (i + 1 < H) A[i][j] = tmp[i+1][j];
			else A[i][j] = tmp[0][j];
		}
		rep(t,W) {
			vector<vector<char>> tmp_2 = A;
			rep(i,H) rep(j,W) {
				if (j + 1 < W) A[i][j] = tmp_2[i][j+1];
				else A[i][j] = tmp_2[i][0];
			}
			bool isFound = true;
			rep(i,H) rep(j,W) {
				if (A[i][j] != B[i][j]) { isFound = false; break; }
			}
			if (isFound) { cout << "Yes" << endl; return 0; }
		}
	}
	cout << "No" << endl;
	return 0;
}