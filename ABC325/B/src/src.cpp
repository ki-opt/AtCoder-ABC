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
	int N;
	cin >> N;
	vector<int> W(N), X(N);
	rep(i,N) {
		cin >> W[i] >> X[i];
	}

	int ans = 0;
	repp(i,0,24) {
		int tmp = 0;
		rep(j,N) {
			int t = (i+X[j]) % 24;
			if (t >= 9 && t < 18) tmp += W[j];
		}
		ans = max(ans,tmp);
	}

	cout << ans << endl;

	return 0;
}