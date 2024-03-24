
//*
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
#include "bits/stdc++.h"

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

/*
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
vector<ll> Eratosthenes( const int N ) {
	vector<bool> is_prime( N + 1 );
	for( int i = 0; i <= N; i++ ) {
		is_prime[ i ] = true;
	}
	vector<ll> P;
	for( int i = 2; i <= N; i++ ) {
		if( is_prime[ i ] ) {
			for( int j = 2 * i; j <= N; j += i ) {
					is_prime[ j ] = false;
			}
			P.emplace_back( (ll)i );
		}
	}
	return P;
}

bool isPrime(long long N) {
    if (N < 2) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
*/

/* 素因数分解
	計算量O(N^1/2)
*/

vector<pair<long long, long long>> prime_factorize(long long N) {
	// 答えを表す可変長配列
	vector<pair<long long, long long>> res;
	// √N まで試し割っていく
	for (long long p = 2; p * p <= N; ++p) {
		// N が p で割り切れないならばスキップ
		if (N % p != 0) continue;
		// N の素因数 p に対する指数を求める
		int e = 0;
		while (N % p == 0) {
			// 指数を 1 増やす
			++e;
			// N を p で割る
			N /= p;
		}
		// 答えに追加
		res.emplace_back(p, e);
	}

	// 素数が最後に残ることがありうる
	if (N != 1) res.emplace_back(N, 1);
	return res;
}

int main() {
	ll N; cin >> N;
	ll ans = 0;
	vector<pair<ll,ll>> P = prime_factorize(N);

	for (auto p : P) {
		ll z = p.first;
		for (ll i = 1; z <= N; z *= p.first) {
			if (N % z == 0) {
				N /= z;
				ans++;
			}
		}
	}
	cout << ans << endl;

/*
	vector<ll> P = Eratosthenes((int)sqrt(N)+1);
	if (isPrime(N)) P.push_back(N);
	//for(auto p : P) cout << p << endl;
	unordered_map<ll,int> umap;
	while(true) {
		bool isFound = false;
		for (auto p : P) {
			ll z = p;
			while (z <= N) {
				if (N % z == 0 && umap.count(z) == 0) break;
				z *= p;
			}
			if (z <= N) {
				N /= z;
				isFound = true;
				ans++;
				umap[z]++;
				break;
			}
		}
		if (isFound) break;
	}
	cout << ans << endl;
*/
	return 0;
}
