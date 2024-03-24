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
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> L(K), R(K);
	set<ll> S;
	rep(i,K) {
		cin >> L[i] >> R[i];
		repp(j,L[i],R[i]+1) S.insert(j);
	}

	vector<mint> dp(N+1,0), sdp(N+1,0);
	dp[1] = 1; sdp[1] = 1;
	repp(i,2,N+1) {
		mint tmp = 0;
		rep(j,K) {
			if (i-L[j] >= 0) tmp += sdp[i-L[j]];
			if (i-R[j]-1 >= 0) tmp -= sdp[i-R[j]-1];
		}
		dp[i] = tmp;
		sdp[i] = sdp[i-1] + dp[i];
	}
	cout << dp[N].val() << endl;

	/*
	vector<mint> dp(N+1,0); dp[1] = 1;
	repp(i,1,N+1) {
		if (dp[i] == 0) continue;
		for (auto s : S) {
			if (i + s > N) break;
			dp[i+s] += dp[i];
		}
	}
	cout << dp[N].val() << endl;
	*/
	return 0;
}