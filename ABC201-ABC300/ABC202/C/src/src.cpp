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
	int N; cin >> N;
	vector<int> A(N), B(N), C(N);
	rep(i,N) { cin >> A[i]; }
	rep(i,N) cin >> B[i];
	rep(i,N) { cin >> C[i]; C[i]--; }
	
	vector<int> BCj(100001,0);
	rep(i,N) BCj[B[C[i]]]++;

	ll ans = 0;
	rep(i,N) ans += BCj[A[i]];
	cout << ans << endl;

	return 0;
}