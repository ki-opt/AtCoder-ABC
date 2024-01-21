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
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	sort(A.begin(),A.end());

	int ans = A[0];
	repp(i,1,N) {
		if (A[i] % ans != 0) {
			ll tmp = ans;
			ans = A[i] % ans; //- tmp * ans;
			A[i] = tmp;
			i--;
		}
		/*
		if (A[i+1] % A[i] == 0) {
			A[i+1] = 0;
			swap(A[i],A[i+1]);
		} else {
			int tmp = A[i+1] / A[i];
			A[i+1] -= tmp * A[i];
			swap(A[i],A[i+1]);
		}
		*/
	}
	cout << ans << endl;

	return 0;
}