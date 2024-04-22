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
	ll Q; cin >> Q;

	map<ll,ll> mp;
	ll add = 0;
	vector<ll> ans;
	rep(q,Q) {
		ll query, x;
		cin >> query;
		if (query == 1) {
			cin >> x;
			mp[x - add]++;
		} else if (query == 2) {
			cin >> x;
			add += x;
		} else {
			ans.push_back(mp.begin()->first + add);
			mp.begin()->second--;
			if(mp.begin()->second == 0) mp.erase(mp.begin()->first);
		}
	}

	for (auto a : ans) cout << a << endl;
	return 0;
}