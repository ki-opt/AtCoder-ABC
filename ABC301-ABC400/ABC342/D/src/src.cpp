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
	vector<ll> A(N);
	rep(i,N) {
		cin >> A[i];
	}

	ll ans = 0;
	vector<ll> cnt(2e6+1,0);
	for (auto x : A) {
		int y = x, i = 2;
		while (i * i <= y) {
			while (y % (i * i) == 0) y /= i * i;
			i++;
		}
		ans += cnt[y];
		cnt[y]++;
	}
	cout << ans + cnt[0] * (N - cnt[0]);
	return 0;
}