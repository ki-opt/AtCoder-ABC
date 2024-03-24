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
	ll N, X, M; cin >> N >> X >> M;

	vector<ll> vec(100001,0); 
	ll tmp = X;
	while(vec[tmp] == 0) {
		vec[tmp]++;
		tmp = (tmp * tmp) % M;
	}
	ll v = tmp;

	// X => tmp;
	ll ans = 0;
	ll cnt = 0;
	tmp = X;
	while (v != tmp) {
		cnt++;
		ans += tmp;
		tmp = (tmp * tmp) % M;
	}
	N -= cnt;

	// tmp => tmp;
	ll total = 0;
	vector<ll> a;
	tmp = v;
	while (a.empty() || tmp != v) {
		a.push_back(tmp);
		total += tmp;
		tmp = (tmp * tmp) % M;
	}

	ans += total * (N / a.size());
	rep(i,N%a.size()) ans += a[i];

	cout << ans << endl;

	return 0;
}