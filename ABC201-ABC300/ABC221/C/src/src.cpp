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
	vector<ll> vec(10,0);
	ll keta = 0;
	while (N != 0) {
		vec[keta] = N % 10;
		N /= 10;
		keta++;
	}

	ll ans = 0;
	for (int i = 1; i < (1 << keta); i++) {
		vector<ll> one_vec, zero_vec;
		rep(j,keta) {
			if (i >> j & 0x0001) {
				one_vec.push_back(vec[j]);
			} else {
				zero_vec.push_back(vec[j]);
			}
		}
		sort(one_vec.begin(),one_vec.end(),greater<ll>());
		sort(zero_vec.begin(),zero_vec.end(),greater<ll>());

		ll left = 0, right = 0;
		ll sisu = (ll)pow(10,zero_vec.size()-1);
		rep(j,zero_vec.size()) {
			left += zero_vec[j] * sisu;
			sisu /= 10;
		}
		sisu = (ll)pow(10,one_vec.size()-1);
		rep(j,one_vec.size()) {
			right += one_vec[j] * sisu;
			sisu /= 10;
		}
		ans = max(ans,left*right);
	}
	cout << ans << endl;

	return 0;
}