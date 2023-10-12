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
	vector<long int> L(N+1);
	L[0] = 2;
	L[1] = 1;
	repp(i,N+1,2) {
		L[i] = L[i-1] + L[i-2];
	}
	cout << L[N] << endl;

	return 0;
}