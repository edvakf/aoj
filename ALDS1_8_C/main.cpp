#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Node {
  int key;
  Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

Node *find(int k) {
  Node *x = root;
  while (x != NIL) {
    if (k == x->key) {
      return x;
    } else if (k < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  return NIL;
}

void del(Node *z) {
  if (z == NIL) {
    return;
  }
  if (z->left == NIL && z->right == NIL) {
    if (z == root) {
      root = NIL;
    } else {
      if (z->parent->left == z) {
        z->parent->left = NIL;
      } else {
        z->parent->right = NIL;
      }
    }
    free(z);
  } else if (z->left == NIL) {
    if (z == root) {
      root = z->right;
    } else {
      if (z->parent->left == z) {
        z->parent->left = z->right;
      } else {
        z->parent->right = z->right;
      }
      z->right->parent = z->parent;
    }
    free(z);
  } else if (z->right == NIL) {
    if (z == root) {
      root = z->left;
    } else {
      if (z->parent->left == z) {
        z->parent->left = z->left;
      } else {
        z->parent->right = z->left;
      }
      z->left->parent = z->parent;
    }
    free(z);
  } else {
    Node *x = z->right;
    while (x->left != NIL) {
      x = x->left;
    }
    z->key = x->key;
    del(x);
  }
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  printf(" %d", u->key);
  inorder(u->right);
}
void preorder(Node *u) {
  if (u == NIL) return;
  printf(" %d", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, i, x;
  string com;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    cin >> com;
    if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "find") {
      scanf("%d", &x);
      if (find(x) != NIL) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    } else if (com == "delete") {
      scanf("%d", &x);
      Node *z = find(x);
      del(z);
    } else if (com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    }
  }

  return 0;
}
