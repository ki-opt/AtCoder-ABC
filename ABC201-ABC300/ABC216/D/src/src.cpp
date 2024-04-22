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
	ll N, M; cin >> N >> M;
	vector<ll> k(M);
	vector<deque<ll>> a(M);
	rep(i,M) {
		cin >> k[i];
		a[i].resize(k[i]);
		rep(j,k[i]) {
			cin >> a[i][j]; 
			a[i][j]--;
		}
	}

	vector<vector<ll>> color(N);
	queue<pair<ll,ll>> que;
	rep(i,M) {
		ll tmp = a[i][0];
		color[tmp].push_back(i);
		a[i].pop_front();
		if (color[tmp].size() == 2) {
			que.push({color[tmp][0],color[tmp][1]});
			color[tmp].clear();
		}
	}

	while (!que.empty()) {
		pair<ll,ll> pairs = que.front(); que.pop();
		ll i = pairs.first;
		if (a[i].size() > 0) {
			ll tmp = a[i].front(); a[i].pop_front();
			color[tmp].push_back(i);
			if (color[tmp].size() == 2) {
				que.push({color[tmp][0],color[tmp][1]});
				color[tmp].clear();
			}
		}

		i = pairs.second;
		if (a[i].size() > 0) {
			ll tmp = a[i].front(); a[i].pop_front();
			color[tmp].push_back(i);
			if (color[tmp].size() == 2) {
				que.push({color[tmp][0],color[tmp][1]});
				color[tmp].clear();
			}
		}
	}

	rep(i,color.size()) {
		if (color[i].size() != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	/*
	vector<vector<ll>> color(N);
	rep(i,M) {
		if (a[i].size() > 0) {
			ll tmp = a[i].front(); a[i].pop_front();
			color[tmp].push_back(i);
			if (color[tmp].size() == 2) {
				queue<ll> que;
				que.push(color[tmp][0]); que.push(color[tmp][1]);
				color[tmp].clear();
				while (!que.empty()) {
					tmp = que.front(); que.pop();
					color[tmp].push_back()
					if (color[tmp].size() == 2) ;
				}
			}
			/*
			if (tutu[tmp].size() == 1) {
				que.push(tutu[tmp][0]);
				que.push(i);
				tutu[tmp].pop_back();
				continue;
			}
			tutu[a[i][0]].push_back(i);
			
		}
	}
	
	rep(i,M) {
		if (a[i].size() != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
	*/

	return 0;
}