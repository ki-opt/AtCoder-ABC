#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned long A, B;
	cin >> A >> B;

	unsigned int cnt = 0;
	while (A != B) {
		if (A > B) A -= B;
		else B -= A;		
		++cnt;
	}
	cout << cnt;
	return 0;
}