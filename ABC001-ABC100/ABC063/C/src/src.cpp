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
	int N;
	cin >> N;
	vector<int> s(N);
	rep(i,N) cin >> s[i];

	/*
	int sum = 0;
	rep(i,N) sum += s[i];

	if (sum % 10 != 0) {
		cout << sum << endl;
		return 0;
	}	sort(s.begin(),s.end());
	*/
	
	vector<vector<int>> dp(N+1,vector<int>(100*100+1,0));
	int max_val = 0;
	repp(i,N+1,1) {
		rep(j,100*100+1) {
			if (j < s[i-1]) dp[i][j] = dp[i-1][j];
			else {
				int tmp = max(dp[i-1][j-s[i-1]]+s[i-1],dp[i-1][j]);
				dp[i][j] = tmp;
				if (dp[i][j] % 10 != 0 && dp[i][j] > max_val) max_val = dp[i][j];
			}
		}
	}
	cout << max_val << endl;

	/*
	vector<int> dp(N+1);
	dp[0] = 0;
	repp(i,N+1,1) {
		if ((dp[i-1] + s[i-1]) % 10 == 0) dp[i] = dp[i-1];
		else dp[i] += dp[i-1] + s[i-1];
	}*/


	return 0;
}