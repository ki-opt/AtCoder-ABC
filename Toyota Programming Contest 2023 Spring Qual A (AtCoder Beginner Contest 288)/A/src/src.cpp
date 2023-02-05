#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::cout; using std::cin;
using std::string; using std::endl;

int main() {
   int N;
   cin >> N;

   vector<int> a(N), b(N);
   for (int i = 0; i < N; i++) {
      cin >> a[i];
      cin >> b[i];
      cout << a[i] + b[i] << endl;
   }

   return 0;
}