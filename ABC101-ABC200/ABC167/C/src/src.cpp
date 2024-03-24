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
	ll N, M, X; cin >> N >> M >> X;
	vector<ll> C(N);
	vector<vector<ll>> A(N,vector<ll>(M));
	rep(i,N) {
		cin >> C[i];
		rep(j,M) cin >> A[i][j];
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i < (1 << N); i++) {
		vector<ll> x(M,0);
		ll cost = 0;
		rep(j,N) {
			if ((i >> j) & 0x1) {
				cost += C[j];
				rep(k,M) x[k] += A[j][k];
			}
		}
		bool isFound = true;
		rep(j,M) {
			if (x[j] < X) {
				isFound = false;
				break;
			}
		}
		if (isFound) ans = min(ans,cost);
	}
	if (ans == LLONG_MAX) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}