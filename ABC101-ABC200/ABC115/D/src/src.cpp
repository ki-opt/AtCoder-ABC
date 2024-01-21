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

vector<ll> A, P;

ll rec(ll N, ll X) {
	if (N == 0) {
		if (X >= 1) return 1;
		else if (X < 1) return 0;
	}

	ll median = (ll)((A[N]+1)/2);
	if (X < median) return rec(N-1,X-1);
	else if (X == median) return P[N-1] + 1;
	else return P[N-1] + 1 + rec(N-1,X-median);
}

int main() {
	ll N, X;
	cin >> N >> X;

	A = vector<ll>(N+1,0);
	P = vector<ll>(N+1,0);
	A[0] = 1;	// レベルiバーガーの厚さ
	P[0] = 1;	// レベルiバーがのパティ数
	repp(i,1,N+1) {
		A[i] = A[i-1]*2+3;
		P[i] = P[i-1]*2+1;
	}

	ll ans = rec(N,X);
	cout << ans << endl;
	return 0;
}