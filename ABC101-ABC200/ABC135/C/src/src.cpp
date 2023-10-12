#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	long int N;
	cin >> N;
	vector<long int> A(N+1), B(N);
	rep(i,N+1) cin >> A[i];
	rep(i,N) cin >> B[i];

	long int ans = 0;
	rep(i,N-1) {
		if (A[i] > B[i]) {
			ans += B[i];
			A[i] -= B[i];
		} else if (A[i] <= B[i]) {
			ans += A[i];
			B[i] -= A[i];
			if (A[i+1] >= B[i]) {
				B[i+1] += B[i];
			} else {
				B[i+1] += A[i+1];
			}
		}
	}
	if (A[N-1] + A[N] > B[N-1]) ans += B[N-1];
	else ans += A[N-1] + A[N];
	cout << ans << endl;

	return 0;
}