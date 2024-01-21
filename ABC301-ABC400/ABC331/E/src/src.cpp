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

struct B_pair {
	ll b;
	ll index;
};

int main() {
	ll N, M, L;
	cin >> N >> M >> L;
	vector<ll> a(N), b(M), c(L), d(L);
	vector<pair<ll,ll>> b_pair(M);
	rep(i,N) cin >> a[i];
	rep(i,M) { cin >> b[i]; b_pair[i] = {b[i],i}; }
	rep(i,L) {
		cin >> c[i] >> d[i];
		c[i]--; d[i]--;
	}
	
	sort(b_pair.begin(),b_pair.end());
	vector<unordered_map<ll,ll>> umap(N);
	rep(i,L) {
		umap[c[i]][d[i]]++;
	}
	ll ans = 0;
	rep(i,N) {
		ll val = a[i];
		bool isFound = false;
		for (int j = M-1; j >= 0; j--) {
			if (L != 0 && umap[i].count(b_pair[j].second) > 0) continue;
			val += b_pair[j].first;
			isFound = true;
			break;
		}
		if (isFound) ans = max(ans,val);
	}
	cout << ans << endl;

	/*
	vector<vector<ll>> pairs(N);
	rep(i,L) pairs[tmp[i].first].push_back(tmp[i].second);

	ll ans = 0;
	rep(i,N) {
		ll val = a[i];
		if (pairs[i].size() == 0) {
			val += b[b.size()-1];
		} else {

			//*lower_bound(pairs[i].begin(),pairs[i].end(),);
		}
		ans = max(ans,val);
	}*/

	return 0;
}