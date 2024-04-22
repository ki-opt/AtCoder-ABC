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
	int N; cin >> N;
	int X, Y; cin >> X >> Y;
	vector<int> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];

	vector<vector<vector<int>>> dp(N,vector<vector<int>>(301,vector<int>(301,INT_MAX)));
	int ans = INT_MAX;
	dp[0][A[0]][B[0]] = 1;
	repp(i,1,N) {
		dp[i][A[i]][B[i]] = min(dp[i][A[i]][B[i]], 1);
		rep(j,301) {
			rep(k,301) {
				if (dp[i-1][j][k] == INT_MAX) continue;
				int j_dash = (j+A[i] >= 300 ? 300 : j+A[i]);
				int k_dash = (k+B[i] >= 300 ? 300 : k+B[i]);
				dp[i][j_dash][k_dash] = min(dp[i][j_dash][k_dash],dp[i-1][j][k]+1);
				dp[i][j][k] = min(dp[i-1][j][k], dp[i][j][k]);
			}
		}
	}

	rep(i,N) {
		repp(j,X,301) {
			repp(k,Y,301) {
				ans = min(ans,dp[i][j][k]);
			}
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;

	return 0;
}