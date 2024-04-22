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
	vector<ll> x(N),y(N);
	rep(i,N) cin >> x[i] >> y[i];

	map<pair<ll,ll>,ll> mp;
	rep(i,N) {
		rep(j,N) {
			if (i == j) continue;
			ll gcd_val = gcd(abs(x[j]-x[i]),abs(y[j]-y[i]));
			if (gcd_val == 1) {
				mp[{x[j]-x[i],y[j]-y[i]}]++;
			} else {
				mp[{(x[j]-x[i])/gcd_val,(y[j]-y[i])/gcd_val}]++;
			}
		}
	}
	cout << mp.size() << endl;
	return 0;
}