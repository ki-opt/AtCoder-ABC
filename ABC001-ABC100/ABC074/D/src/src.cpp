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
	ll N; cin >> N;
	vector<vector<ll>> A(N,vector<ll>(N));
	rep(i,N) rep(j,N) {
		if (i == j) A[i][j] = 1e15;
		cin >> A[i][j]; 
	}

	ll ans = 0;
	vector<vector<ll>> a = A;
	rep(i,N) {
		repp(j,i+1,N) {
			ll tmp = 1e15;	
			rep(k,N) {
				if (i != k && j != k) {
					tmp = min(tmp,a[i][k]+a[k][j]);
				}
			}			
			if (tmp < A[i][j]) {
				cout << -1 << endl;
				return 0;
			} else if (tmp > A[i][j]) {
				ans += A[i][j];
			}
		}
	}

	cout << ans << endl;

	return 0;
}