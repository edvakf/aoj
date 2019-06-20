#include <algorithm>
#include <climits>
#include <cstdio>

using namespace std;

typedef struct Card {
  char suite[2];
  int num;
} Card;

int partition(Card A[], int p, int r) {
  Card x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j].num <= x.num) {
      i++;
      // printf("swap A[%d]=%d & A[%d]=%d\n", i, A[i], j, A[j]);
      swap(A[i], A[j]);
    }
  }
  // printf("swap A[%d]=%d & A[%d]=%d\n", i + 1, A[i + 1], r, A[r]);
  swap(A[i + 1], A[r]);
  return i + 1;
}

void quickSort(Card A[], int p, int r) {
  if (p < r) {
    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void merge(Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1 + 1];
  Card R[n2 + 1];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1].num = INT_MAX;
  R[n2].num = INT_MAX;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].num <= R[j].num) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(Card A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  Card A[n], B[n];
  for (int i = 0; i < n; i++) {
    scanf("%s %d", A[i].suite, &A[i].num);
    B[i] = A[i];
    // printf("%s %d\n", A[i].suite, A[i].num);
  }

  quickSort(A, 0, n - 1);
  mergeSort(B, 0, n);

  // for (int i = 0; i < n; i++) {
  //   printf("%s %d\n", B[i].suite, B[i].num);
  // }

  bool stable = true;
  for (int i = 0; i < n; i++) {
    if (!(A[i].num == B[i].num && A[i].suite[0] == B[i].suite[0])) {
      // printf("i=%d, A[i]=%s,%d, B[i]=%s,%d\n", i, A[i].suite, A[i].num, B[i].suite, B[i].num);
      printf("Not stable\n");
      stable = false;
      break;
    }
  }
  if (stable) {
    printf("Stable\n");
  }
  for (int i = 0; i < n; i++) {
    printf("%s %d\n", A[i].suite, A[i].num);
  }
}