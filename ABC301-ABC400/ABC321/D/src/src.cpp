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
	ll N, M, P;
	cin >> N >> M >> P;
	vector<ll> A(N), B(M);
	rep(i,N) cin >> A[i];
	rep(i,M) cin >> B[i];
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//vector<ll> A_num(N,0), B_num(M,0);
	ll ans = 0;
	ll p_num = 0;
	rep(i,N) {
		auto itr = upper_bound(B.begin(),B.end(),P-A[i]);
		auto index = distance(B.begin(), itr);
		ans += A[i] * index;
		p_num += M - index;
	}
	rep(i,M) {
		auto itr = upper_bound(A.begin(),A.end(),P-B[i]);
		auto index = distance(A.begin(), itr);
		ans += B[i] * index;
		p_num += N - index;
	}

	cout << ans + P * (p_num / 2) << endl;

	return 0;
}