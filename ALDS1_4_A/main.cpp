#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
  size_t n;
  cin >> n;
  int S[10010];
  for (size_t i = 0; i < n; i++) {
    cin >> S[i];
  }
  sort(S, S + n);

  size_t q;
  cin >> q;
  int T[510];
  for (size_t i = 0; i < q; i++) {
    cin >> T[i];
  }
  sort(T, T + q);

  int c = 0;
  size_t k = 0;
  for (size_t i = 0; i < q; i++) {  // T[i]
    while (S[k] < T[i] && k < n) {
      k++;
    }
    if (S[k] == T[i]) {
      c++;
    }
  }

  printf("%d\n", c);
  return 0;
}