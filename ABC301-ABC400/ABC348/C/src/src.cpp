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
	ll N; cin >> N;
	vector<ll> A(N), C(N);
	rep(i,N) cin >> A[i] >> C[i];

	map<ll,ll> mp;
	rep(i,N) {
		if (mp.count(C[i]) > 0) mp[C[i]] = min(mp[C[i]],A[i]);
		else mp[C[i]] = A[i];
	}

	ll ans = 0;
	for (auto m : mp) {
		ans = max(ans, m.second);
	}
	cout << ans << endl;

	return 0;
}