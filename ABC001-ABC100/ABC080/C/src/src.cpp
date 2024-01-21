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
	int N;
	cin >> N;
	vector<int> ci(N,0);
	vector<vector<int>> F(N,vector<int>(10));
	rep(i,N) rep(j,10) {
		cin >> F[i][j];
	}
	vector<vector<int>> P(N,vector<int>(11));
	rep(i,N) repp(j,0,11) cin >> P[i][j];

	ll ans = LLONG_MIN;
	for (int msk = 1; msk < (1 << 10); msk++) {
		ll sum = 0;
		rep(i,N) {
			int c = 0;
			rep(j,10) if ((msk & (1 << j)) && F[i][j] == 1) c++;
			sum += P[i][c];
		}
		ans = max(ans,sum);
	}
	cout << ans << endl;

	return 0;
}
