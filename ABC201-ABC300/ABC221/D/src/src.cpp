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
	vector<ll> A(N), B(N);
	map<ll,ll> mp;
	rep(i,N) {
		cin >> A[i] >> B[i];
		mp[A[i]]++;
		mp[A[i]+B[i]]--;
	}

	vector<ll> ans(N+1,0);
	auto itr = mp.begin();
	ll day = itr->first;
	ll k = itr->second;
	while (itr != mp.end()) {
		itr++;
		if (itr == mp.end()) break;
		ll next_day = itr->first;
		ans[k] += next_day - day;
		k += itr->second;
		day = next_day;
	}

	repp(i,1,N+1) {
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}