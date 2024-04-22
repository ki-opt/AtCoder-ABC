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
	ll N, K; cin >> N >> K;
	vector<pair<ll,ll>> a(N);
	rep(i,N) {
		ll tmp;
		cin >> tmp;
		a[i] = {tmp,i};
	}

	sort(a.begin(),a.end());
	if (K % N == 0) {
		rep(i,N) cout << K / N << endl;
	} else if (K % N != 0) {
		vector<ll> ans(N,K/N);
		rep(i,K%N) {
			ans[a[i].second]++;
		}
		rep(i,N) {
			cout << ans[i] << endl;
		}
		
	}

	return 0;
}