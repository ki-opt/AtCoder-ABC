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
	int N, T, A;
	cin >> N >> T >> A;
	vector<int> H(N);
	rep(i,N) cin >> H[i];

	int ans = INT_MAX;
	double diff = 10000000;
	rep(i,N) {
		double temprature = (double)T - (double)H[i] * 0.006;
		if (abs((double)A - temprature) < diff) {
			diff = abs((double)A - temprature);
			ans = i + 1;
		}
	}
	cout << ans << endl;

	return 0;
}