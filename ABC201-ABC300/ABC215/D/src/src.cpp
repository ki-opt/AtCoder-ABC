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


#include "bits/stdc++.h"
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
vector<int> Eratosthenes( const int N ) {
	vector<bool> is_prime( N + 1 );
	for( int i = 0; i <= N; i++ ) {
	is_prime[ i ] = true;
	}
	vector<int> P;
	for( int i = 2; i <= N; i++ ) {
		if( is_prime[ i ] ) {
			for( int j = 2 * i; j <= N; j += i ) {
					is_prime[ j ] = false;
			}
			P.emplace_back( i );
		}
	}
	return P;
}


// first 基数p, second 指数e = p^e
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
	int N, M; cin >> N >> M;
	vector<int> A(N);
	unordered_map<int,int> umap;
	rep(i,N) {
		cin >> A[i];
		umap[A[i]]++;
		int y = 1;
		while (y*y <= A[i]) {
			if (A[i] % y == 0) {
				umap[y]++;
				if (y != A[i] / y) umap[A[i]/y]++;
			}
			y++;
		}
		/*
		vector<pair<ll,ll>> res = prime_factorize(A[i]);
		for (auto p : res) {
			repp(e,1,p.second+1) {
				umap[p.first]++;
				p.first *= p.first;
			}
		}
		*/
	}

	vector<int> ans = {1};
	repp(i,2,M+1) {
		if (umap.count(i) > 0) continue;
		bool isFound = true;
		int y = 2;
		while (y*y <= i) {
			if (i % y == 0) {
				if (umap.count(y) > 0) {
					isFound = false;
					break;
				}
				if (y != i / y) {
					if (umap.count(i/y) > 0) {
						isFound = false;
						break;
					}
				}
			}
			y++;
		}
		if (isFound) ans.push_back(i);
	}

	/*
	vector<int> ans = {1};
	vector<int> sosu = Eratosthenes(M);
	for (auto s : sosu) {
		if (umap.count(s) > 0) continue;
		ans.push_back(s);
	}
	*/
	
	cout << ans.size() << endl;
	for (auto a: ans) cout << a << endl;


	return 0;
}