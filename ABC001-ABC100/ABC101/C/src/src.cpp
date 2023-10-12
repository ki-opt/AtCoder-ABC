#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, limit, init) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int ans = ceil(((double)(N - K) / (double)(K - 1))) + 1;
	cout << ans << endl;

	return 0;
}