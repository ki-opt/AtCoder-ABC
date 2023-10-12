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
	ll N;
	cin >> N;
	vector<ll> X(N), Y(N), Z(N);
	ll total_xy = 0, total_z = 0;
	rep(i,N) {
		cin >> X[i] >> Y[i] >> Z[i];
		total_xy += X[i] + Y[i];
		total_z += Z[i];
	}

	vector<vector<ll>> dp(N,vector<ll>(total_z+1,LLONG_MAX));
	dp[0][Z[0]] = max((ll)0,(Y[0]-X[0])/2+1);
	repp(i,1,N) {
		repp(j,0,total_z+1) {
			if (j < Z[i]) {
				dp[i][j] = dp[i-1][j];
				continue;
			} else if (j >= Z[i]) {
				ll tmp = (Y[i] - X[i]) / 2 + 1;
				if (dp[i-1][j-Z[i]] == LLONG_MAX) {
					if (j == Z[i])	dp[i][j] = min(max((ll)0,tmp),dp[i-1][j]);
					else dp[i][j] = dp[i-1][j];
				} else {
					dp[i][j] = min(dp[i-1][j-Z[i]]+max((ll)0,tmp),dp[i-1][j]);
				}
			}//*/
			/*
			ll tmp = Y[i] - X[i];
			if (tmp <= 0) {
				if (dp[i][j-Z[i]] == -1) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = dp[i][j-Z[i]];
				}
			} else {
				tmp = tmp / 2 + 1;
				if (dp[i][j-Z[i]] == -1) {
					if (j != Z[i]) continue;
					dp[i][j] = tmp;
				} else {
					dp[i][j] = dp[i][j-Z[i]] + tmp;
				}
			}*/
		}
	}

	ll ans = LLONG_MAX;
	int i = N - 1;
	for(int j = total_z / 2 + 1; j < total_z + 1; j++) {
		if (dp[i][j] == LLONG_MAX) continue;
		ans = min(dp[i][j],ans);
	}
	cout << ans << endl;

	return 0;
}