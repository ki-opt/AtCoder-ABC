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
	vector<int>a(N);
	rep(i,N) cin >> a[i];

	//int min_val = *min_element(a.begin(),a.end());
	//int max_val = *max_element(a.begin(),a.end());

	vector<int> histogram(100001,0);
	rep(i,N) histogram[a[i]]++;

	int ans = 0;
	if (N >= 3) {
		repp(i,N-1,1){
			int tmp = histogram[i-1]+histogram[i]+histogram[i+1];
			if (tmp > ans) ans = tmp;
		}
	} else {
		if (N == 1) {
			cout << 1 << endl;
			return 0;
		} else {
			if (abs(a[0] - a[1]) <= 1) cout << 2 << endl;
			else cout << 1 << endl;
			return 0;
		}
	}

	cout << ans << endl;

	return 0;
}