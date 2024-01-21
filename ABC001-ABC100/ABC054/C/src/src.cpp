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

struct Node{
	int v;
	vector<bool> seen;
	int num;
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	vector<vector<int>> g(N);
	rep(i,M) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	ll ans = 0;
	queue<Node> que;
	rep(i,g[0].size()) { 
		vector<bool> seen(N,false);
		seen[0] = true;
		seen[g[0][i]] = true;
		que.push({g[0][i],seen,1});
	}
	while(!que.empty()) {
		Node tmp = que.front(); que.pop();
		if (tmp.num + 1 == N) {
			ans++;
			continue;
		}
		for (auto next_v : g[tmp.v]) {
			if (!tmp.seen[next_v]) {
				vector<bool> seen_tmp = tmp.seen;
				seen_tmp[next_v] = true;
				que.push({next_v,seen_tmp,tmp.num+1});
			}
		}
	}
	cout << ans << endl;

	return 0;
}