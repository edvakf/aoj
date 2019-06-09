#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cnt;

void insertionSort(vector<int> &A, size_t n, size_t g) {  // n,g = 5,4 -> 5,1
  for (size_t i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;  // use int because j = j - g can be negative
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(vector<int> &A, size_t n) {
  cnt = 0;
  size_t G[100];
  int m = ceil(log2(n));
  cout << m << endl;
  size_t i = 0;
  for (; i < m; i++) {
    G[i] = pow(2, m - 1 - i);
    cout << G[i] << " ";

    insertionSort(A, n, G[i]);
  }
  cout << 1 << endl;
  G[i] = 1;
  insertionSort(A, n, G[i]);
}

int main(int argc, char **argv) {
  size_t n;
  vector<int> A;

  cin >> n;
  for (size_t i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    A.push_back(tmp);
  }

  shellSort(A, n);

  cout << cnt << endl;

  for (size_t i = 0; i < n; i++) {
    // if (i > 0) cout << endl;
    cout << A[i] << endl;
  }

  return 0;
}