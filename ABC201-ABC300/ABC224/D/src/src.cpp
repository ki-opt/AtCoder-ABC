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

struct Node {
	int val;
	int cnt;
	int empty;
	vector<int> ans;
};
bool operator<(const Node &node1, const Node & node2) {
	return node1.val < node2.val;
}

int check(vector<int> &ans) {
	int val = 0;
	rep(i,8) if (ans[i] == i) val++;
	return val;
}

int main() {
	int M; cin >> M;
	vector<vector<int>> graph(9);
	rep(i,M) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> ans(9,-1);
	rep(i,8) {
		int p; cin >> p;
		p--;
		ans[p] = i;
	}

	int empty_node = -1;
	rep(i,9) if (ans[i] == -1) empty_node = i;

	queue<Node> pque;
	map<vector<int>,int> mp;
	pque.push({check(ans),0,empty_node,ans});
	mp[ans]++;
	while(!pque.empty()) {
		Node node = pque.front(); pque.pop();
		if (node.val >= 8) {
			cout << node.cnt << endl;
			return 0;
		}
		for (auto &g : graph[node.empty]) {
			swap(node.ans[node.empty],node.ans[g]);
			if (mp.count(node.ans) == 0) {
				pque.push({check(node.ans),node.cnt+1,g,node.ans});
				mp[node.ans]++;
			}
			swap(node.ans[node.empty],node.ans[g]);
		}		
	}
	cout << -1 << endl;

	return 0;
}