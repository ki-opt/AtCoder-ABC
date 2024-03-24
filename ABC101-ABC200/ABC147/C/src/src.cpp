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
	vector<int> A(N);
	vector<vector<int>> x(N), y(N);
	rep(i,N) {
		cin >> A[i];
		x[i].resize(A[i]), y[i].resize(A[i]);
		rep(j,A[i]) {
			cin >> x[i][j] >> y[i][j];
			x[i][j]--;
		}
	}

	int ans = 0;
	for (int bit = 1; bit < (1 << N); bit++) {
		vector<int> check(N,-1);
		int cnt = 0;
		rep(i,N) {
			check[i] = 0x0001 & (bit >> i);
			cnt += check[i];
		}
		
		bool isFound = true;
		rep(i,N) {
			if (check[i] == 0) continue;
			rep(j,A[i]) {
				if (y[i][j] == 0) {
					if (check[x[i][j]] != 0) {
						isFound = false;
						break;
					}
				} else if (y[i][j] == 1) {
					if (check[x[i][j]] != 1) {
						isFound = false;
						break;
					}
				}
			}
		}
		if (isFound) ans = max(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}