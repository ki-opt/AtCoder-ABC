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
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	
	vector<ll> a(N,0);
	a[0] = A[0];
	repp(i,1,N) a[i] = a[i-1] + A[i];
	
	ll ans = 0, pos = 0, a_max = 0, a_dash = 0;
	rep(i,N) {
		pos += a[i];
		a_dash += A[i];
		a_max = max(a_max,a_dash);
		if (i + 1 == N) ans = max({ans,pos});
		else ans = max({ans,pos+a_max,pos});		
	}
	cout << ans << endl;

	/*
	int index = -1;
	for (int i = N-1; i >= 0; i--) if (a[i] > 0) {
		index = i; break;
	}
	if (index == -1) {
		cout << 0 << endl;
	} else {
		ll ans = 0;
		if (index+1 == N) {
			rep(i,index) ans += a[i];
		} else {
			rep(i,index+1) ans += a[i];
		}
		ll v = 0, tmp = 0;
		rep(i,N) {
			tmp += A[i];
			v = max(v,tmp);
		} 

		cout << ans + v << endl;
	}

	/*
	vector<ll> a(N,0), a_max(N,0);
	a[0] = A[0];
	if (A[0] > 0) a_max[0] = A[0];
	repp(i,1,N) {
		a[i] = a[i-1] + A[i];
		if (A[i] > 0) a_max[i] = a_max[i-1] + A[i];
		else a_max[i] = a_max[i-1];
	}

	ll ans = 0, pos = 0;
	rep(i,N) {
		pos += a_max[i];
		ans = max(ans,pos);
		pos += (-a_max[i] + a[i]);
		ans = max(ans,pos);		
	}
	cout << ans << endl;
	*/

	return 0;
}