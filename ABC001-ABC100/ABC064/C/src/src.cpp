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

	int free_num = 0;
	vector<int> ans(8,0);
	rep(i,N){
		if (a[i] < 3200) {
			ans[a[i]/400]++;
		} else {
			free_num++;
		}
	}

	int m = 0, M = 0;
	rep(i,8) {
		if (ans[i] > 0) m++;
	}
	if (m == 0) cout << 1 << " ";
	else cout << m << " ";

	//if (m + free_num > 8) cout << 8 << endl;
	//else 
	cout << m + free_num << endl;

	return 0;
}