#include <algorithm>
#include <iostream>

using namespace std;

#define Nil -1

struct Node {
  int parent;
  int left;
  int right;
  int sibling;
  int height;
  int depth;
};

int findRoot(Node nodes[]) {
  int i = 0;
  while (nodes[i].parent != Nil) {
    i = nodes[i].parent;
  }
  return i;
}

void setDepth(Node nodes[], int id, int depth) {
  nodes[id].depth = depth;
  if (nodes[id].left != Nil) setDepth(nodes, nodes[id].left, depth + 1);
  if (nodes[id].right != Nil) setDepth(nodes, nodes[id].right, depth + 1);
}

int setHeight(Node nodes[], int id) {
  int left = nodes[id].left;
  int right = nodes[id].right;
  int hl = -1, hr = -1;
  if (left != Nil) hl = setHeight(nodes, left);
  if (right != Nil) hr = setHeight(nodes, right);

  return nodes[id].height = max(hl, hr) + 1;
}

int main() {
  int N;
  cin >> N;
  Node nodes[N];
  for (int i = 0; i < N; i++) {
    nodes[i].parent = Nil;
    nodes[i].sibling = Nil;
    // nodes[i].height = 0;
    // nodes[i].depth = 0;
  }
  for (int i = 0; i < N; i++) {
    int id, left, right;
    cin >> id >> left >> right;
    nodes[id].left = left;
    nodes[id].right = right;
    if (left != Nil) {
      nodes[left].parent = id;
      nodes[left].sibling = right;
    }
    if (right != Nil) {
      nodes[right].parent = id;
      nodes[right].sibling = left;
    }
  }

  int root = findRoot(nodes);
  setDepth(nodes, root, 0);
  setHeight(nodes, root);

  for (int i = 0; i < N; i++) {
    cout << "node " << i << ": parent = " << nodes[i].parent << ", sibling = " << nodes[i].sibling << ", degree = ";
    if (nodes[i].left == Nil && nodes[i].right == Nil) {
      cout << 0;
    } else if (nodes[i].left == Nil || nodes[i].right == Nil) {
      cout << 1;
    } else {
      cout << 2;
    }
    cout << ", depth = " << nodes[i].depth << ", height = " << nodes[i].height << ", ";
    if (i == root) {
      cout << "root";
    } else if (nodes[i].left == Nil && nodes[i].right == Nil) {
      cout << "leaf";
    } else {
      cout << "internal node";
    }
    cout << endl;
  }
}