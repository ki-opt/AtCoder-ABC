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
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int ans = 0;
	ans += A * X + B * Y;

	int ans_tmp = 0;
	if (X > Y) {
		ans_tmp = C * 2 * X;
		if (ans > ans_tmp) ans = ans_tmp; 
	} else {
		ans_tmp = C * 2 * Y;
		if (ans > ans_tmp) ans = ans_tmp;
	}
	ans_tmp = 0;
	if (X > Y) {
		ans_tmp = C * 2 * Y;
		ans_tmp += (X - Y) * A;
		if (ans > ans_tmp) ans = ans_tmp;
	} else {
		ans_tmp = C * 2 * X;
		ans_tmp += (Y - X) * B;
		if (ans > ans_tmp) ans = ans_tmp;
	}
	cout << ans << endl;
	return 0;
}