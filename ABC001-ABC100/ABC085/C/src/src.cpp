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
	long int N, Y;
	cin >> N >> Y;
	
	repp(i,N+1,0) {
		long int tmp = i * 10000;
		repp(j,N+1,0) {
			if (N - (i + j) < 0) continue;
			long int ans = tmp + j * 5000 + (N-(i+j)) * 1000;
			if (ans == Y) {
				cout << i << " " << j << " " << N-(i+j) << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}