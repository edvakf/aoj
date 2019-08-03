#include <iostream>
using namespace std;

#define Nil -1

struct Node {
  int left;
  int right;
};

void preorder(Node nodes[], int id) {
  if (id == Nil) return;
  cout << " " << id;
  preorder(nodes, nodes[id].left);
  preorder(nodes, nodes[id].right);
}

void inorder(Node nodes[], int id) {
  if (id == Nil) return;
  inorder(nodes, nodes[id].left);
  cout << " " << id;
  inorder(nodes, nodes[id].right);
}

void postorder(Node nodes[], int id) {
  if (id == Nil) return;
  postorder(nodes, nodes[id].left);
  postorder(nodes, nodes[id].right);
  cout << " " << id;
}

int main() {
  int N;
  cin >> N;
  Node nodes[N];
  bool isChild[N];

  for (int i = 0; i < N; i++) {
    isChild[i] = false;
  }

  for (int i = 0; i < N; i++) {
    int id;
    cin >> id;
    cin >> nodes[id].left >> nodes[id].right;
    isChild[nodes[id].left] = true;
    isChild[nodes[id].right] = true;
  }

  int root;
  for (int i = 0; i < N; i++) {
    if (isChild[i] == false) {
      root = i;
      break;
    }
  }

  cout << "Preorder" << endl;
  preorder(nodes, root);
  cout << endl;
  cout << "Inorder" << endl;
  inorder(nodes, root);
  cout << endl;
  cout << "Postorder" << endl;
  postorder(nodes, root);
  cout << endl;
}