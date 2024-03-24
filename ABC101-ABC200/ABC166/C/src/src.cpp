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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> H(N);
	rep(i,N) cin >> H[i];
	vector<ll> A(M), B(M);
	vector<vector<ll>> g(N);
	rep(i,M) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}

	ll ans = N;
	rep(i,N) {
		for (auto n : g[i]) {
			if (H[i] <= H[n]) {
				ans--;
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}