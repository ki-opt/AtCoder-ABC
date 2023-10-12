#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<ll> F(N), S(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> F[i] >> S[i];
		pairs[i] = {S[i],F[i]};
	}

	sort(pairs.rbegin(), pairs.rend());
	ll onazi = 0, tigau = 0;
	rep(i,N-1) {
		if (pairs[0].second != pairs[i+1].second) {
			tigau = pairs[0].first + pairs[i+1].first;
			break;
		}
	}
	rep(i,N-1) {
		if (pairs[0].second == pairs[i+1].second) {
			ll tmp = pairs[0].first + pairs[i+1].first / 2;
			ll tmp_2 = pairs[0].first / 2 + pairs[i+1].first;
			onazi = max(tmp,tmp_2);
			break;
		}
	}
	if (onazi > tigau) cout << onazi << endl;
	else cout << tigau << endl;

	return 0;
}