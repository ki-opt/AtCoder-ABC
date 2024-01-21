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
	ll X, Y, Z;
	string S;
	cin >> X >> Y >> Z >> S;

	vector<vector<ll>> dp(S.size(),vector<ll>(2,LLONG_MAX));
	if (S[0] == 'a') {
		dp[0][0] = X;
		dp[0][1] = Z + Y;
	} else if (S[0] == 'A') {
		dp[0][0] = Y;
		dp[0][1] = Z + X;
	}
	repp(i,1,S.size()) {
		if (S[i] == 'a') {
			dp[i][0] = min(dp[i-1][0] + X, dp[i-1][1] + Z + X);
			dp[i][1] = min(dp[i-1][0] + Z + Y, dp[i-1][1] + Y);
		} else if (S[i] == 'A') {
			dp[i][0] = min(dp[i-1][0] + Y, dp[i-1][1] + Z + Y);
			dp[i][1] = min(dp[i-1][0] + Z + X, dp[i-1][1] + X);
		}
	}
	cout << min(dp[S.size()-1][0],dp[S.size()-1][1]) << endl;

	return 0;
}