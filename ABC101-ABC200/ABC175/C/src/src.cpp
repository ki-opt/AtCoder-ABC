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
	ll X, K, D; cin >> X >> K >> D;
	X = abs(X);

	ll k;
	if (X % D == 0) {
		k = X / D;
		if (k > K) {
			cout << X - K * D << endl;
			return 0;
		}
		X = 0;
		if ((K - k) % 2 == 0) cout << 0 << endl;
		else cout << D << endl;
		return 0; 
	} else {
		k = (X / D + 1);
		if (k > K) {
			cout << X - K * D << endl;
			return 0;
		}
		X -= k * D;
		X = abs(X);
		K -= k;
	}

	if (K % 2 == 0) {
		cout << abs(X) << endl;
	} else {
		cout << abs(X-D) << endl;
	}

	return 0;
}