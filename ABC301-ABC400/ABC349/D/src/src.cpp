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
	ll L, R; cin >> L >> R;
	vector<pair<ll,ll>> ans;

	ll l = L;
	while (true) {
		ll left = (ll)pow(2,60);
		while (true) {
			if (l % left == 0) break;
			left /= 2;
		}
		if (left * (l / left + 1) > R) {
			left /= 2;
			while (left * (l / left + 1) > R) {
				left /= 2;	
			}
		}
		ans.push_back({l, left*(l/left+1)});
		l = left * (l / left + 1);
		if (l == R) break;
	}

	cout << ans.size() << endl;
	for (auto a : ans) {
		cout << a.first << " " << a.second << endl;
	}
	return 0;
}