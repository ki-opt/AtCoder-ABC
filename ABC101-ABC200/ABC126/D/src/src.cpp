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
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

struct Node{ll node, dist;};
vector<vector<Node>> graph;

void dfs(ll n, vector<ll> &color) {
	for (auto g : graph[n]) {
		if (color[g.node] != -1) continue; 
		if (g.dist % 2 == 0) color[g.node] = color[n];
		else color[g.node] = 1 - color[n];
		dfs(g.node,color);	
	}
}

int main() {
	ll N; cin >> N;
	graph.resize(N);
	rep(i,N-1) {
		ll u, v, w; cin >> u >> v >> w;
		u--; v--;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}

	vector<ll> color(N,-1);
	color[0] = 0;
	dfs(0,color);

	rep(i,N) cout << color[i] << endl;

	return 0;
}