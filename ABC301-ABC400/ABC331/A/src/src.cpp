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
	int M, D;
	int y, m, d;
	cin >> M >> D >> y >> m >> d;

	if (d + 1 <= D) {
		cout << y << " " << m << " " << d + 1 << endl;
	} else if (m + 1 <= M) {
		cout << y << " " << m + 1 << " " << 1 << endl;
	} else {
		cout << y + 1 << " " << 1 << " " << 1 << endl;
	}

	return 0;
}