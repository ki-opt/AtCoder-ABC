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
	ll N, M; cin >> N >> M;
	vector<ll> A(M), B(M);
	vector<vector<ll>> graph(N);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		graph[A[i]].push_back(B[i]);
		graph[B[i]].push_back(A[i]);
	}

	vector<ll> seen(N,-1);
	vector<mint> num(N,0);
	queue<pair<ll,ll>> que;
	que.push({0,0}); seen[0] = 0; num[0] = 1;
	while (!que.empty()) {
		pair<ll,ll> pairs = que.front(); que.pop();
		for (auto g : graph[pairs.first]) {
			if (pairs.second + 1 == seen[g] || seen[g] == -1) {
				num[g] += num[pairs.first];
				if (seen[g] == -1) que.push({g, pairs.second + 1});
				seen[g] = pairs.second + 1;
			}
		}
	}
	cout << num[N-1].val() << endl;

	return 0;
}