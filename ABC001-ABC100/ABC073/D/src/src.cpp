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
#include <numeric>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node {
	ll next, weight;
};

int main() {
	ll N, M, R; cin >> N >> M >> R;
	vector<ll> r(R);
	//unordered_map<ll,ll> umap;
	rep(i,R) {
		cin >> r[i];
		r[i]--;
		//umap[r[i]]++;
	}
	vector<vector<ll>> graph(N,vector<ll>(N,LLONG_MAX));
	rep(i,M) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	rep(i,N) graph[i][i] = 0;

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][k] < LLONG_MAX && graph[k][j] < LLONG_MAX) {
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}

	ll ans = LLONG_MAX;
	sort(r.begin(),r.end());
	do {
		ll root_length = 0;
		rep(i,R-1) root_length += graph[r[i]][r[i+1]];
		ans = min(ans,root_length);
	} while (next_permutation(r.begin(),r.end()));
	cout << ans << endl;
	/*
	vector<vector<Node>> graph(N);
	rep(i,M) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}

	ll ans = LLONG_MAX;
	do {
		ll root_length = 0;
		for (int r_dash = 0; r_dash < R-1; r_dash++) {
			priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pque;
			pque.push({0,r[r_dash]});
			vector<pair<ll,ll>> seen(N,{-1,-1}); seen[r[r_dash]] = {0,-1};
			while (!pque.empty()) {
				pair<ll,ll> node = pque.top(); pque.pop();
				if (node.first > seen[node.second].first) continue;
				if (node.second == r[r_dash+1]) break;
				for (auto &g : graph[node.second]) {
					if (seen[g.next].first == -1 || node.first + g.weight <= seen[g.next].first) {
						seen[g.next] = {node.first + g.weight, node.second};
						pque.push({seen[g.next].first,g.next});
					} 
				}
			}
			root_length += seen[r[r_dash+1]].first;
		}
	ans = min(ans,root_length);
	} while (next_permutation(r.begin(),r.end()));
	cout << ans << endl;
	*/
	/* 
	ll ans = LLONG_MAX;
	for (auto r_dash : r) {
		priority_queue<pair<ll,ll>> pque;
		vector<ll> seen(N,-1);
		pque.push({0,r_dash}); seen[r_dash] = 0;
		while (!pque.empty()) {
			pair<ll,ll> node = pque.top(); pque.pop();
			for (auto &g : graph[node.second]) {
				if (seen[g.next] == -1 || node.first + g.weight < seen[g.next]) {
					seen[g.next] = node.first + g.weight;
					pque.push({seen[g.next],g.next});
				} 
			}
		}
		ll tmp_max = 0;
		for (auto s : r) {
			tmp_max = max(tmp_max,seen[s]);
		}
		ans = min(ans,tmp_max);
	}
	cout << ans << endl;
	*/

	return 0;
}