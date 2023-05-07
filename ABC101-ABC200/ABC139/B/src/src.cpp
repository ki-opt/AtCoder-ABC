#include <iostream>
#include <vector>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	
	if (B == 1) {
		cout << 0 << endl;
		return 0;
	}

	int cnt = 0;
	for (int i = 0;; i++) {
		if (i == 0) {
			cnt = A;
		}
		else {
			cnt += A - 1;
		}
		if (cnt >= B) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}