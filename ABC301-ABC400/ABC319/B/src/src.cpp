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

	rep(i,N+1) {
		bool flag = false;
		repp(j,1,10) {
			if (N % j == 0) {
				rep(k,1001) {
					if (i == (N / j) * k) {
						cout << j;
						flag = true;
					}
					if (flag) break;
				}
			}
			if (flag) break;
		}
		if (!flag) cout << '-';
	}
	cout << endl;

	return 0;
}