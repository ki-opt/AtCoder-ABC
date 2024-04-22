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
#include <numeric>
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
	ll N; cin >> N;

	ll ans = 0;
	for (ll A = 1; A < 500000; A++) {
		for (ll B = A; B < 500000; B++) {
			ll C = N / (A*B);
			if (C < B) break;
			ans += (C - B + 1);
			/*
			if (N % (i*j) == 0) {
				if (c == j) ans++;
				else ans += (c - j + 2);
			} else {
				
				ans += (c - j + 1);
			}
			*/
		}
	}
	cout << ans << endl;

	return 0;
}