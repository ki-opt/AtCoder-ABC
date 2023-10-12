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
	int A, B;
	cin >> A >> B;

	int ans = 0;
	repp(i,B+1,A) {
		vector<int> a(5);
		int value = i;
		a[0] = (value % 10); value /= 10;
		a[1] = (value % 10); value /= 10;
		a[2] = (value % 10); value /= 10;
		a[3] = (value % 10); value /= 10;
		a[4] = (value % 10); value /= 10;

		if (a[4] == a[0] && a[3] == a[1]) ans++;
	}

	cout << ans << endl;

	return 0;
}