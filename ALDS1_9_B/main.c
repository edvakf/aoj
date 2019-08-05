#include <stdio.h>

int parent(int i) {
  return i / 2;
}
int left(int i) {
  return i * 2;
}
int right(int i) {
  return i*2 + 1;
}

void maxHeapify(int A[], int H, int i) {
  int l = left(i);
  int r = right(i);

  int largest ;
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {
    int tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    maxHeapify(A, H, largest);
  }
}

void buildMaxHeap(int A[], int H) {
  for (int i = H / 2; i >= 1; i--) {
    maxHeapify(A, H, i);
  }
}

int main() {
  int H;
  scanf("%d", &H);

  int A[H+1];

  for (int i = 1; i <= H; i++) {
    scanf("%d", &A[i]);
  }

  buildMaxHeap(A, H);

  for (int i = 1; i <= H; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");
}
