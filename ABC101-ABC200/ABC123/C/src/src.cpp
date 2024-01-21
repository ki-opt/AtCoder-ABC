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
	ll N, A, B, C, D, E;
	cin >> N >> A >> B >> C >> D >> E;
	vector<pair<ll,ll>> pairs = { {A,1},{B,2},{C,3},{D,4},{E,5} };
	sort(pairs.begin(),pairs.end());
	
	ll ans = pairs[0].second - 1;
	//ll ans = 4;
	if (N % pairs[0].first == 0) ans += N / pairs[0].first;
	else ans += N / pairs[0].first + 1;
	ans += (5 - pairs[0].second);
	cout << ans << endl;

	return 0;
}