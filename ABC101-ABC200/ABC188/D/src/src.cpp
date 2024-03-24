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
	ll N, C; cin >> N >> C;
	vector<ll> a(N), b(N), c(N);
	map<ll,ll> mp;
	rep(i,N) {
		cin >> a[i] >> b[i] >> c[i]; 
		b[i]++;
		mp[a[i]] += c[i];
		mp[b[i]] -= c[i];
	}

	ll ans = 0;
	ll day = mp.begin()->first, fee = mp.begin()->second;
	for (auto itr = ++mp.begin(); itr != mp.end(); itr++) {
		if (fee > C) ans += (itr->first - day) * C;
		else ans += (itr->first - day) * fee;
		day = itr->first;
		fee += itr->second;
	}
	cout << ans << endl;

	/*
	vector<pair<ll,ll>> vec;
	rep(i,N) {
		cin >> a[i] >> b[i] >> c[i]; 
		b[i]++;
		vec.push_back({a[i],c[i]});
		vec.push_back({b[i],-c[i]});
	}
	sort(vec.begin(),vec.end());

	ll fee = vec[0].first;
	repp(i,1,vec.size()) {

		fee += v.first;
		if (fee > C) 
	}
	ll ans = 0;
	*/
	/*
	vector<pair<ll,ll>> A(N), B(N);
	rep(i,N) {
		cin >> a[i] >> b[i] >> c[i];
		A[i] = {--a[i],i}; B[i] = {b[i],i};
	}
	sort(A.begin(),A.end()); sort(B.begin(),B.end());

	vector<ll> vec;
	ll day = A[0].first;
	ll a_index = 0, b_index = 0;
	while (true) {
		ll tmp = 0;
		while (a_index)
	}
	*/



	return 0;
}