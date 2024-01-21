#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, Q;
	string S;
	cin >> N >> Q >> S;
	vector<ll> l(Q), r(Q);
	rep(i,Q) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}

	vector<bool> check(N,false);
	vector<int> val;//(N,0);
	rep(i,N-1) {
		if (S[i] == S[i+1]) {
			val.push_back(i);
			check[i] = true;
		}
	}
	if (val.size() == 0) {
		rep(i,Q) cout << 0 << endl;
		return 0;
	}

	rep(i,Q) {
		if (l[i] == r[i]) {
			cout << 0 << endl;
			continue;
		}
		auto itr = lower_bound(val.begin(),val.end(),l[i]);
		int left = distance(val.begin(),itr);
		itr = lower_bound(val.begin(),val.end(),r[i]);
		int right = distance(val.begin(),itr);
		cout << right - left << endl;
	}

	return 0;
}