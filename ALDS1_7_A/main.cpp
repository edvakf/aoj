#include <cstdlib>
#include <iostream>

using namespace std;

#define Nil -1

struct Node {
  int parent;
  int left_child;
  int right_sibling;
};

int main() {
  int N;  // number of nodes
  cin >> N;

  Node nodes[N];

  for (int i = 0; i < N; i++) {
    nodes[i].parent = Nil;
    nodes[i].left_child = Nil;
    nodes[i].right_sibling = Nil;
  }

  for (int i = 0; i < N; i++) {
    int parent, degree;
    cin >> parent >> degree;
    int prev_child;
    for (int d = 0; d < degree; d++) {
      int child;
      cin >> child;
      nodes[child].parent = parent;
      if (d == 0) {
        nodes[parent].left_child = child;
      } else {
        nodes[prev_child].right_sibling = child;
      }
      prev_child = child;
    }
  }

  int depths[N];
  for (int i = 0; i < N; i++) {
    int depth = 0;
    int id = i;
    while (nodes[id].parent != Nil) {
      depth++;
      id = nodes[id].parent;
    }
    depths[i] = depth;
  }

  for (int i = 0; i < N; i++) {
    cout << "node " << i << ": parent = " << nodes[i].parent << ", depth = " << depths[i] << ", ";
    if (nodes[i].parent == Nil) {
      cout << "root";
    } else if (nodes[i].left_child == Nil) {
      cout << "leaf";
    } else {
      cout << "internal node";
    }
    cout << ", [";
    int child = nodes[i].left_child;
    bool first = true;
    while (child != Nil) {
      if (!first) {
        cout << ", ";
      }
      first = false;
      cout << child;
      child = nodes[child].right_sibling;
    }
    cout << "]" << endl;
  }
}