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
	vector<double> P(N);
	rep(i,N) cin >> P[i];
	vector<vector<double>> dp(N,vector<double>(N,0));
	
	// 初期値
	dp[0][0] = P[0];
	repp(i,1,N) {
		rep(j,i+1) {
			if (j == 0) {
				dp[i][j] = max(dp[i-1][j],P[i]);
			} else if (j == i) {
				dp[i][j] = 0.9*dp[i-1][j-1]+P[i];
			} else {
				dp[i][j] = max(dp[i-1][j],0.9*dp[i-1][j-1]+P[i]);
			}
		}
	}
	
	double ans = LLONG_MIN;
	rep(i,N) {
		double tmp = 0;
		rep(j,i+1) tmp += pow(0.9,i-j);
		ans = max(ans,dp[N-1][i]/tmp-1200/sqrt(i+1));
	}
	printf("%.10f\n", ans);


	return 0;
}