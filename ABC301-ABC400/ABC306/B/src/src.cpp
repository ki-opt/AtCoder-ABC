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
	vector<int> A(64);
	rep(i,64) cin >> A[i];

	unsigned long int ans = 0;
	rep(i,64) {
		if (A[i] == 1) ans += (long int)pow(2,i);
	}
	cout << ans << endl;

	return 0;
}