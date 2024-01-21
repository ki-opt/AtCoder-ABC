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
#include <bits/stdc++.h>
#include <atcoder/all>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

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

bool check(int p) {
	for (int i = 2; i * i <= p; i++) {
		if (p % i == 0) return false;
	}
	return true;
}

int main() {
	int Q;
	cin >> Q;
	vector<int> l(Q), r(Q);
	vector<int> P_all = Eratosthenes((int)pow(10,5)), P;
	for (auto p : P_all) {
		if (p == 2) continue;
		if (check((p+1)/2)) P.push_back(p);
	}
	rep(i,Q) {
		cin >> l[i] >> r[i];
		auto itr_l = lower_bound(P.begin(),P.end(),l[i]);
		auto itr_r = upper_bound(P.begin(),P.end(),r[i]);
		int index_l = distance(P.begin(),itr_l), index_r = distance(P.begin(),itr_r);
		cout << index_r - index_l << endl;				
	}

	return 0;
}