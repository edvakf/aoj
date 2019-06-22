#include <cstdio>

void countingSort(int n, int A[], int B[], int k) {
  int C[k + 1];
  for (int i = 0; i <= k; i++) C[i] = 0;

  for (int j = 0; j < n; j++) C[A[j]]++;

  for (int i = 1; i <= k; i++) C[i] += C[i - 1];

  for (int j = n - 1; j >= 0; j--) {
    B[C[A[j]] - 1] = A[j];
    C[A[j]]--;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  int B[n];
  countingSort(n, A, B, 10000);

  for (int i = 0; i < n; i++) {
    if (i != 0) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
}