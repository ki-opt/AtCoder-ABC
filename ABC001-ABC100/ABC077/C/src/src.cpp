#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll N;
	cin >> N;
	vector<ll> A(N), B(N), C(N);
	rep(i,N) cin >> A[i];
	rep(i,N) cin >> B[i];
	rep(i,N) cin >> C[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	ll ans = 0;
	rep(i,N) {
		auto itr = lower_bound(A.begin(),A.end(),B[i]);
		ll a = distance(A.begin(),itr);
		itr = upper_bound(C.begin(),C.end(),B[i]);
		ll c = distance(itr,C.end());
		ans += a*c;		
	}
	/*
	//vector<ll> b_sum(N), a_sum(N);
	vector<ll> b(N), a(N);
	rep(i,N) {
		auto itr = lower_bound(B.begin(),B.end(),C[i]);
		ll tmp = distance(B.begin(),itr);
		if (i == 0) b_sum[i] = tmp;
		else b_sum[i] = b_sum[i-1] + tmp;
		b[i] = tmp;
	}
	rep(i,N) {
		auto itr = lower_bound(A.begin(),A.end(),B[i]);
		ll tmp = distance(A.begin(),itr);
		if (i == 0) a_sum[i] = tmp;
		else a_sum[i] = a_sum[i-1] + tmp;
		a[i] = tmp;
	}
	*/
	cout << ans << endl;

	return 0;
}