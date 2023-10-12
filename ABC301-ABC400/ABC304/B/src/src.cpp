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

	if (N <= pow(10,3)-1) cout << N << endl;
	else if (N <= pow(10,4)-1) cout << (N / 10) * 10 << endl;
	else if (N <= pow(10,5)-1) cout << (N / 100) * 100 << endl;
	else if (N <= pow(10,6)-1) cout << (N / 1000) * 1000 << endl;
	else if (N <= pow(10,7)-1) cout << (N / 10000) * 10000 << endl;
	else if (N <= pow(10,8)-1) cout << (N / 100000) * 100000 << endl;
	else if (N <= pow(10,9)-1) cout << (N / 1000000) * 1000000 << endl;

	return 0;
}