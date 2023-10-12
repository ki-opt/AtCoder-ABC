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
	int X;
	cin >> X;

	int ans = 0;
	for(int b = 1; b < 1000; b++) {
		if (b == 1) {
			if (b <= X) ans = b;
		} else {
			int tmp = pow(b,2);
			for (int p = 2; tmp <= X; p++) {
				if (tmp > ans) ans = tmp;
				tmp = pow(b,p+1);
			}
		}
	}
	cout << ans << endl;

	return 0;
}