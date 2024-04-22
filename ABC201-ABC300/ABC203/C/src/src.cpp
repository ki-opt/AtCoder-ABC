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
#include <set>
#include <math.h>
#include <float.h>
#include "atcoder/all"

using namespace std;
using namespace atcoder;

using ull=unsigned long long;
using ll=long long;
//using mint = modint998244353;
//using mint = modint1000000007;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, K; cin >> N >> K;
	vector<ll> A(N), B(N);
	vector<pair<ll,ll>> pairs(N);
	rep(i,N) {
		cin >> A[i] >> B[i];
		pairs[i] = {A[i],B[i]};
	}
	sort(pairs.begin(),pairs.end());
	ll now = 0, index = 0;
	while (index < N && pairs[index].first - now <= K) {
		K = K - (pairs[index].first - now) + pairs[index].second;
		now = pairs[index].first;
		index++;
		while (index < N && pairs[index].first == pairs[index-1].first) {
			K += pairs[index].second;
			index++;
		}
	}
	cout << now + K << endl;

	return 0;
}