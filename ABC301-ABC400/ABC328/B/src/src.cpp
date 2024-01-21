#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>
#include <queue>

using ull=unsigned long long;
using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	rep(i,N) cin >> D[i];

	int ans = 0;
	rep(i,N) {
		int tmp_i = i+1;
		int bef = tmp_i % 10;
		tmp_i /= 10;
		bool aaa = true;
		while(tmp_i != 0) {
			int v = tmp_i % 10;
			if (v != bef) {
				aaa = false;
				break;
			}
			tmp_i /= 10;
		}
		if (!aaa) continue;
		tmp_i = (i+1) % 10;
		repp(j,1,D[i]+1) {
			int tmp = j;
			bool flag = true;
			while (tmp != 0) {
				int val = tmp % 10;
				if (val != tmp_i) {
					flag = false;
					break;
				}
				tmp /= 10;
			}
			if (flag) {
				cerr << i+1 << " " << j << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}