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
	vector<ll> A(N), B(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> A[i] >> B[i];
		pairs[i] = {A[i],B[i]};
	}

	sort(pairs.begin(), pairs.end(), [&](const pair<ll,ll> left, const pair<ll,ll> right) {
		return left.second < right.second;
	});

	ll ans = 0;
	rep(i,N) {
		ans += pairs[i].first;
		if (ans > pairs[i].second) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}