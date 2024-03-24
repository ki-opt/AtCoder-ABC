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
	int N, M, K; cin >> N >> M >> K;
	vector<int> A(M), B(M), C(K), D(K);
	vector<vector<int>> f(N), b(N);
	UnionFind uf(N);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		f[A[i]].push_back(B[i]);
		f[B[i]].push_back(A[i]);
		uf.unite(A[i],B[i]);
	}
	rep(i,K) {
		cin >> C[i] >> D[i];
		C[i]--; D[i]--;
		b[C[i]].push_back(D[i]);
		b[D[i]].push_back(C[i]);
	}

	vector<int> ans(N);
	rep(i,N) ans[i] = uf.size(i) - f[i].size() - 1;
	rep(i,K) {
		if (uf.issame(C[i],D[i])) {
			ans[C[i]]--; ans[D[i]]--;
		}
	}
	for (auto a : ans) cout << a << " ";
	cout << endl;

	/* ans - 1
	rep(i,N) {
		int ans = uf.size(i) - f[i].size() - 1;
		for (auto b_ : b[i]) {
			if (uf.issame(i,b_)) ans--;
		}
		cout << ans << " ";
	}
	cout << endl;
	*/
	return 0;
}