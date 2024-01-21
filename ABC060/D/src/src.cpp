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
	ll N, W; cin >> N >> W;
	vector<ll> w(N), v(N);
	ll w1;
	rep(i,N) {
		cin >> w[i] >> v[i];
		if (i == 0) { w1 = w[i]; w[i] = 0; }
		else w[i] -= w1;
	}
	
	vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(N+1,vector<ll>(3*N,0)));
	ll ans = 0;
	repp(i,0,N) {
		dp[i+1][0][w[i]] = max(v[i],dp[i][0][w[i]]);
		if (w1 + w[i] <= W) ans = max(ans,dp[i+1][0][w[i]]);
		rep(j,N) {
			rep(k,3*(N-1)) {
				if (dp[i][j][k] > 0) {
					dp[i+1][j+1][k+w[i]] = max(dp[i][j][k]+v[i],dp[i+1][j+1][k+w[i]]);
					dp[i+1][j][k] = max(dp[i][j][k],dp[i+1][j][k]);
					if ((j + 2) * w1 + k + w[i] <= W) ans = max(ans,dp[i+1][j+1][k+w[i]]);
					if ((j + 1) * w1 + k <= W) ans = max(ans,dp[i+1][j][k]);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}