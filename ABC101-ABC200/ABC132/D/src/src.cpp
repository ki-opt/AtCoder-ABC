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
	init_nCk(2000);

	ll ans = 0;
	repp(k,1,K+1) {
		ll tmp;		// 青のボールの並べ方
		if (k == 1 || k == K) tmp = 1;
		else tmp = nCk(K-1,k-1);
		ll tmp_2;	// 赤のボールの並べ方
		if (k <= N-K+1) tmp_2 = nCk(N-K+1,k);
		else tmp_2 = 0;
		cout << (tmp * (tmp_2 % MOD)) % MOD << endl;
	}

	return 0;
}