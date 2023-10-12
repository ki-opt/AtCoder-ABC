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
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	sort(a.begin(),a.end(),greater<ll>());
	ll max_val = a[0];
	ll diff_min = LLONG_MAX;
	ll ans = -1;
	repp(i,1,n) {
		if (abs(((double)max_val / 2.0) - (double)abs(max_val - a[i])) < diff_min) {
			diff_min = abs(((double)max_val / 2.0) - (double)abs(max_val - a[i]));
			ans = a[i];
		}
	}
	cout << max_val << " " << ans << endl;
	return 0;
}