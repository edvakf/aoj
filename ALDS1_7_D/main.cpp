#include <iostream>

using namespace std;

void reorder(int Preorder[], int Inorder[], int Postorder[], int l, int a, int b, int c) {
  if (l == 0) return;

  int num = Preorder[a];
  Postorder[c + l - 1] = num;

  for (int i = 0; i < l; i++) {
    if (Inorder[b + i] == num) {
      reorder(Preorder, Inorder, Postorder, i, a + 1, b, c);
      reorder(Preorder, Inorder, Postorder, l - i - 1, a + i + 1, b + i + 1, c + i);
      break;
    }
  }
}

int main() {
  int N;
  cin >> N;

  int Preorder[N];
  int Inorder[N];
  int Postorder[N];

  for (int i = 0; i < N; i++) {
    cin >> Preorder[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> Inorder[i];
  }

  reorder(Preorder, Inorder, Postorder, N, 0, 0, 0);

  for (int i = 0; i < N; i++) {
    if (i != 0) cout << " ";
    cout << Postorder[i];
  }
  cout << endl;
}