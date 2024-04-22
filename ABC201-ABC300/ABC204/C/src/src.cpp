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

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> A(M), B(M);
	vector<vector<ll>> graph(N);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		graph[A[i]].push_back(B[i]);
	}

	ll ans = 0;
	rep(i,N) {
		queue<ll> que;
		vector<bool> seen(N,false);
		que.push(i); seen[i] = true;
		ans++;
		while (!que.empty()) {
			ll tmp = que.front(); que.pop();
			for (auto &g : graph[tmp]) {
				if (seen[g]) continue;
				seen[g] = true;
				que.push(g);
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}