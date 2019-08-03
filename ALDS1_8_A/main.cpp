#include <iostream>
#include <string>

using namespace std;

struct Node {
  int v;
  int l;
  int r;
  int p;
};

#define N 500000
#define Nil -1

void insert(Node nodes[], int z) {
  if (z == 0) {
    return;
  }
  int y = Nil;  // parent of x
  int x = 0;    // root
  while (x != Nil) {
    y = x;
    if (nodes[z].v < nodes[x].v) {
      x = nodes[x].l;
    } else {
      x = nodes[x].r;
    }
  }
  nodes[z].p = y;

  if (y == Nil) {  // nodes is an empty tree

  } else if (nodes[z].v < nodes[y].v) {
    nodes[y].l = z;
  } else {
    nodes[y].r = z;
  }
}

void printInorder(Node nodes[], int n) {
  if (n == Nil) return;
  printInorder(nodes, nodes[n].l);
  cout << " " << nodes[n].v;
  printInorder(nodes, nodes[n].r);
}

void printPreorder(Node nodes[], int n) {
  if (n == Nil) return;
  cout << " " << nodes[n].v;
  printPreorder(nodes, nodes[n].l);
  printPreorder(nodes, nodes[n].r);
}

void print(Node nodes[]) {
  printInorder(nodes, 0);
  cout << endl;
  printPreorder(nodes, 0);
  cout << endl;
}

int main() {
  Node nodes[N];
  for (int i = 0; i < N; i++) {
    nodes[i].l = Nil;
    nodes[i].r = Nil;
    nodes[i].p = Nil;
  }

  int L;
  cin >> L;
  int n = 0;
  for (int i = 0; i < L; i++) {
    string cmd;
    cin >> cmd;
    if (cmd[0] == 'i') {
      cin >> nodes[n].v;
      if (n != 0) insert(nodes, n);
      n++;
    } else if (cmd[0] == 'p') {
      if (n != 0) print(nodes);
    }
  }
}