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

ll N, A, B;

bool check(ll mid, vector<ll> &h) {
	ll cnt = 0;
	rep(i,N) {
		ll val = h[i] - (mid * B);
		if (val <= 0) continue;
		cnt += val / A;
		if (val % A != 0) cnt++;
	}
	return cnt <= mid;
}

int main() {
	cin >> N >> A >> B;
	A -= B;
	vector<ll> h(N);
	rep(i,N) {
		cin >> h[i];
	}

	ll l = 0, r = (ll)pow(10,9);
	while (l + 1 != r) {
		ll x = (l + r) / 2;
		if (check(x,h)) r = x;
		else l = x;
	}
	cout << l+1 << endl;

	return 0;
}