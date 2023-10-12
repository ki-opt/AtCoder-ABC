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
	int N;
	cin >> N;
	vector<int> P(N);
	rep(i,N) cin >> P[i];

	int ans = 1;
	int min_value = P[0];
	repp(i,N,1) {
		if (P[i] <= min_value) {
			ans++;
			min_value = P[i];
		}
	}
	cout << ans << endl;
	return 0;
}