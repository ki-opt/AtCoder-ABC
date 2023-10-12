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
	vector<int> a(M), b(M);
	rep(i,M) cin >> a[i] >> b[i];
	vector<vector<int>> city(N,vector<int>(N,0));

	rep(i,M) {
		city[a[i]-1][b[i]-1] += 1;
		city[b[i]-1][a[i]-1] += 1;
	}
	rep(i,N) {
		int ans = 0;
		rep(j,N) {
			if (i != j && city[i][j] >= 1) ans += city[i][j];
		}
		cout << ans << endl;
	}

	return 0;
}