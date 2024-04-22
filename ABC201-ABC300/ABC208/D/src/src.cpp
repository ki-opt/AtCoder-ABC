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

struct Node{ ll node, cost; };

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> A(M), B(M), C(M);
	vector<vector<ll>> dist(N,vector<ll>(N,1e12));
	//rep(i,N) dist[i][i] = 0;
	rep(i,M) {
		cin >> A[i] >> B[i] >> C[i];
		A[i]--; B[i]--;
		dist[A[i]][B[i]] = C[i];
	}

	ll ans = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (dist[i][j] < (ll)1e12) ans += dist[i][j];
			}
		}
	}

	cout << ans << endl;

	return 0;
}