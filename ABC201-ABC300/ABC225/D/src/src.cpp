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
	ll N, Q; cin >> N >> Q;
	
	vector<vector<ll>> ans;
	vector<pair<ll,ll>> train(N,{-1,-1});
	rep(q,Q) {
		ll query, x, y; cin >> query;
		if (query == 1) {
			cin >> x >> y;
			x--; y--;
			train[x].second = y;
			train[y].first = x;
		} else if (query == 2) {
			cin >> x >> y;
			x--; y--;
			train[x].second = -1;
			train[y].first = -1;
		} else {
			cin >> x;
			x--;
			ans.push_back(vector<ll>());
			while (train[x].first != -1) x = train[x].first;
			ans.back().push_back(x);
			while (train[x].second != -1) {
				ans.back().push_back(train[x].second);
				x = train[x].second;
			}
		}
	}

	for (auto &a : ans) {
		cout << a.size() << " ";
		for (auto v : a) {
			cout << v + 1 << " ";
		}
		cout << endl;
	}

	return 0;
}