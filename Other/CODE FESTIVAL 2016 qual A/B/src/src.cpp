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
	vector<int> a(N);
	rep(i,N) cin >> a[i];

	int ans = 0;
	rep(i,N) {
		if (a[a[i]-1] == i + 1) ans++;
	}	
	cout << ans / 2 << endl;

	return 0;
}