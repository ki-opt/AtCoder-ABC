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
	ll Q; cin >> Q;

	vector<ll> ans;
	priority_queue<ll,vector<ll>,greater<ll>> pque;
	queue<ll> que;
	rep(q,Q) {
		int query; cin >> query;
		if (query == 1) {
			ll x; cin >> x;
			que.push(x);
		} else if (query == 2) {
			if (pque.empty()) {
				ans.push_back(que.front());
				que.pop();
			} else {
				ans.push_back(pque.top());
				pque.pop();
			}
		} else {
			while (!que.empty()) {
				pque.push(que.front());
				que.pop();	
			}
		}
	}

	/*
	vector<ll> ans;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pque;
	queue<pair<ll,ll>> que;
	unordered_map<ll,ll> seen;
	for (ll q = 0; q < Q; q++) {
		ll query; cin >> query;
		if (query == 1) {
			ll x; cin >> x;
			que.push({x,q});
			pque.push({x,q});
		} else if (query == 2) {
			if (que.empty()) {
				while (seen.count(pque.top().second) > 0) pque.pop();
				ans.push_back(pque.top().first);
				seen[pque.top().second]++;
				pque.pop();
			} else {
				while (seen.count(que.front().second) > 0) que.pop();
				ans.push_back(que.front().first);
				seen[que.front().second]++;
				que.pop();
			}
		} else {
			queue<pair<ll,ll>> empty;
			que.swap(empty);
		}
	}
	*/

	for (auto a : ans) cout << a << endl;

	return 0;
}