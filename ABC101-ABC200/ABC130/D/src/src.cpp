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
	ll N, K;
	cin >> N >> K;
	vector<ll> a(N);
	rep(i,N) cin >> a[i];

	ll ans = 0;
	ll total = 0;
	int j = 0;
	repp(i,0,N) {
		while(j < N && total < K) {
			total += a[j];
			j++;
		}
		if (j == N && total < K) break;
		else { ans += N - (j - 1); total -= a[i]; }
	}
	cout << ans << endl;
	return 0;
}