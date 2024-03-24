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
	ll K;
	cin >> K;
	if (K < 50) {
		if (K % 2 == 0) {
			cout << 2 << endl;
			cout << (K + 2) / 2 << " " << (K + 2) / 2 << endl;
		} else {
			cout << 2 << endl;
			cout << (K + 3) / 2 << " " << K / 2 << endl;
		}
		return 0;
	}

	ll N = 50;
	vector<ll> ans(N,49);
	ll total = K - (N - 1);
	rep(i,N) {
		if (49 + total > (ll)pow(10,16)) {
			ans[i] += (ll)pow(10,16);
			total -= (ll)pow(10,16);
		} else {
			ans[i] += total;
			break;
		}
	}
	cout << N << endl;
	for (auto a : ans) cout << a << " ";
	cout << endl;
	return 0;
}