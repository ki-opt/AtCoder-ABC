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
	ll N, K; cin >> N >> K;
	vector<ll> xxx(N), yyy(N);
	set<ll> set_x, set_y;
	rep(i,N) {
		cin >> xxx[i] >> yyy[i];
		set_x.insert(xxx[i]);
		set_y.insert(yyy[i]);
	}

	ll ans = LLONG_MAX;
	for (auto x : set_x) for (auto xx : set_x) 
		for (auto y : set_y) for (auto yy : set_y) {
		
		ll cnt = 0;
		rep(i,N) {
			if (xxx[i] >= x && xxx[i] <= xx && yyy[i] >= y && yyy[i] <= yy) cnt++;
		}
		if (cnt >= K) ans = min(ans,(xx-x)*(yy-y));
	}

	cout << ans << endl;

	/*
	map<ll,vector<ll>> mp_x, mp_y;
	map<ll,vector<ll>,greater<ll>> mp_x_rev, mp_y_rev;
	rep(i,N) {
		cin >> xxx[i] >> yyy[i];
		mp_x[xxx[i]].push_back(yyy[i]);
		mp_y[yyy[i]].push_back(xxx[i]);
		mp_x_rev[xxx[i]].push_back(yyy[i]);
		mp_y_rev[yyy[i]].push_back(xxx[i]);
	}

	
	ll cnt = N, ans = LLONG_MAX;
	for (auto vy : mp_x) {
		if (cnt < K) break;
		ll tmp = cnt;
		ll x = vy.first;
		for (auto vx : mp_y) {
			if (tmp < K) break;
			ll y = vy.first;
			ll tmp_2 = tmp;
			for (auto vy_rev : mp_x_rev) {		
				if (tmp_2 < K) break;
				ll tmp_3 = tmp_2;
				for (auto vx_rev : mp_y_rev) {
					if (tmp_3 < K) break;
					ans = min(ans,(vx_rev.first-x)*(vy_rev.first-y));
					tmp_3 -= vx_rev.second.size();
				}
				tmp_2 -= vy_rev.second.size();
			}
			tmp -= vx.second.size();
		}
		cnt -= vy.second.size();
	}

	/*
	map<ll,vector<ll>> mp_x, mp_y;
	map<pair<ll,ll>,ll> mp;
	rep(i,N) {
		cin >> xxx[i] >> yyy[i];
		mp_x[xxx[i]].push_back(yyy[i]);
		mp_y[yyy[i]].push_back(xxx[i]);
		mp[{xxx[i],yyy[i]}]++;
	}

	ll ans = LLONG_MAX;
	rep(i,N) {
		ll x = xxx[i], y = yyy[i];
		for (auto y1 : mp_x[x]) {
			if (y == y1) continue;
			for (auto x1 : mp_y[y]) {
				if (x == x1) continue;
				if (mp.count({x1,y1}) > 0) {
					ll bl_x = min(x,x1), bl_y = min(y,y1);
					ll tr_x = max(x,x1), tr_y = max(y,y1);
					ll cnt = 0;
					rep(i,N) {
						if (xxx[i] >= bl_x && xxx[i] <= tr_x && 
							yyy[i] >= bl_y && yyy[i] <= tr_y) cnt++;
					}
					if (cnt >= K) {
						ans = min(ans,(tr_x-bl_x)*(tr_y-bl_y));
					}
				} 
			}
		}
	}
	*/

	return 0;
}