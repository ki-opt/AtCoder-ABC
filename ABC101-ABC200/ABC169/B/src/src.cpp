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
// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}
int main() {
	ull N;
	cin >> N;
	vector<ull> A(N);
	rep(i,N) {
		cin >> A[i];
		if (A[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}

	ull ans = 1;
	rep(i,N) {
		if (overflow_if_mul(ans, A[i]) || ans * A[i] > (ull)pow(10,18)) {
			cout << -1 << endl;
			return 0;
		}
		ans *= A[i];
	}
	cout << ans << endl;
	return 0;
}