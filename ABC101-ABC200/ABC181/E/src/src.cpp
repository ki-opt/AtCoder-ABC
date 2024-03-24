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
	ll N, M; cin >> N >> M;
	vector<ll> H(N), W(M);
	rep(i,N) cin >> H[i];
	rep(i,M) cin >> W[i];

	sort(H.begin(),H.end());
	
	/*
	ll v = -1, index = -1;
	rep(i,M) {

	}
	*/

	vector<ll> left, right;
	if (N > 1) left.push_back(abs(H[0]-H[1])), right.push_back(abs(H[N-1]-H[N-2]));
	else left.push_back(0), right.push_back(0);

	for (int i = 2; i < N-1; i += 2) left.push_back(left[i/2-1] + abs(H[i]-H[i+1]));
	for (int i = 3; i < N; i += 2) right.push_back(right[i/2-1] + abs(H[N-i]-H[N-i-1]));
	ll ans = LLONG_MAX;
	rep(i,M) {
		auto itr = lower_bound(H.begin(),H.end(),W[i]);
		int index_tmp = distance(H.begin(),itr);
		repp(p,-10,11) {
			int index = index_tmp + p;
			if (index < 0 || index > N) continue;
			if (index == 0) {
				ans = min(ans,abs(H[0]-W[i])+right.back());
			} else if (index == N) {
				ans = min(ans,abs(H[N-1]-W[i])+left.back());
			} else {
				if (index % 2 == 1) {
					if (N/2-1-(index/2+1) < 0) continue;
					ans = min(ans,abs(H[index+1]-W[i])+left[index/2]+right[N/2-1-(index/2+1)]);
				} else {
					ans = min(ans,abs(H[index]-W[i])+left[index/2-1]+right[(N/2-1)-(index/2-1)]);
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}