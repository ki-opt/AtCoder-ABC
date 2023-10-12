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
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i,N) cin >> a[i];

	int ans = 0;
	int cnt = 1;
	rep(i,N){
		if (cnt == a[i]) {	
			cnt++;
		} else {
			ans++;
		}
	}
	if (ans == N) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}