#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <stack>
#include "atcoder/all"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, T;
	cin >> N >> T;
	vector<ll> A(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> A[i];
		pairs[i] = {A[i],i};
	}
	
	sort(pairs.rbegin(),pairs.rend());
	ll ans = 0, ans_cnt = 1;
	ll index = 0;
	ll max_val = pairs[index].first;
	rep(i,N-1) {
		while (pairs[index].second <= i && index < N) {
			index++;
			max_val = pairs[index].first;
		}
		if (index == N) break;
		ll tmp = -A[i]*(T/2)+max_val*(T/2);
		if (tmp >= ans) {
			if (tmp == ans) ans_cnt++;
			else ans_cnt = 1;
			ans = tmp;
		}
	}
	cout << ans_cnt << endl;
	return 0;
}