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

#define teisu ((ll)pow(10,9)+7)

int main() {
	ll N, A, B;
	cin >> N >> A >> B;
	vector<ll> X(N);
	rep(i,N) cin >> X[i];

	ll ans = 0;
	rep(i,N-1) {
		if ((X[i+1]-X[i])*A > B) {
			ans += B;
		} else {
			ans += (X[i+1]-X[i])*A;
		}
	}
	cout << ans << endl;

	return 0;
}