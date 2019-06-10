#include <cstdio>

using namespace std;

bool binarySearch(int A[], size_t N, int a) {
  size_t p = 0, q = N;
  while (p < q) {
    size_t i = (p + q) / 2;
    if (A[i] == a) {
      return true;
    }
    if (A[i] < a) {
      p = i + 1;
    } else {
      q = i;
    }
  }
  return false;
}

int main(void) {
  size_t n;
  scanf("%zu", &n);
  int S[110000];
  for (size_t i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  int c = 0;

  size_t q;
  scanf("%zu", &q);
  for (size_t i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (binarySearch(S, n, t)) {
      c++;
    }
  }

  printf("%d\n", c);
  return 0;
}