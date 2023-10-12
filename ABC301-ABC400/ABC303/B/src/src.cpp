#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> a(M,vector<int>(N));
	rep(i,M) {
		rep(j,N) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> check(N,vector<int>(N,0));
	rep(i,M) {
		rep(j,N-1) {
			if (a[i][j] < a[i][j+1]) check[a[i][j]-1][a[i][j+1]-1]++;
			else check[a[i][j+1]-1][a[i][j]-1]++;
		}
	}

	int ans = 0;
	rep(i,N) {
		repp(j,N,i+1) {
			if (check[i][j] == 0) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}