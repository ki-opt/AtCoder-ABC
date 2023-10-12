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

	vector<ll> ans(N);
	ans[0] = A[0];
	repp(i,1,N) {
		if (i % 2 == 1) ans[0] += -A[i];
		else if (i % 2 == 0) ans[0] += A[i]; 
	}
	//ans[0] /= 2;
	repp(i,1,N) {
		ans[i] = 2 * A[i-1] - ans[i-1];
	}
	
	/*//ans[0] = A[0] - (A[1] - A[N-1]);
	rep(i,N) {
		if (i < N - 2) ans[i] = (A[i] - A[i+1] + A[i+2]) / 2;
		else if (i == N - 2) ans[i] = (A[i] );
		else if (i == N - 1) ans
		//ans[i] = A[i-1] - ans[i-1];
	}*/
	rep(i,N) cout << ans[i] << " ";
	cout << endl;

	return 0;
}