#include <iostream>
using namespace std;

bool canimake(int m, int A[], int begin, int end) {
  // cout << "make " << m << " with ";
  // for (int i = begin; i < end; i++) {
  //   cout << A[i] << " ";
  // }
  // cout << endl;
  if (m == 0) {
    return true;
  } else if (m < 0) {
    return false;
  } else {  // m > 0
    for (int i = begin; i < end; i++) {
      if (canimake(m - A[i], A, i + 1, end)) {
        return true;
      }
    }
    return false;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int m;
    cin >> m;
    if (canimake(m, A, 0, n)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}