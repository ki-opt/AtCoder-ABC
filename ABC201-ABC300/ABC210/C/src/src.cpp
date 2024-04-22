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
	ll N, K; cin >> N >> K;
	vector<ll> c(N);
	rep(i,N) cin >> c[i];

	map<ll,ll> mp;
	rep(i,K) mp[c[i]]++;
	ll ans = mp.size();
	
	repp(i,1,N-K+1) {
		mp[c[i-1]]--;
		if (mp[c[i-1]] == 0) mp.erase(c[i-1]);
		mp[c[i+K-1]]++;
		ans = max(ans,(ll)mp.size());
	}

	cout << ans << endl;
	return 0;
}