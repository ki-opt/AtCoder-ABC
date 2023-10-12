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
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	if (n % 2 == 0) {
		for (int i = n - 1; i >= 0; i -= 2) {
			cout << a[i] << " ";	
		}
		for (int i = 0; i < n; i += 2) {
			cout << a[i] << " ";
		}
	} else if (n % 2 == 1) {
		for (int i = n - 1; i >= 0; i -= 2) {
			cout << a[i] << " ";
		}
		for (int i = 1; i < n; i += 2) {
			cout << a[i] << " ";
		}
	}

	return 0;
}