#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N, L, R;
	cin >> N >> L >> R;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	rep(i,N) {
		if (A[i] >= L && A[i] <= R) cout << A[i] << " ";
		else if (A[i] < L) cout << L << " ";
		else if (A[i] > R) cout << R << " ";
	}

	return 0;
}