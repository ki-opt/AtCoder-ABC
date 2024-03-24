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
	ll N, M, K; cin >> N >> M >> K;
	vector<ll> A(N), B(M);
	rep(i,N) cin >> A[i];
	rep(i,M) cin >> B[i];

	vector<ll> a(N+1,0), b(M+1,0);
	repp(i,1,N+1) a[i] = a[i-1] + A[i-1];
	repp(i,1,M+1) b[i] = b[i-1] + B[i-1];

	ll ans = 0;
	rep(i,N+1) {
		if (a[i] > K) break;
		auto itr = upper_bound(b.begin(),b.end(),K-a[i]);
		int j = distance(b.begin(),itr) - 1;
		//if (K - a[i] + b[j] > K) j--;
		ll tmp_ans = i + j;
		ans = max(ans,tmp_ans);
	}
	cout << ans << endl;

	return 0;
}