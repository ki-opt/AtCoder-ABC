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
	int N, K;
	cin >> N >> K;
	vector<unsigned int> h(N);
	rep(i,N) cin >> h[i];

	sort(h.begin(),h.end());
	unsigned int max_num = h[0], min_num = h[K-1];
	unsigned int ans = INT_MAX;
	for (int i = 0; i < N - K + 1; i++) {
		min_num = h[i];
		max_num = h[i+K-1];
		if (max_num - min_num < ans) ans = max_num - min_num;
	}
	cout << ans << endl;

	return 0;
}