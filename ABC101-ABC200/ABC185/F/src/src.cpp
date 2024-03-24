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
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

ll op(ll a, ll b) {
	return a ^ b;
}
ll e() {
	return (ll)0;
}

int main() {
	ll N, Q; cin >> N >> Q;
	vector<ll> A(N); rep(i,N) cin >> A[i];
	segtree<ll,op,e> seg(A);

	vector<ll> ans;
	rep(i,Q) {
		ll t, x, y;
		cin >> t >> x >> y;
		x--;
		if (t == 1) {
			ll v = seg.get(x);
			v ^= y;
			seg.set(x,v);
		} else if (t == 2) {
			ans.push_back(seg.prod(x,y));
		}
	}
	for (auto a : ans) cout << a << endl;

	return 0;
}