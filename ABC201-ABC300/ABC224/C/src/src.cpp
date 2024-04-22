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
	vector<ll> X(N), Y(N);
	rep(i,N) cin >> X[i] >> Y[i];

	ll ans = 0;
	rep(i,N) {
		ll x0 = X[i], y0 = Y[i];
		repp(j,i+1,N) {
			ll x1 = X[j] - x0, y1 = Y[j] - y0;
			repp(k,j+1,N) {
				ll x2 = X[k] - x0, y2 = Y[k] - y0;
				if (abs(x1*y2 - x2*y1) == 0) continue;
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}