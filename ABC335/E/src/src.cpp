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


class UnionFind {
public:
	vector<int> par, siz;
	// initialize
	UnionFind(int n) : par(n,-1), siz(n,1) {}

	// 根を求める
	int root(int x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	// 同じグループかどうかの判定
	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	// xを含むグループとyを含むグループの併合
	bool unite(int x, int y) {
		// x, yでそれぞれ根まで移動
		x = root(x); y = root(y);
		// 同じグループの場合終了
		if (x == y) return false;

		// union by size
		if (siz[x] < siz[y]) swap(x, y);

		// yをxの子にする
		par[y] = x;
		siz[x] += siz[y];
		return true;
	}
	
	// xを含むグループのサイズ
	int size(int x) {
		return siz[root(x)];
	}
};

int main() {
	int N, M; cin >> N >> M;
	vector<int> A(N), U(M), V(M);
	rep(i,N) cin >> A[i];

	vector<vector<pair<int,int>>> g(200001);
	UnionFind uf(N);
	rep(i,M) {
		cin >> U[i] >> V[i];
		U[i]--; V[i]--;
		if (A[U[i]] < A[V[i]]) g[A[U[i]]].push_back({U[i],V[i]});
		else if (A[U[i]] > A[V[i]]) g[A[V[i]]].push_back({V[i],U[i]});
		else uf.unite(U[i],V[i]);
	}

	vector<int> dp(200001,0);
	dp[uf.root(0)] = 1;
	for (auto next : g) {
		for (auto [u,v] : next) {
			u = uf.root(u);
			v = uf.root(v);
			if (dp[u] > 0) dp[v] = max(dp[v],dp[u]+1);
		}
	}
	cout << dp[uf.root(N-1)] << endl;



	/*
	vector<int> cost(N,0);
	queue<int> que;
	cost[0] = 1;
	for (auto n : g[0]) {
		if (A[n] <= A[0]) continue;
		que.push(n);
		cost[n] = 2;
	}
	while (!que.empty()) {
		int tmp = que.front(); que.pop();
		for (auto n : g[tmp]) {
			if (A[n] <= A[tmp]) continue;
			if (cost[n] >= cost[tmp] + 1) continue;
			que.push(n);
			cost[n] = cost[tmp] + 1;
		}
	}

	int ans = cost[N-1];
	cout << ans << endl;
	*/

	return 0;
}