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
	ll K;
	cin >> K;

	vector<ll> ans;
	for (int i = 2; i < (1<<10); i++) {
		ll val = 0, tmp = 1;
		for (int j = 1; j < 10; j++) {
			if (((i >> j) & 0x0001) == 1) {
				val += tmp * (ll)j;
				tmp *= 10;
			}
		}
		if (i & 0x0001) val *= 10;
		ans.push_back(val);
	}
	sort(ans.begin(),ans.end());
	cout << ans[K-1] << endl;

	return 0;
}