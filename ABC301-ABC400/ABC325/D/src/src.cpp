#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ull N;
	cin >> N;
	vector<ll> T(N), D(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> T[i] >> D[i];
		pairs[i] = {T[i],T[i]+D[i]};
	}

	ll n = 0;
	ll t = pairs[n].first;
	ll ans = 0;
	priority_queue<ll,vector<ll>,greater<ll>> pque;
	sort(pairs.begin(), pairs.end());
	while(n < N || !pque.empty()) {
		while (n < N && pairs[n].first == t) { pque.push(pairs[n].second); n++; }
		if (!pque.empty()) {
			ll tmp = pque.top(); pque.pop();
			if (t <= tmp) { 
				ans++;
				t++;
			}
			while(!pque.empty() && t > pque.top()) pque.pop();
		} else {
			t = pairs[n].first;
		}
	}
	cout << ans << endl;

	return 0;
}