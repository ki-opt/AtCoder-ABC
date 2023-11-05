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
		//pairs[i] = {T[i]+D[i],T[i]};
	}

	ll ans = 0;
	sort(pairs.begin(), pairs.end());
	for (ll t = 1; t < (ll)pow(10,18); t++) {
		
	}
	/*
	ull ans = 0;
	sort(pairs.begin(),pairs.end());
	ull t = pairs[0].second;
	repp(i,0,N) {
		if (t >= pairs[i].second && t <= pairs[i].first) {
			ans++;
			t++;
		} else {
			if (t > pairs[i].first) continue;
			t = pairs[i].second + 1;
			ans++;	
		}
	}
	//*/
	cout << ans << endl;

	return 0;
}