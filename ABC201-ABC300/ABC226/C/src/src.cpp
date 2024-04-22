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

vector<ll> T, K;
vector<vector<ll>> A;

ll dfs(ll a, vector<bool> &seen) {
	if (seen[a]) return 0;
	seen[a] = true;
	ll tmp = 0;
	rep(j,K[a]) {
		if (seen[A[a][j]]) continue;
		tmp += dfs(A[a][j],seen);
	}
	return tmp + T[a];
}

int main() {
	ll N; cin >> N;
	T.resize(N); K.resize(N);
	A.resize(N);
	rep(i,N) {
		cin >> T[i] >> K[i];
		A[i].resize(K[i]);
		rep(j,K[i]) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	vector<bool> seen(N,false);
	ll ans = T[N-1];
	rep(j,K[N-1]) {
		ans += dfs(A[N-1][j],seen);
	}
	cout << ans << endl;

	/*
	vector<ll> t(N,0);
	rep(i,N) {
		t[i] += T[i];
		rep(j,K[i]) {
			t[i] += t[A[i][j]];
		}
	}
	*/

	return 0;
}