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
using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, Q; cin >> N >> Q;
	vector<vector<ll>> graph(N);
	rep(i,N-1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<ll> que;
	vector<ll> seen(N,-1);
	que.push(0); seen[0] = 1;
	while (!que.empty()) {
		ll tmp = que.front(); que.pop();
		for (auto g : graph[tmp]) {
			if (seen[g] == -1) {
				seen[g] = seen[tmp]+1;
				que.push(g);
			}
		}
	}

	rep(q,Q) {
		ll c, d; cin >> c >> d;
		c--; d--;
		if (abs(seen[c]-seen[d]) % 2 == 0) {
			cout << "Town" << endl;
		} else {
			cout << "Road" << endl;
		}
	}

	return 0;
}