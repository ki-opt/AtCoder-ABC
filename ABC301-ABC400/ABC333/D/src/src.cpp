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

struct Node{
	int node, length;
};

int main() {
	int N;
	cin >> N;
	vector<int> u(N), v(N);
	vector<vector<int>> g(N);
	rep(i,N-1) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}

	vector<int> ans;
	for (auto i : g[0]) {
		int cnt = 1;
		queue<int> que;
		vector<bool> seen(N,false);
		seen[0] = true;
		que.push(i); seen[i] = true;
		while (!que.empty()) {
			int tmp = que.front(); que.pop();
			for (auto j : g[tmp]) {
				if (seen[j]) continue;				
				seen[j] = true;
				que.push(j);
				cnt++;
			}			
		}
		ans.push_back(cnt);
	}
	if (g[0].size() == 1) {
		cout << 1 << endl;
		return 0;
	}
	sort(ans.begin(),ans.end());
	int total = 0;
	rep(i,ans.size()-1) total += ans[i];
	cout << total+1 << endl;

	return 0;
}