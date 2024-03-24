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

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)


//*
int main() {
	int N; cin >> N;
	vector<int> a(N-1), b(N-1), edge(N-1);
	vector<vector<pair<int,int>>> g(N);
	rep(i,N-1) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		g[a[i]].push_back({b[i],i});
		g[b[i]].push_back({a[i],i});
	}

	auto dfs = [&](auto dfs, int curr, int parr, int col) -> void {
		set<int> used;
		used.insert(col);
		int c = 1;
		for (auto e : g[curr]) {
			if (e.first == parr) continue;
			while (used.count(c)) c++;
			edge[e.second] = c;
			dfs(dfs, e.first, curr, c);
			c++;
		}
	};
	dfs(dfs,0,-1,0);
	cout << *max_element(edge.begin(),edge.end()) << endl;
	rep(i,N-1) cout << edge[i] << endl;

	return 0;
}
//*/
/*
int N;
vector<pair<int,int>> E[101010];
//---------------------------------------------------------------------------------------------------
int ans[101010];
void dfs(int cu, int pa = -1, int col = 0) {
	set<int> used;
	used.insert(col);
	int c = 1;
	for(auto to : E[cu]) if (to.first != pa) {
		while (used.count(c)) c++;
		ans[to.second] = c;
		dfs(to.first, cu, c);
		c++;
	}
}
//---------------------------------------------------------------------------------------------------
int main() {
	cin >> N;
	repp(i, 0, N - 1) {
		int a, b; cin >> a >> b;
		a--; b--;

		E[a].push_back({ b, i });
		E[b].push_back({ a, i });
	}

	dfs(0);

	int ma = 0;
	repp(i, 0, N) ma = max(ma, (int)E[i].size());
	printf("%d\n", ma);
	repp(i, 0, N - 1) printf("%d\n", ans[i]);
	return 0;
}
//*/