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
	int N, M;
	cin >> N >> M;
	vector<int> X(M);
	rep(i,M) cin >> X[i];

	if (N >= M) {
		cout << 0 << endl;
		return 0;
	}

	sort(X.begin(),X.end());
	vector<int> diff(M-1,0);
	int ans = 0;
	rep(i,M-1) {
		diff[i] = X[i+1] - X[i];
		ans += diff[i];
	}
	
	sort(diff.begin(),diff.end(),greater<int>());
	rep(i,N-1) {
		ans -= diff[i];
	}
	cout << ans << endl;

	return 0;
}