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
vector<vector<ll>> graph, rev;
vector<ll> A;

void dfs(ll n, vector<ll> &seen, ll min_val = 0) {
	ans = max(ans,A[n]-min_val);
	if (min_val >= seen[n]) return;
	min_val = min(min_val,A[n]);
	seen[n] = min_val;
	for (auto g : graph[n]) dfs(g, seen, min_val);
}

int main() {
	ll N, M; cin >> N >> M;
	A.resize(N), graph.resize(N), rev.resize(N);
	rep(i,N) cin >> A[i];
	rep(i,M) {
		ll x, y;
		cin >> x >> y; x--, y--;
		graph[x].push_back(y);
		rev[y].push_back(x);
	}

	vector<ll> seen(N,LLONG_MAX);
	rep(n,N) {
		if (rev[n].size() > 0) continue;
		for (auto g : graph[n]) {
			dfs(g,seen,A[n]);
		}
	}
	cout << ans << endl;


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