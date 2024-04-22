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
	ll N; cin >> N;
	vector<ll> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];

	vector<double> left(N), right(N);
	double total = 0;
	rep(i,N) {
		left[i] = (double)A[i] / (double)B[i];
		right[i] = (double)A[N-i-1] / (double)B[i];
		total += left[i];
	}

	double time = 0, ans = 0;
	double half = total / 2.0;
	rep(i,N) {
		if (time + left[i] < half) {
			time += left[i];
			ans += (double)A[i];
		} else {
			ans += (double)B[i] * (half - time);
			break;
		}
	}

	printf("%.10f\n", ans);

	return 0;
}