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

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

class UnionFind {
public:
	vector<ll> par, siz;
	// initialize
	UnionFind(ll n) : par(n,-1), siz(n,1) {}

	// 根を求める
	ll root(ll x) {
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	// 同じグループかどうかの判定
	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	// xを含むグループとyを含むグループの併合
	bool unite(ll x, ll y) {
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
	ll size(ll x) {
		return siz[root(x)];
	}
};

/*
struct Node {
	ll next, w;
};

struct UF {
	ll node;
	UnionFind uf;
	ll w;
};
void DFS(const vector<vector<Node>> &g,
			UF uf_comb) {
	if (uf_comb.uf.size(0) == N+1) {
		ans = min(ans, uf_comb.w%K);
		return;
	}
	for (auto node : g[uf_comb.node]) {
		if (uf_comb.uf.issame(uf_comb.node,node.next)) continue;
		UnionFind uf_ = uf_comb.uf;
		uf_.unite(uf_comb.node, node.next);
		DFS(g,{uf_comb.node,uf_,uf_comb.w+node.w});
	}
}
*/

// 次のコンビネーションを生成する関数
bool next_combination(vector<int> &combination, int n, int k) {
	for (int i = k - 1; i >= 0; --i) {
		if (combination[i] < n - k + i) {
			++combination[i];
			for (int j = i + 1; j < k; ++j) {
					combination[j] = combination[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}

int main() {
	ll N, M, K;
	ll ans = LLONG_MAX;
	cin >> N >> M >> K;
	//vector<vector<Node>> g(N);
	vector<vector<ll>> g_adj(N,vector<ll>(N,-1));
	vector<int> x(M), y(M);
	rep(i,M) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		x[i] = u; y[i] = v;
		//g[u].push_back({v,w});
		//g[v].push_back({u,w});
		g_adj[u][v] = w;
		g_adj[v][u] = w;
	}

	// コンビネーションを列挙
	vector<int> combination(M);
	rep(i,M) { combination[i] = i; }
	do {
		ll weight = 0;
		UnionFind uf(N);
		rep(i,N-1) {
			int bef = x[combination[i]], next = y[combination[i]];
			if (g_adj[bef][next] == -1 || uf.issame(bef,next)) { 
				continue;
			}
			uf.unite(bef,next);
			weight += g_adj[bef][next];
		}
		if (uf.size(0) == N) ans = min(ans,weight%K);
	} while (next_combination(combination, M, N-1));
	cout << ans << endl;

	/*
	UnionFind uf(N);
	DFS(g,{0,uf,0});
	*/

	/*
	stack<UF> st;
	for (auto n : g[0]) {
		UnionFind uf(N);
		uf.unite(0,n.next);
		st.push({n.next,uf,n.w});
	}
	ll ans = LLONG_MAX;
	while (!st.empty()) {
		UF tmp = st.top(); st.pop();
		if (tmp.uf.size(0) == N) {
			ans = min(ans,tmp.w%K);
			continue;
		}
		for (auto n : g[tmp.node]) {
			if (tmp.uf.issame(tmp.node,n.next)) continue;
			UnionFind uf_ = tmp.uf;
			uf_.unite(tmp.node,n.next);
			st.push({n.next,uf_,tmp.w+n.w});
		}
	}
	*/

	/*
	vector<int> tmp(N);
	rep(i,N) tmp[i] = i;
	ll ans = LLONG_MAX;
	do {
				
	} while(next_permutation(tmp.begin(),tmp.end()));
	*/


	/*
	stack<UF> que;
	for (auto n : g[0]) {		
		UnionFind uf(N);
		uf.unite(0,n.next);
		que.push({n.next,uf,n.w});
	}
	ll ans = LLONG_MAX;
	while (!que.empty()) {
		UF tmp = que.front(); que.pop();
		if (tmp.uf.size(0) == N) {
			ans = min(ans,tmp.w%K);
			continue;
		}
		for (auto n : g[tmp.node]) {
			if (tmp.uf.issame(tmp.node,n.next)) continue;
			UnionFind uf_ = tmp.uf;
			uf_.unite(tmp.node,n.next);
			que.push({n.next,uf_,tmp.w+n.w});
		}
	}
	*/

	return 0;
}