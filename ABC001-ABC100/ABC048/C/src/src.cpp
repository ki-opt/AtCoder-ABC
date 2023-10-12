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
	ll N, x;
	cin >> N >> x;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];

	ll ans = 0;
	repp(i,1,N) {
		if (a[i-1] + a[i] > x) {
			if (a[i-1] + a[i] - x > a[i]) {
				ans += a[i];
				a[i] = 0;
				int tmp = a[i-1] - x;
				ans += tmp;
				a[i-1] -= tmp;
			} else {
				ll tmp = a[i-1] + a[i] - x;
				ans += tmp;
				a[i] -= tmp;
			}
		}
	}
	cout << ans << endl;

	return 0;
}