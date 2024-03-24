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


using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll L, Q; cin >> L >> Q;
	vector<ll> c(Q), x(Q);
	rep(i,Q) {
		cin >> c[i] >> x[i];
	}

	set<ll> s;
	s.insert(0);
	s.insert(L);
	rep(i,Q) {
		if (c[i] == 1) {
			s.insert(x[i]);
		} else {
			auto iter = s.lower_bound(x[i]);
			int right = *iter;
			iter--;
			int left = *iter;
			cout << right - left << endl;
		}
	}



	return 0;
}