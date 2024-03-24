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
	vector<string> S(N);
	rep(i,N) cin >> S[i];
	vector<vector<ll>> dp(N+1,vector<ll>(2,0));
	dp[0][0] = 1; dp[0][1] = 1;
	rep(i,N) {
		if (S[i] == "OR") {
			dp[i+1][0] += dp[i][0];
			dp[i+1][1] += dp[i][0] * 1 + dp[i][1] * 2;
		} else if (S[i] == "AND") {
			dp[i+1][0] += dp[i][0] * 2 + dp[i][1] * 1;
			dp[i+1][1] += dp[i][1] * 1;
		}
	}

	cout << dp[N][1] << endl;

	return 0;
}