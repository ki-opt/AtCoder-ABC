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
	vector<ll> A(N); rep(i,N) cin >> A[i];
	ll X; cin >> X;

	ll total = 0;
	rep(i,N) total += A[i];

	ll ans = (X / total) * N;
	if (X % total != 0) {
		total = (X / total) * total;
		rep(i,N) {
			total += A[i];
			ans++;
			if (total > X) break;
		}
	} else ans++;
	cout << ans << endl;
	
	return 0;
}