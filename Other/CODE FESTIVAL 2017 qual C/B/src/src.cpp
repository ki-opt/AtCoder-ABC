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
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	int comb = (int)pow(3,N);
	int dec = 1;
	rep(i,N) {
		if (A[i] % 2 == 0) {
			dec = dec * 2;
		}
	}
	cout << comb - dec << endl;
	
	

	return 0;
}