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
	int H, N; cin >> H >> N;
	vector<int> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];
	
	vector<vector<int>> dp(N,vector<int>(H+1,INT_MAX));
	dp[0][A[0]] = B[0];
	rep(i,H) if (dp[0][i] != INT_MAX) {
		if (i + A[0] > H) dp[0][H] = dp[0][i] + B[0];
		else dp[0][i+A[0]] = dp[0][i] + B[0];
	}

	repp(i,1,N) {
		if (A[i] > H) dp[i][H] = min(dp[i-1][H],B[i]);
		else dp[i][A[i]] = min(dp[i-1][A[i]],B[i]);
		rep(j,H+1) {
			dp[i][j] = min(dp[i-1][j],dp[i][j]);
			if (j == H || dp[i][j] == INT_MAX) continue;
			int col = j + A[i];
			if (col > H) col = H;
			dp[i][col] = min(dp[i][col],dp[i][j]+B[i]);
		}
	}
	
	int ans = INT_MAX;
	rep(i,N) ans = min(ans,dp[i][H]);
	cout << ans << endl;

	/*
	double maxv = 0;
	int index;
	rep(i,N) {
		cin >> A[i] >> B[i];
		if (A[i] / B[i] > maxv) {
			maxv = A[i] / B[i];
			index = i;
		}
	}

	if (H % A[index] == 0) {
		cout << (H / (int)A[index]) * (int)B[index] << endl;
		return 0;
	} else {
		H -= (H / (int)A[index]) * (int)B[index];
		int ans = 0;
		for (int i = 0; i < N; i++) {
			te
		}
	}
	*/

	return 0;
}