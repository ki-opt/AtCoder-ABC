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

vector<int> ans;
vector<int> C;

void dfs(vector<bool> &seen, vector<vector<int>> &graph, vector<int> &color, int node) {
	if (color[C[node]] == 0) ans.push_back(node);
	color[C[node]]++;
	for (auto g : graph[node]) {
		if (seen[g]) continue;
		seen[g] = true;
		dfs(seen,graph,color,g);
	}
	color[C[node]]--;
}

int main() {
	int N; cin >> N;
	C.resize(N); rep(i,N) cin >> C[i];
	vector<vector<int>> graph(N);
	rep(i,N-1) {
		int a, b; cin >> a >> b;
		a--; b--;
		graph[a].push_back(b); graph[b].push_back(a);
	}

	vector<bool> seen(N,false); seen[0] = true;
	vector<int> color(100001,0);
	dfs(seen,graph,color,0);

	sort(ans.begin(),ans.end());
	for (auto a : ans) {
		cout << a+1 << endl;
	}

	/*
	vector<int> ans = {0};
	queue<pair<int,unordered_map<int,int>>> que;
	vector<bool> seen(N,false);
	que.push({0,{{C[0],1}}}); seen[0] = true;
	while (!que.empty()) {
		pair<int,unordered_map<int,int>> tmp = que.front(); que.pop();
		for (auto g : graph[tmp.first]) {
			if (seen[g]) continue;
			if (tmp.second.count(C[g]) == 0) ans.push_back(g);
			tmp.second[C[g]]++;
			seen[g] = true;
			que.push({g,tmp.second});
			tmp.second[C[g]]--;
			if (tmp.second[C[g]] == 0) tmp.second.erase(C[g]);
		}
	}
	*/

	return 0;
}