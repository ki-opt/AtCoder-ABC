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

ll MOD = 1e9 + 7;

vector<ll> fact_inv, inv, Com;
/*  
	init_nCk :二項係数のための前処理
   計算量:O(n)
*/
void init_nCk(ll n, ll SIZE) {
	fact_inv.resize(SIZE + 5);
	inv.resize(SIZE + 5);
	fact_inv[0] = fact_inv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < SIZE + 5; i++) {
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
	}
	Com.resize(SIZE + 5);
	Com[0] = 1;
	for (ll i = 1; i < SIZE + 5; i++) {
		Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
	}
}
/* 
	nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
   計算量:O(1)
*/
long long nCk(ll k) {
	assert(!(k < 0));
	return Com[k];
}

long long power_mod(long long base, long long exponent, long long modulus) {
	long long result = 1;
	base = base % modulus;

	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result = (result * base) % modulus;
		}

		exponent = exponent / 2;
		base = (base * base) % modulus;
	}

	return result;
}

ll n, a, b;

int count(int x) {
	int res = 1;
	repp(i,0,x) res = (res * (n % MOD - i % MOD)) % MOD;
	repp(i,1,x+1) res = (res / i) % MOD;
	return res;
}

int main() {
	cin >> n >> a >> b;
	
	//ll ans = power_mod(2,n,MOD) - 1;
	//cout << ans - count(a) - count(b) << endl;
	//*
	init_nCk(n,200000+1);
	ll ans = power_mod(2,n,MOD) - 1;
	ll a_tmp = nCk(a);
	ll b_tmp = nCk(b);
	ans = ((ans + MOD) - ((a_tmp + b_tmp) % MOD)) % MOD;
	cout << ans << endl;
	//*/
	return 0;
}