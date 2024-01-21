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
	ll D;
	cin >> D;

	ll ans = LLONG_MAX;
	for (ll x = 0; x * x <= D + 10000; x++) {
		ll tmp = D - x * x;
		ll y = (ll)pow(tmp,0.5);
		ans = min({ans,abs(x * x + y * y - D),abs(x * x + (y+1) * (y+1) - D)});
		/*
		bool flag = false;
		ll bef_val = LLONG_MAX;
		for (ll y = x; !flag; y++) {
			ans = min(ans,abs(x*x+y*y-D));
			if (abs(x*x+y*y-D) - bef_val > 0) break; //flag = true;
			bef_val = abs(x*x+y*y-D);
		}
		*/
	}
	cout << ans << endl;

	return 0;
}