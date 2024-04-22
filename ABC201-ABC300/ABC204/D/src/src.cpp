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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N; cin >> N;
	vector<ll> T(N);
	rep(i,N) cin >> T[i];
	if (N == 1) {
		cout << T[0] << endl;
		return 0;
	}

	ll total = 0;
	rep(i,N) total += T[i];

	ll ans = LLONG_MAX;
	vector<vector<ll>> dp(N,vector<ll>(N*1000+1,0));
	rep(i,N) {
		dp[i][T[i]] = 1;
		ans = min(ans,max(T[i],total-T[i]));
		if (i == 0) continue;
		rep(j,N*1000+1) {
			if (dp[i-1][j] == 0) continue;
			dp[i][j] = 1;
			dp[i][j+T[i]] = 1;
			ans = min(ans,max(j+T[i],total-(j+T[i])));
		}
	}
	cout << ans << endl;

	/*
	ll left = 0, right = 100*1000+1;
	while (left + 1 < right) {

	}
	*/

	return 0;
}