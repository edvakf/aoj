#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  int diff = -1e9-1;

  int minv;
  cin >> minv; // drop 1st line
  cin >> minv;

  int n;
  while (cin >> n) {
    if (diff < n - minv) {
      diff = n - minv;
    }
    if (n < minv) {
      minv = n;
    }
  }
  cout << diff << endl;
  return 0;
}
