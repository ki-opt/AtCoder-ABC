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

struct comp{
	bool operator()(pair<ll,ll> &left, pair<ll,ll> &right) const {
		if (left.second == right.second) return left.first > right.first;
		else return left.second > right.second;
	}
};

int main() {
	ll N; cin >> N;
	vector<ll> A(N-1), B(N-1), X(N-1);
	vector<vector<pair<ll,ll>>> g(N);
	rep(i,N-1) {
		cin >> A[i] >> B[i] >> X[i];
		X[i]--;
		g[i].push_back({i+1,A[i]});
		g[i].push_back({X[i],B[i]});
	}

	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, comp> que;
	vector<ll> seen(N,LLONG_MAX);
	que.push({0,0}); seen[0] = 0;
	ll ans = LLONG_MAX;
	while (!que.empty()) {
		pair<ll,ll> tmp = que.top(); que.pop();
		if (tmp.second > seen[tmp.first]) continue;
		for (auto n : g[tmp.first]) {
			if (tmp.second + n.second >= seen[n.first]) continue;
			que.push({n.first, tmp.second + n.second});
			seen[n.first] = tmp.second + n.second;
		}
	}
	cout << seen[N-1] << endl;

	/*
	ll ans = 0;
	vector<ll> dp(N,LLONG_MAX);
	rep(i,N-1) {
		dp[i+1] = min(dp[i+1],dp[i]+A[i]);
		dp[X[i]] = min(dp[i]+B[i],dp[X[i]]);
	}
	cout << dp[N-1] << endl;
	*/
	return 0;
}