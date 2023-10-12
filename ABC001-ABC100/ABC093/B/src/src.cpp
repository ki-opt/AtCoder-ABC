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
	long int A, B, K;
	cin >> A >> B >> K;
	
	//vector<int> check(B+1,0);
	unordered_map<int,int> check;
	repp(i,A+K,A) {
		if (i >= A && i <= B) {
			cout << i << endl;
			check[i] = 1;
		}
	}
	for(int i = B-K+1; i <= B; i++) {
		if (check.count(i) == 0 && i >= A && i <= B) cout << i << endl;
	}
	
	/*
	if ((B-A)%2==0) {
		if (K >= B - A - 1) {
			for(long int i = A; i < B + 1; i++) {
				cout << i << endl;
			}
			return 0;
		}
	} else {
		if (K >= B - A - 2) {
			for(long int i = A; i < B + 1; i++) {
				cout << i << endl;
			}
			return 0;
		}
	}

	for (long int i = A; i < A + K; i++) {
		cout << i << endl;
	}
	for (long int i = B - K + 1; i <= B; i++){
		cout << i << endl;
	}*/

	return 0;
}