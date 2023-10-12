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
	int D, N;
	cin >> D >> N;
	
	int num = pow(100,D);
	if (N == 100) cout << num * (N+1) << endl;
	else cout << num * N << endl;

	return 0;
}