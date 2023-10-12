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
	vector<ll> p(N);
	rep(i,N) cin >> p[i];

	ll ans = 0;
	rep(i,N) {
		if (p[i] == i+1) {
			if (i + 1 == N) swap(p[i],p[i-1]);
			else swap(p[i],p[i+1]);
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}