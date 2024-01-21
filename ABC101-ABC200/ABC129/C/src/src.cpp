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
	int N, M;
	cin >> N >> M;
	vector<int> a(M);
	unordered_map<int,int> umap;
	rep(i,M) {
		cin >> a[i];
		umap[a[i]]++;
	}

	ll ans = 0;
	/*vector<vector<ll>> dp(N+1,vector<ll>(2,0));
	if (umap.count(1) == 0) dp[1][0] = 1;
	if (umap.count(2) == 0) dp[2][1] = 1;
	repp(i,1,N) {
		if (dp[i][0] != 0) { 
			if (umap.count(i+1) == 0) dp[i+1][0] += dp[i][0];
			if (i+2 <= N && umap.count(i+2) == 0) dp[i+2][1] += dp[i][0] + 1;
		}
		if (dp[i][1] != 0) {
			if (umap.count(i+1) == 0) dp[i+1][0] += dp[i][1] + 1;
			if (i+2 <= N && umap.count(i+2) == 0) dp[i+2][1] += dp[i][1];
		}
	}
	cout << dp[N][0] + dp[N][1] << endl;*/
	vector<ll> dp(N+1,0);
	if (umap.count(1) == 0) dp[1] = 1;
	if (umap.count(2) == 0) dp[2] = 1;
	repp(i,1,N) {
		if (i != 0 && dp[i] == 0) continue;
		if (umap.count(i+1) == 0) dp[i+1] = (dp[i+1] + dp[i]) % 1000000007;
		if (i+2 <= N && umap.count(i+2) == 0) dp[i+2] = (dp[i+2] + dp[i]) % 1000000007;
	}
	cout << dp[N] << endl;

	return 0;
}