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
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	sort(A.begin(),A.end());

	ll ans = 0;
	auto iter = upper_bound(A.begin(),A.end(),A[0]-0.1+M);
	ans = iter - A.begin();
	repp(i,1,N) {
		iter = upper_bound(A.begin(),A.end(),A[i]-0.1+M);
		ll tmp = iter - A.begin() - i;
		if (iter - A.begin() == N) {
			tmp--;
		}
		if (tmp > ans) ans = tmp;
	}
	cout << ans << endl;

	return 0;
}