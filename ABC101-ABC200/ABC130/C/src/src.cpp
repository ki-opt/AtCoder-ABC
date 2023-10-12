#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	ll W, H, x, y;
	cin >> W >> H >> x >> y;

	if ((x * 2 == W && y * 2 == H)) {
		printf("%.10f 1\n", (double)W * (double)H / 2.0);	
		return 0;
	} else if (x * 2 == W) {
		printf("%.10f 0\n", (double)x * (double)H);
		return 0;
	} else if (y * 2 == H) {
		printf("%.10f 0\n", (double)y * (double)W);
		return 0;
	} else {
		printf("%.10f 0\n", (double)W * (double)H / 2.0);
	}

	return 0;
}