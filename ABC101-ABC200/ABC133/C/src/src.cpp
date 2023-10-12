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
	ll L, R;
	cin >> L >> R;

	ll min_val = LLONG_MAX;
	for(ll i = L; i < L + 2020; i++) {
		if (i >= R) break;
		for (ll j = i + 1; j < i + 2020; j++) {
			if (j > R) break;
			ll tmp = i * j % 2019;
			if (tmp < min_val) {
				min_val = tmp;
				if (min_val == 0) break;
			}
		}
	}
	cout << min_val << endl;

	return 0;
}