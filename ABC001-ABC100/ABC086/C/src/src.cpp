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
	int N;
	cin >> N;
	vector<int> t(N), x(N), y(N);
	rep(i,N) cin >> t[i] >> x[i] >> y[i];

	int now_t = 0;
	int now_x = 0, now_y = 0;
	rep(i,N) {
		int dist = abs(x[i] - now_x) + abs(y[i] - now_y);
		if (dist + now_t > t[i]) {
			cout << "No" << endl;
			return 0;
		}
		int tmp = t[i] - (dist + now_t);
		if (tmp % 2 != 0) {
			cout << "No" << endl;
			return 0;
		}
		now_x = x[i];
		now_y = y[i];
		now_t = t[i];
	}
	cout << "Yes" << endl;

	return 0;
}