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
	long int fact_val = pow(10,9)+7;
	cin >> N;

	long int ans = 1;
	for (int i = 1; i < N+1; i++) {
		ans = (i * ans) % fact_val;
	}	
	cout << ans << endl;


	return 0;
}