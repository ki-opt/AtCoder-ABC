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
	long int X, Y;
	cin >> X >> Y;

	int ans = 0;
	long int A = X;
	while(A >= X && A <= Y) {
		ans++;
		A *= 2;
	}
	cout << ans << endl;

	return 0;
}