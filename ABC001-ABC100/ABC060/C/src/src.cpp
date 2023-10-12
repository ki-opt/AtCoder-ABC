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
	long int N, T;
	cin >> N >> T;
	vector<int> t(N);
	rep(i,N) cin >> t[i];

	long int ans = 0;
	rep(i,N-1) {
		if (t[i+1] - t[i] > T) ans += T;
		else ans += t[i+1] - t[i];
	}
	ans += T;

	cout << ans << endl;

	return 0;
}