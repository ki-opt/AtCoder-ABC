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

ll ans = LLONG_MIN;

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> A(N), dp(N,LLONG_MAX);
	rep(i,N) { cin >> A[i]; }
	vector<pair<ll,ll>> pairs(M);
	rep(i,M) {
		ll x, y;
		cin >> x >> y; x--, y--;
		pairs[i] = {x,y};
	}
	sort(pairs.begin(),pairs.end());
	for (auto p : pairs) {
		dp[p.second] = min({dp[p.second],dp[p.first],A[p.first]});
	}
	rep(i,N) ans = max(ans,A[i]-dp[i]);
	cout << ans << endl;

	/*
	rep(i,N) {
		for (auto g : graph[i]) {
			dp[g] = min(dp[g],A[i]);
			ans = max(ans,A[g]-dp[i]);
		}
	}
	*/


	/*vector<pair<ll,ll>> pairs(M);
	rep(i,N) cin >> A[i];
	rep(i,M) {
		ll x, y;
		cin >> x >> y; x--, y--;
		graph[x].push_back(y);
		//pairs[i] = {x,y};
	}

	/*
	sort(pairs.begin(),pairs.end());

	vector<bool> seen(N,false);
	for (auto p : pairs) {
		if (p.first != 0) {
			seen[p.first] = true;
			dfs(p.second, seen, A[p.first]);
		}
	}
	cout << ans << endl;
	*/

	/*
	rep(i,N) {
		if (!seen[i]) {
			seen[i] = true;
			for (auto g : graph[i]) {
				ll min_val = A[i];
				dfs(i,seen,min_val);
			}
		}
	}
	*/

	return 0;
}