#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long int N, A, B;
	cin >> N >> A >> B;

	long int b_sum = (N / (A + B)) * A;
	long int res = N % (A + B);
	if (res <= A) b_sum += res;
	else b_sum += A;
	
	if (A == 0) cout << 0 << endl;
	else cout << b_sum << endl;

	return 0;
}