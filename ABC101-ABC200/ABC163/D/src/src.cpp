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

const int MOD = 1e9 + 7;
vector<long long> fact, fact_inv, inv;
/*
	init_nCk: 二項係数のための前処理
	計算量: O(n)
*/
void init_nCk(int SIZE) {
	fact.resize(SIZE + 5);
	fact_inv.resize(SIZE + 5);
	inv.resize(SIZE + 5);
	fact[0] = fact[1] = 1;
	fact_inv[0] = fact_inv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < SIZE + 5; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
	}
}
/*  
	nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
   計算量:O(1)
*/
long long nCk(int n, int k) {
	assert(!(n < k));
	assert(!(n < 0 || k < 0));
	return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
	int N, K; cin >> N >> K;
	ll ans = 0;
	ll left = 0, right = 0;
	rep(i,K) left += i, right += (N-i);
	repp(i,K,N+2) {
		ans = (ans + (right - left + 1)) % MOD;
		left += i;
		right += (N-i);
	}
	cout << ans << endl;
	/*
	init_nCk(200010);
	repp(i,K,N+2) {
		ans = (ans + nCk(N+1,i)) % MOD;
	}
	*/
	
	return 0;
}