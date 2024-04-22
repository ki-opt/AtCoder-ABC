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
	ll N, M; cin >> N >> M;
	vector<ll> A(N), B(M);
	rep(i,N) cin >> A[i];
	rep(i,M) cin >> B[i];

	sort(A.begin(),A.end());
	sort(B.begin(),B.end());

	int a = 0, b = 0;
	ll ans = abs(A[a]-B[b]);
	while (a < N || b < M) {
		if (A[a] > B[b]) {
			b++;
		} else {
			a++;
		}
		if (a == N || b == M) break;
		ans = min(ans,abs(A[a]-B[b]));
	}
	cout << ans << endl;

	return 0;
}