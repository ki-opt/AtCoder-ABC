#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long int H;
	cin >> H;

	int depth = log2(H) + 1;
	
	long int sum = 0;
	for (int i = 0; i < depth; i++) {
		sum += (long int)pow(2,i);
	}

	cout << sum << endl;

	return 0;
}