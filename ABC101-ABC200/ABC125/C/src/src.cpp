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

bool isprime(ll N) {
	if (N < 2) return false;
	for (ll i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	vector<int> left(N+1,0), right(N+1,0);
	for (int i = 0; i < N; i++) left[i+1] = gcd(left[i],A[i]);
	for (int i = N-1; i >= 0; i--) right[i] = gcd(right[i+1],A[i]);

	int ans = 0;
	rep(i,N) {
		int l = left[i];
		int r = right[i+1];
		ans = max(ans,gcd(l,r));
	}
	cout << ans << endl;

	/*
	for (ll i = 2; i * i <= *max_element(A.begin(),A.end()); i++) {
		rep(j,N) {
			if (A[j] % i == 0) {

			}
		}
	}
	*/
	


	return 0;
}