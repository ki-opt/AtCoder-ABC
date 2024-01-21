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

struct Node{
	int next, cost, edge;
};

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M), c(M);
	vector<vector<Node>> g(N);
	rep(i,M) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		g[a[i]].push_back({b[i],c[i],i});
		g[b[i]].push_back({a[i],c[i],i});
	}
	
	vector<bool> check(M,false); 
	rep(i,N) {
		queue<Node> que;
		vector<bool> used_edge(M,false);
		vector<pair<int,int>> cost(N,{INT_MAX,-1});
		cost[i] = { 0, -1 };
		for (auto n : g[i]) {
			que.push(n);
			cost[n.next] = { n.cost,n.edge };
			used_edge[n.edge] = true;
		}
		while (!que.empty()) {
			Node tmp = que.front(); que.pop();
			for (auto n : g[tmp.next]) {
				if (cost[n.next].first <= cost[tmp.next].first + n.cost) continue;
				que.push(n);
				if (cost[n.next].first != INT_MAX) used_edge[cost[n.next].second] = false;
				used_edge[n.edge] = true;
				cost[n.next] = { cost[tmp.next].first+n.cost, n.edge };
			}
		}
		rep(j,M) if (used_edge[j]) check[j] = true;
	}
	
	int ans = 0;
	rep(i,M) if (!check[i]) ans++;

	cout << ans << endl;	
	return 0;
}