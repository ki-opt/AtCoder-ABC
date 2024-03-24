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


map<ll,ll,greater<ll>> op(map<ll,ll,greater<ll>> a, map<ll,ll,greater<ll>> b) {
	map<ll,ll,greater<ll>> tmp;
	for (auto &m : a) tmp[m.first] += m.second;
	for (auto &m : b) tmp[m.first] += m.second;
	map<ll,ll,greater<ll>> ret;
	auto itr = tmp.begin();
	ret[itr->first] += itr->second;
	itr++;
	if (tmp.size() >= 2) ret[itr->first] += itr->second;
	return ret;
}
map<ll,ll,greater<ll>> e() {
	return {{0,0}};
}

int main() {
	ll N, Q; cin >> N >> Q;
	vector<ll> A(N);
	vector<map<ll,ll,greater<ll>>> vec(N);
	rep(i,N) { cin >> A[i]; vec[i][A[i]]++; }

	segtree<map<ll,ll,greater<ll>>,op,e> seg(vec);

	vector<ll> ans;
	rep(i,Q) {
		int q; cin >> q;
		if (q == 1) {
			ll p, x; cin >> p >> x; p--;
			seg.set(p,{{x,1}});
		} else if (q == 2) {
			ll l, r; cin >> l >> r; l--;
			map<ll,ll,greater<ll>> tmp = seg.prod(l,r);
			auto itr = tmp.begin();
			if (itr->first == 0) {
				ans.push_back(0);
			} else {
				itr++;
				if (itr->first == 0) ans.push_back(0);
				else ans.push_back(itr->second);
			}
		}
	}

	for (auto a : ans) cout << a << endl;
	return 0;
}