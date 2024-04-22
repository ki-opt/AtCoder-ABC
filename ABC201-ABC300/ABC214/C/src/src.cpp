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
	vector<ll> S(N), T(N);
	vector<pair<ll,ll>> s(N), t(N);
	rep(i,N) {
		cin >> S[i];
		s[i] = {S[i],i};
	}
	rep(i,N) {
		cin >> T[i];
		t[i] = {T[i],i};
	}

	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pque;
	rep(i,N) pque.push({T[i],i});
	vector<ll> ans(N, LLONG_MAX);
	
	pair<ll,ll> tmp = pque.top(); pque.pop();
	ans[tmp.second] = tmp.first;
	pque.push({tmp.first+S[tmp.second],tmp.second+1});

	while (!pque.empty()) {
		tmp = pque.top(); pque.pop();
		ll index = (tmp.second == N ? 0 : tmp.second);
		if (ans[index] != LLONG_MAX) continue;
		ans[index] = tmp.first;
		pque.push({ans[index]+S[index],index+1});
	}
	
	for (auto a : ans) cout << a << endl;

	/*
	sort(t.begin(),t.end());

	vector<ll>  ans(N,LLONG_MAX);
	ll i = 1, time = t[0].first, index = t[0].second;
	ans[index] = time;
	repp(cnt,1,N) {
		if (time + S[index] >= t[i].first) {
			time = t[i].first;
			index = t[i].second;
			i++;
			ans[index] = time;
		} else {
			time = time + S[index];
			index++;
			if (index == N) index = 0;
			ans[index] = time;
		}
	}

	/*
	rep(i,N) {
		ans[i] = min(ans[i],T[i]);
	}
	rep(i,N) {
		if (t[i].second + 1 == N) {
			ans[0] = min(ans[0], ans[t[i].second]+S[t[i].second]);
		} else {
			ans[t[i].second+1] = min(ans[t[i].second+1], ans[t[i].second]+S[t[i].second]);
		}
	}
	*/
	return 0;
}