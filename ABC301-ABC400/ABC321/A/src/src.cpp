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
	if (N < 10) {
		cout << "Yes" << endl;
		return 0;
	}
	
	int cnt = 0;
	int keta = N % 10;
	while(N != 0) {
		if (cnt != 0) {
			if (N % 10 <= keta) {
				cout << "No" << endl;
				return 0;
			}
		}
		keta = N % 10;
		N /= 10;
		cnt++;
	}
	cout << "Yes" << endl;
	return 0;
}