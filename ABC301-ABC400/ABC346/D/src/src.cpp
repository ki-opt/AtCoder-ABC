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
	string S; cin >> S;
	vector<ll> C(N); rep(i,N) cin >> C[i];

	vector<ll> zero_one(N,0), one_zero(N,0);
	if (S[0] == '0') one_zero[0] = C[0];
	else if (S[0] == '1') zero_one[0] = C[0];
	repp(i,1,N) {
		zero_one[i] = zero_one[i-1]; one_zero[i] = one_zero[i-1];
		// 01
		if (S[i] == '0') {
			if (i % 2 == 0) one_zero[i] += C[i];
			else if (i % 2 == 1) zero_one[i] += C[i];
		} else if (S[i] == '1') {
			if (i % 2 == 0) zero_one[i] += C[i];
			else if (i % 2 == 1) one_zero[i] += C[i];
		}
	}
	ll one_zero_tot = one_zero.back(), zero_one_tot = zero_one.back();
	zero_one.push_back(0); one_zero.push_back(0);	

	ll ans = LLONG_MAX;
	repp(i,0,N-1) { 
		// 00
		ll tmp_0 = (S[i] != '0' ? C[i] : 0);
		if (i % 2 == 0) tmp_0 += one_zero_tot - one_zero[i];
		else if (i % 2 == 1) tmp_0 += zero_one_tot - zero_one[i];
		if (i != 0) {
			if (i % 2 == 0) tmp_0 += zero_one[i-1]; 
			else if (i % 2 == 1) tmp_0 += one_zero[i-1];
		}

		// 11
		ll tmp_1 = (S[i] != '1' ? C[i] : 0);
		if (i % 2 == 0) tmp_1 += zero_one_tot - zero_one[i];
		else if (i % 2 == 1) tmp_1 += one_zero_tot - one_zero[i];
		if (i != 0) {
			if (i % 2 == 0) tmp_1 += one_zero[i-1];
			else if (i % 2 == 1) tmp_1 += zero_one[i-1];
		}

		ans = min({ans,tmp_0,tmp_1});
	}
	cout << ans << endl;

	return 0;
}
/*
int main() {
	ll N; cin >> N;
	string S; cin >> S;
	S += '*';
	vector<ll> C(N); rep(i,N) cin >> C[i];
	C.push_back(0);

	vector<ll> zero_one(N+1,0), one_zero(N+1,0);
	for (int i = 0; i < N; i+=2) {
		if (i != 0) {
			zero_one[i] = zero_one[i-1];
			one_zero[i] = one_zero[i-1];
		}
		// 01
		if (S[i] != '0') zero_one[i] += C[i];
		if (S[i+1] != '1' && S[i+1] != '*') zero_one[i] += C[i+1]; 
		zero_one[i+1] = zero_one[i];
		// 10
		if (S[i] != '1') one_zero[i] += C[i];
		if (S[i+1] != '0' && S[i+1] != '*') one_zero[i] += C[i+1];
		one_zero[i+1] = one_zero[i];
	}

	ll ans = LLONG_MAX;
	for (int i = 0; i < N-1; i++) {
		// 00
		ll tmp_0 = 0;
		if (i - 1 < 0) {
			tmp_0 += one_zero.back() - one_zero[i];
		} else {
			tmp_0 += zero_one[i-1] + (one_zero.back() - one_zero[i]);
		}
		if (S[i] != '0') tmp_0 += C[i];
		if (S[i+1] != '0' && S[i+1] != '*') tmp_0 += C[i+1];
		// 11
		ll tmp_1 = 0;
		if (i - 1 < 0) {
			tmp_1 += zero_one.back() - zero_one[i];
		} else {
			tmp_1 += one_zero[i-1] + (zero_one.back() - zero_one[i]);
		}
		if (S[i] != '1') tmp_1 += C[i];
		if (S[i+1] != '1' && S[i+1] != '*') tmp_1 += C[i+1];
		ans = min({ans,tmp_0,tmp_1});
	}
	cout << ans << endl;

	return 0;
}
*/