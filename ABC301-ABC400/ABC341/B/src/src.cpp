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
	ll N; cin >> N;
	vector<ll> A(N), S(N-1), T(N-1);
	rep(i,N) cin >> A[i];
	rep(i,N-1) {
		cin >> S[i] >> T[i];
	}
	rep(i,N-1) {
		A[i+1] += T[i] * (A[i] / S[i]);
	}
	cout << A[N-1] << endl;


	return 0;
}