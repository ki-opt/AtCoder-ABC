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
	vector<int> H(N);
	rep(i,N) cin >> H[i];
	
	int max = 0;
	rep(i,N-1) {
		int cur_num = H[i];
		if (cur_num >= H[i+1]) {
			int cnt = 0;
			repp(j,N,i+1) {
				if (cur_num >= H[j]) cnt++;
				else break;
				cur_num = H[j];
				i = j - 1;
			}
			if (cnt > max) max = cnt;
		}
	}
	cout << max << endl;

	return 0;
}