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
	ll K; cin >> K;
	if (K % 2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> a(K+2);
	a[0] = 7 % K;
	for (int i = 1; i <= K+1; i++) a[i] = (a[i-1]*10+7) % K;
	for (int i = 0; i <= K+1; i++) if (a[i] == 0) {
		cout << i+1 << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}