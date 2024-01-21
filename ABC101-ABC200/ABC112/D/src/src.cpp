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
	ll N, M;
	cin >> N >> M;

	vector<ll> candidate;
	for (ll i = 1; i * i <= M; i++) {
		if (M % i == 0) {
			candidate.push_back(i);
			candidate.push_back(M/i);
		}
	}
	//if (N == 1) candidate.push_back(M);
	sort(candidate.begin(),candidate.end());
	
	ll ans = 1;
	for (auto i : candidate) {
		if (i * N <= M) ans = max(ans,i);
	}	
	cout << ans << endl;
	return 0;
}