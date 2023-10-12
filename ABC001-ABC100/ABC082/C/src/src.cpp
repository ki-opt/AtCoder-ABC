#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];

	unordered_map<ll,ll> umap;
	sort(a.begin(),a.end());
	rep(i,N) {
		if (umap.count(a[i]) == 0) umap[a[i]] = 1;
		else umap[a[i]]++;
	}

	ll ans = 0;
	for (auto itr = umap.begin(); itr != umap.end(); itr++) {
		ll key = itr->first;
		ll val = itr->second;
		if (key > val) ans += val;
		else if (key <= val) ans += (val - key); 
	}
	cout << ans << endl;

	return 0;
}