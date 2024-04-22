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

vector<ll> ans;

void dfs(ll node, vector<bool> &seen, vector<vector<ll>> &graph) {
	cout << node+1 << " ";
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		dfs(g, seen, graph);
		cout << node+1 << " ";
	}
}

int main() {
	ll N; cin >> N;
	vector<ll> A(N-1), B(N-1);
	vector<vector<ll>> graph(N);
	rep(i,N-1) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		graph[A[i]].push_back(B[i]);
		graph[B[i]].push_back(A[i]);
	}

	rep(i,N) sort(graph[i].begin(),graph[i].end());

	vector<bool> seen(N,false);
	seen[0] = true;
	dfs(0, seen, graph);
	
	return 0;
}