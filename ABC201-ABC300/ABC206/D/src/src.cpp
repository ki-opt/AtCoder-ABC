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

int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	
	
	vector<ll> a(200001);
	rep(i,N) a[A[i]] = A[i];

	ll ans = 0;
	rep(i,N/2) {
		if (a[A[i]] == a[A[N-1-i]] || A[i] == A[N-1-i]) continue;
		a[A[i]] = -1, a[A[N-1-i]] = -1;
		ans++;
	}
	cout << ans << endl;
	/*
	UnionFind uf(200001);

	ll ans = 0;
	rep(i,N/2) {
		if (uf.issame(A[i],A[N-1-i])) continue;
		uf.unite(A[i],A[N-1-i]);
		ans++;
	}
	cout << ans << endl;
	*/
	/*
	vector<bool> seen(200001,false);
	vector<ll> a(200001,-1);
	rep(i,N) a[A[i]] = A[i];

	ll ans = 0;
	rep(i,N/2) {
		if (a[A[i]] == a[A[N-1-i]]) continue;
		if (seen[A[i]]) {
			a[A[N-1-i]] = A[i];
		} else {
			a[A[i]] = A[N-1-i];
		}
		seen[A[N-1-i]] = true;
		seen[A[i]] = true;
		ans++;
	}
	cout << ans << endl;

	/*
	vector<vector<ll>> a(200001);
	rep(i,N) a[A[i]].push_back(i);

	ll ans = 0;
	rep(i,N/2) {
		if (A[i] == A[N-i-1]) continue;
		ans++;
		for (auto a_index : a[A[i]]) {
			A[a_index] = A[N-i-1];
			a[A[N-i-1]].push_back(a_index);
		}
		a[A[i]].erase(a[A[i]].begin(),a[A[i]].end());
	}
	cout << ans << endl;
	*/
	/*
	vector<ll> a(200001,-1);
	rep(i,N) a[A[i]] = A[i];
	
	ll ans = 0;
	rep(i,N/2) {
		if (a[A[i]] == a[A[N-1-i]]) continue;
		a[A[i]] = A[N-1-i];
		ans++;
	}

	/*
	rep(i,N) a[A[i]] = A[i];	
	ll ans2 = 0;
	rep(i,N/2) {
		if (a[A[i]] == a[A[N-1-i]]) continue;
		a[A[N-1-i]] = A[i];
		ans2++;
	}
	cout << min(ans,ans2) << endl;
	*/
	/*
	if (N % 2 == 0) {
		rep(i,N/2) {

		}
	} else if (N % 2 == 1) {
		rep(i,N/2) {
			
		}
	}
	*/

	return 0;
}