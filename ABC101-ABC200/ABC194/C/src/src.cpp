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
	vector<ll> A(N), d(N), sum(N,0), d_sum(N,0);
	rep(i,N) {
		cin >> A[i];
		d[i] = A[i] * A[i];
		if (i != 0) sum[i] = sum[i-1] + A[i], d_sum[i] = d_sum[i-1] + d[i];
		else sum[i] = A[i], d_sum[i] = d[i];
	}

	ll ans = 0;
	repp(i,1,N) {
		ans += i * d[i] - 2 * A[i] * sum[i-1] + d_sum[i-1];
	}
	cout << ans << endl;
	

	return 0;
}