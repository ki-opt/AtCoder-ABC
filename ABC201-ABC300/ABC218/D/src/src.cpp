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
	vector<ll> x(N), y(N);
	map<ll,vector<ll>> mp_x;
	map<ll,vector<ll>> mp_y;
	rep(i,N) {
		cin >> x[i] >> y[i];
		mp_x[x[i]].push_back(y[i]);
		mp_y[y[i]].push_back(x[i]);
	}

	ll ans = 0;
	for (const auto &mx : mp_x) {
		rep(i,mx.second.size()-1) {
			ll y1 = mx.second[i];
			repp(j,i+1,mx.second.size()) {
				ll y2 = mx.second[j];
				rep(k,mp_y[y1].size()) {
					ll x1 = mp_y[y1][k];
					rep(l,mp_y[y2].size()) {
						ll x2 = mp_y[y2][l];
						if (mx.first != x1 && mx.first != x2 && x1 == x2) ans++;
					}
				}
			}
		}
	}
	/*
	map<ll,vector<ll>> mp_x;
	map<ll,map<ll,ll>> mp_y;
	rep(i,N) {
		cin >> x[i] >> y[i];
		mp_x[x[i]].push_back(y[i]);
		mp_y[y[i]][x[i]]++;
	}

	ll ans = 0;
	for (const auto &mx : mp_x) {	
		rep(i,mx.second.size()-1) {
			repp(j,i+1,mx.second.size()) {
				ans += mp_y[mx.second[i]][mx.second[j]];
				//ans += (mp_y[mx.second[i]]-1) * (mp_y[mx.second[j]]-1);
				//cerr << 1 << endl;
			}
		}
		//rep(i,mx.second.size()) mp_y[mx.second[i]]--;
	}
	*/
	cout << ans / 2<< endl;

	return 0;
}