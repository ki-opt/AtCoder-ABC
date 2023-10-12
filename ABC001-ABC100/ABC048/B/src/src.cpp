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
	ll a, b, x;
	cin >> a >> b >> x;
	if (x == 1) {
		cout << b - a + 1 << endl;
		return 0;
	}
	ll ans = b / x - (a - 1) / x;
	if (a == 0) ans++;
	cout << ans << endl;
	return 0;
}