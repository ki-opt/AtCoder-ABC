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
	vector<ll> a(N), b(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> a[i] >> b[i];
		pairs[i] = {a[i],b[i]};
	}

	sort(pairs.begin(),pairs.end());
	ll before_sum = 0, sum = 0;
	rep(i,N) {
		sum += pairs[i].second;
		if (before_sum <= K && K <= sum) {
			cout << pairs[i].first << endl;
			return 0;
		}
		before_sum += pairs[i].second;
	}

	return 0;
}