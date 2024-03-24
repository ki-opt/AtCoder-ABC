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
	素数の列挙
	計算量O(NloglogN)
*/
/*
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
*/

int main() {
	int N; cin >> N;

	ll ans = 0;
	repp(i,1,N+1) {
		for (int j = i; j < N+1; j+=i) ans += j;
	}
	cout << ans << endl;
	return 0;
}