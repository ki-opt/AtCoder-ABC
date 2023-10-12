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

void dfs(const int &before_node, const int &next_node, vector<ll> &ans, 
			vector<ll> &val, vector<vector<int>> &node) {
	ans[next_node] = ans[before_node] + val[next_node];
	rep(i,node[next_node].size()) {
		if (before_node == node[next_node][i]) continue;
		dfs(next_node,node[next_node][i],ans,val,node);
		//ans[all_node[before_node][i]] = val[all_node[before_node][i]] + ans[before_node];	
		/*rep(j,all_node[all_node[before_node][i]].size()) {
			ans[all_node[before_node][j]] = val[all_node[before_node][j]] + ans[all_node[all_node[before_node][i]][j]];
			dfs(all_node[all_node[before_node][i]][j], ans, val, all_node);
		}*/
	}
}

int main() {
	ll N, Q;
	cin >> N >> Q;
	vector<ll> a(N-1), b(N-1), p(Q), x(Q);
	vector<vector<int>> node(N+1,vector<int>());
	rep(i,N-1) {
		cin >> a[i] >> b[i];
		node[a[i]].push_back(b[i]);
		node[b[i]].push_back(a[i]);
	}
	vector<ll> val(N+1,0);
	rep(i,Q) {
		cin >> p[i] >> x[i];
		val[p[i]] += x[i];
	}

	vector<ll> ans(N+1,0);
	ans[1] = val[1];
	rep(i,node[1].size()) {
		dfs(1, node[1][i], ans, val, node);
	}
	repp(i,1,N+1) cout << ans[i] << " ";

	return 0;
}