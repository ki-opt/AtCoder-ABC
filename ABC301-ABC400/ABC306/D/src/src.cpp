#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N;
	cin >> N;
	vector<long int> X(N), Y(N);
	rep(i,N) cin >> X[i] >> Y[i];

	long int ans = 0;
	vector<vector<long int>> dp(N+1,vector<long int>(2,0));
	repp(i,N+1,1) {
		int x = X[i-1], y = Y[i-1];
		if (x == 0) {
			dp[i][0] = max({dp[i-1][0], dp[i-1][0] + y, dp[i-1][1] + y});
			dp[i][1] = dp[i-1][1];
		} else if (x == 1) {
			dp[i][0] = dp[i-1][0];
			dp[i][1] = max(dp[i-1][0] + y, dp[i-1][1]);
		}
		ans = max({dp[i][0],dp[i][1],ans});
		//ans = max(dp[i][1],ans);
	}
	cout << max(dp[N][0],dp[N][1]) << endl;

	return 0;
}