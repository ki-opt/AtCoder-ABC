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
	vector<ll> t(N), l(N), r(N);
	rep(i,N) {
		cin >> t[i] >> l[i] >> r[i];
		if (t[i] == 1) l[i] = 2*l[i], r[i] = 2*r[i];
		else if (t[i] == 2) l[i] = 2*l[i], r[i] = 2*r[i]-1;
		else if (t[i] == 3) l[i] = 2*l[i]+1, r[i] = 2*r[i];
		else l[i] = 2*l[i]+1, r[i] = 2*r[i]-1;
	}

	ll ans = 0;
	rep(i,N) {
		ll lv = l[i], rv = r[i];
		repp(j,i+1,N) {
			ll llv = l[j], rrv = r[j];
			if ((lv <= llv && llv <= rv) || (lv <= rrv && rrv <= rv) || 
				(lv <= llv && rrv <= rv) || (llv <= lv && rv <= rrv)) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}