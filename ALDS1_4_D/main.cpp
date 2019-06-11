#include <cstdio>

bool max_truck_load_is_enough_for_the_trucks(int w[], int n, int k, int P) {
  int c = 0;
  int e = 0;
  // printf("k=%d, P=%d\n", k, P);
  for (int i = 0; i < n; i++) {
    if (w[i] > P) {
      return false;  // P is too small for the packet
    }
    if (e + w[i] > P) {
      e = 0;
      c++;
    }
    e += w[i];  // load of this truck
  }
  c++;
  return c <= k;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int avg = 0;
  int w[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    avg += w[i];
  }
  avg /= k;
  int a = avg / 2;  // lower bound of P
  while (max_truck_load_is_enough_for_the_trucks(w, n, k, a)) {
    a /= 2;
  }
  int b = avg * 2;  // upper bound of P
  while (!max_truck_load_is_enough_for_the_trucks(w, n, k, b)) {
    b *= 2;
  }

  while (a + 1 < b) {
    int d = (a + b) / 2;  // P at this iteration
    // printf("a=%d, b=%d, d=%d\n", a, b, d);

    if (max_truck_load_is_enough_for_the_trucks(w, n, k, d)) {
      // printf("enough\n");
      b = d;
    } else {
      // printf("not enough\n");
      a = d;
    }
  }

  printf("%d\n", b);
}