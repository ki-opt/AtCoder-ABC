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

struct Edge{
	int a, b; ll c;
	bool operator<(const Edge &another) const {
		return c < another.c;
	}
};

int main() {
	int N, M; cin >> N >> M;
	vector<Edge> edge;
	rep(i,M) {
		int a, b; ll c;
		cin >> a >> b >> c;
		a--; b--;
		edge.push_back({a,b,c});
	}

	sort(edge.begin(),edge.end());
	UnionFind uf(N);
	ll ans = 0;
	rep(i,M) {
		if (uf.issame(edge[i].a,edge[i].b)) {
			if (edge[i].c >= 0) ans += edge[i].c;
			continue;
		}
		uf.unite(edge[i].a,edge[i].b);
	}
	cout << ans << endl;
	return 0;
}