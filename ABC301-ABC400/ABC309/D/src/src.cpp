#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

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
	int N1, N2, M;
	cin >> N1 >> N2 >> M;
	vector<int> a(M), b(M);
	vector<vector<int>> rinsetu(N1+N2+1);
	rep(i,M) {
		cin >> a[i] >> b[i];
		rinsetu[a[i]].push_back(b[i]);
		rinsetu[b[i]].push_back(a[i]);
	}

	int depth_N1 = 0;
	queue<pair<int,int>> que;
	vector<bool> check(N1+1,false);
	check[1] = true;
	rep(i,rinsetu[1].size()) { que.push({rinsetu[1][i],1}); check[rinsetu[1][i]] = true; }
	while(que.empty() == false) {
		pair<int,int> next = que.front(); que.pop();
		if (next.second > depth_N1) depth_N1 = next.second;
		rep(i,rinsetu[next.first].size()) {
			if (check[rinsetu[next.first][i]] == false) {
				que.push({rinsetu[next.first][i],next.second+1});
				check[rinsetu[next.first][i]] = true;
			}
		}
	}
	
	int depth_N2 = 0;
	vector<bool> check2(N1+N2+1,false);
	check2[N1+N2] = true;
	rep(i,rinsetu[N1+N2].size()) { que.push({rinsetu[N1+N2][i],1}); check2[rinsetu[N1+N2][i]] = true; }
	while(que.empty() == false) {
		pair<int,int> next = que.front(); que.pop();
		if (next.second > depth_N2) depth_N2 = next.second;
		rep(i,rinsetu[next.first].size()) {
			if (check2[rinsetu[next.first][i]] == false) {
				que.push({rinsetu[next.first][i],next.second+1});
				check2[rinsetu[next.first][i]] = true;
			}
		}
	}

	cout << depth_N1 + depth_N2 + 1 << endl;
	cerr << depth_N1 << " " << depth_N2 << endl;
	return 0;
}