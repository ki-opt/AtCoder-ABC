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
	int N, H, X;
	cin >> N >> H >> X;
	vector<int> P(N);
	rep(i,N) cin >> P[i];

	rep(i,N) {
		if (H + P[i] >= X) {
			cout << i+1 << endl;
			return 0;
		}
	}


	return 0;
}