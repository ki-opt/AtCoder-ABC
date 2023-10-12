#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> dp(N+1,0);
	repp(i,1,N+1) { dp[i] = i; }
	rep(i,N+1) {
		for (int j = 1; (int)pow(6,j)<N+1; j++) {
			int tmp = (int)pow(6,j);
			for (int k = 1; i+k*tmp < N+1; k++) {
				dp[i+k*tmp] = min(dp[i+k*tmp],dp[i]+k);
			}
		}		
		for (int j = 1; (int)pow(9,j)<N+1; j++) {
			int tmp = (int)pow(9,j);
			for (int k = 1; i+k*tmp < N+1; k++) {
				dp[i+k*tmp] = min(dp[i+k*tmp],dp[i]+k);
			}
		}
	}
	cout << dp[N]; // << endl;
	return 0;
}