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
	ll N, M; cin >> N >> M;
	if (M == 0) {cout<<1<<endl;return 0;}
	vector<ll> A(M+2); A[0] = 0; A[A.size()-1] = N+1;
	rep(i,M) cin >> A[i+1];

	sort(A.begin(),A.end());
	
	ll k = LLONG_MAX;
	rep(i,A.size()-1) {
		ll tmp = A[i+1] - A[i];
		if (tmp > 1) k = min(k,A[i+1]-A[i]);
	}
	k--;
	if (k == LLONG_MAX) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;
	rep(i,A.size()-1) {
		ll tmp = A[i+1] - A[i];
		if (tmp <= 1) continue;
		if ((tmp-1) % k == 0) ans += (tmp-1) / k;
		else ans += (tmp - 1) / k + 1;
	}
	cout << ans << endl;


	/*
	vector<ll> A(M);
	rep(i,M) cin >> A[i];

	sort(A.begin(),A.end());
	ll k = LLONG_MAX, num = 0;
	rep(i,M) {
		ll tmp = A[i] - num - 1;
		num = A[i];
		if (tmp <= 0) continue;
		k = min(k,tmp);
	}
	if (N-A.back()>1) k = min(k,N-A.back());
	
	ll ans = 0; num = A[0];
	if (A[0] > 1) {
		if (A[0]-)
	}
	repp(i,1,M) {
		ll tmp = A[i] - num - 1;
		if (tmp > 0) {
			if (tmp % k == 0) ans += tmp / k;
			else ans += tmp / k + 1;
		}
		num = A[i];
	} 
	if (N-A.back()>1) {
		if ((N-A.back()-1)%k == 0) ans += (N-A.back()-1)/k;
		else ans += (N-A.back()-1)/k+1;
	}
	cout << ans << endl;
	*/
	return 0;
}