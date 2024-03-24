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
	if (N <= 10) {
		cout << 0 << endl;
		return 0;
	}

	ll n = N, keta = 0;
	while (n != 0) keta++, n /= 10;

	ll ans = 0, v = 9;
	for (int i = 2; i < keta; i+=2) {
		ans += v;
		v *= 10;
	}

	if (keta % 2 == 0) {
		for (ll i = (ll)pow(10,keta/2-1); i * (ll)pow(10,keta/2) + i <= N; i++) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}