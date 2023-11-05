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
	repp(i,N,1000) {
		int iti, ni, san;
		int tmp = i;
		iti = tmp % 10;
		tmp /= 10;
		ni = tmp % 10;
		tmp /= 10;
		san = tmp % 10;
		if (ni * san == iti) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}