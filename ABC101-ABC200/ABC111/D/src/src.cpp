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
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N; cin >> N;
	vector<ll> X(N), Y(N);
	cin >> X[0] >> Y[0];
	ll val = abs(X[0]) + abs(Y[0]);
	repp(i,1,N) {
		cin >> X[i] >> Y[i];
		if (val % 2 != (abs(X[i]) + abs(Y[i])) % 2) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<ll> d;
	for (int i = 30; i >= 0; i--) d.push_back(1LL << i);
	if (val % 2 == 0) d.push_back(1);
	cout << d.size() << endl;
	for (auto d_ : d) cout << d_ << " ";
	cout << endl;

	rep(i,N) {
		ll x = 0, y = 0;
		rep(j,d.size()) {
			if (abs(X[i]-x) > abs(Y[i]-y)) {
				if (X[i] < x) x -= d[j], cout << "L";
				else x += d[j], cout << "R";
			} else {
				if (Y[i] < y) y -= d[j], cout << "D";
				else y += d[j], cout << "U";
			}
		}
		cout << endl;
	}

	return 0;
}