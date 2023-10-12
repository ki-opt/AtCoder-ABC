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
	long int N, K, Q;
	cin >> N >> K >> Q;
	vector<int> A(Q);
	rep(i,Q) cin >> A[i];

	int threshold = 0;
	vector<long int> ans(N,K);
	rep(i,Q) {
		ans[A[i]-1]++;
		threshold++;
	}

	rep(i,N) {
		if (ans[i] <= threshold) cout << "No" << endl;
		else cout << "Yes" << endl;
	}

	return 0;
}