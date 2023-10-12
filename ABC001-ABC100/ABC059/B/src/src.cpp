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
	string A, B;
	cin >> A >> B;
	if (A.size() > B.size()) {
		cout << "GREATER" << endl;
	} else if (A.size() < B.size()) {
		cout << "LESS" << endl;
	} else {
		rep(i, A.size()) {
			int a = A[i] - '0', b = B[i] - '0';
			if (a > b) {
				cout << "GREATER" << endl;
				return 0;
			} else if (a < b) {
				cout << "LESS" << endl;
				return 0;
			}
		}
		cout << "EQUAL" << endl;
	}
	return 0;
}