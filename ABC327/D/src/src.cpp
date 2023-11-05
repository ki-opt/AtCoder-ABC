#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

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
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	vector<vector<int>> g(N);
	rep(i,M) { cin >> A[i]; A[i]--; }
	rep(i,M) { cin >> B[i]; B[i]--; }
	rep(i,M) {
		//if (A[i] == B[i]) {cout << "No" << endl; return 0;}
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}

	UnionFind uf(N*2);
	rep(i,M) {
		uf.unite(A[i],N+B[i]);
		uf.unite(A[i]+N,B[i]);
	}

	rep(i,N) {
		if (uf.issame(i,i+N)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	/*
	UnionFind uf(N+1);
	rep(i,M) {
		if (A[i] != ) uf.unite(A[i],B[i]);
	}

	rep(i,M) {
		if (uf.root(A[i]) == uf.root(B[i])) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;*/

	/*
	vector<int> X(N+1,-1);
	rep(i,M) {
		if (X[A[i]] == -1 && X[B[i]] == -1) {
			X[A[i]] = 0; X[B[i]] = 1;
		} else if (X[A[i]] == -1 && X[B[i]] != -1) {
			X[A[i]] = 1 - X[B[i]];
		} else if (X[A[i]] != -1 && X[B[i]] == -1) {
			X[B[i]] = 1 - X[A[i]];
		} else {
			if (X[A[i]] == X[B[i]]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	//*/

	/*vector<int> a(N+1,0), b(N+1,0);
	rep(i,M) {
		a[A[i]]++; b[B[i]]++;
	}*/

	return 0;
}