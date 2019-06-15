#include <algorithm>
#include <cstdio>

using namespace std;

int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      // printf("swap A[%d]=%d & A[%d]=%d\n", i, A[i], j, A[j]);
      swap(A[i], A[j]);
    }
  }
  // printf("swap A[%d]=%d & A[%d]=%d\n", i + 1, A[i + 1], r, A[r]);
  swap(A[i + 1], A[r]);
  return i + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  int q = partition(A, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      printf(" ");
    }
    if (i == q) {
      printf("[%d]", A[i]);
    } else {
      printf("%d", A[i]);
    }
  }
  printf("\n");
}