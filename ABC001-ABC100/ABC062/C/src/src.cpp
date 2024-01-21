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

ll H, W;

int main() {
	cin >> H >> W;
	if (H == 2 || W == 2) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = LLONG_MAX;
	for (ll i = 1; i < H-1; i++) {
		ll a, b, c;
		// tate = 3
		a = i * W;
		b = (ll)(((H - i) / (ll)2)) * W;
		c = H * W - a - b;
		ll max_val = max({a,b,c});
		ll min_val = min({a,b,c});
		ans = min(ans,max_val-min_val);
		// tate = 1, yoko = 2
		b = (H - i) * (ll)(W / (ll)2);
		c = H * W - a - b;
		max_val = max({a,b,c});
		min_val = min({a,b,c});
		ans = min(ans,max_val-min_val);
	}

	swap(H,W);
	for (ll i = 1; i < H-1; i++) {
		ll a, b, c;
		// tate = 3
		a = i * W;
		b = (ll)(((H - i) / (ll)2)) * W;
		c = H * W - a - b;
		ll max_val = max({a,b,c});
		ll min_val = min({a,b,c});
		ans = min(ans,max_val-min_val);
		// tate = 1, yoko = 2
		b = (H - i) * (ll)(W / (ll)2);
		c = H * W - a - b;
		max_val = max({a,b,c});
		min_val = min({a,b,c});
		ans = min(ans,max_val-min_val);
	}

	cout << ans << endl;

	return 0;
}