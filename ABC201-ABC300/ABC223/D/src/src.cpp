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
	vector<ll> C(N,0);
	vector<vector<ll>> graph(N);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		C[B[i]]++;
		graph[A[i]].push_back(B[i]);
	}

	priority_queue<ll,vector<ll>,greater<ll>> pque;
	rep(i,N) {
		if (C[i] == 0) {
			pque.push(i);
		}
	}

	vector<ll> ans;
	while (!pque.empty()) {
		ll tmp = pque.top(); pque.pop();
		ans.push_back(tmp);
		for (auto g : graph[tmp]) {
			C[g]--;
		}
		for (auto g : graph[tmp]) if (C[g] == 0) pque.push(g);
	}

	if (ans.size() != N) {
		cout << -1 << endl;
		return 0;
	} else {
		for (auto a : ans) {
			cout << a+1 << " ";
		}
	}



	return 0;
}