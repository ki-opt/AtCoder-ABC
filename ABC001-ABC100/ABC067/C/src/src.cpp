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
	ll N;
	cin >> N;
	vector<ll> a(N);
	ll tmp = 0;
	rep(i,N) {
		cin >> a[i];
		tmp += a[i];
	}

	ll left = 0, right = tmp;
	ll ans = LLONG_MAX;
	rep(i,N-1) {
		left += a[i];
		right -= a[i];
		ans = min(ans,abs(left-right));
	}
	cout << ans << endl;

	return 0;
}