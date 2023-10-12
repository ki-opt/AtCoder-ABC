#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <string>

using ll=long long;
using namespace std;

#define rep(iter, limit) for (int iter = 0; iter < (int)(limit); iter++)
#define repp(iter, init, limit) for (int iter = (int)init; iter < (int)(limit); iter++)

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> D(K), check(10);
	rep(i,K) {
		cin >> D[i];
		check[D[i]] = 1;
	}

	int i = N;
	while (1) {
		int tmp = i;
		while(tmp != 0) {
			int val = tmp % 10;
			if (check[val] == 1) break;
			tmp /= 10;
		}
		if (tmp == 0) {
			cout << i << endl;
			return 0;
		}
		i++;
	}


	return 0;
}