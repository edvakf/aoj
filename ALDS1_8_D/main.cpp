#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Node {
  int key;
  int pri;
  Node *left, *right;
};

Node *NIL;

class Treap {
  Node *root;

  Node *rightRotate_(Node *t) {
    Node *s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
  }

  Node *leftRotate_(Node *t) {
    Node *s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
  }

  Node *insert_(Node *t, int k, int p) {
    if (t == NIL) {
      Node *x = (Node *)malloc(sizeof(Node));
      x->key = k;
      x->pri = p;
      x->left = NIL;
      x->right = NIL;
      return x;
    }
    if (k == t->key) {
      return t;
    }
    if (k < t->key) {
      t->left = insert_(t->left, k, p);
      if (t->pri < t->left->pri) {
        t = rightRotate_(t);
      }
    } else {
      t->right = insert_(t->right, k, p);
      if (t->pri < t->right->pri) {
        t = leftRotate_(t);
      }
    }

    return t;
  }

  Node *delete_(Node *t, int k) {
    if (t == NIL) {
      return NIL;
    }
    if (k < t->key) {
      t->left = delete_(t->left, k);
      return t;
    } else if (k > t->key) {
      t->right = delete_(t->right, k);
      return t;
    } else {
      if (t->left == NIL && t->right == NIL) {
        free(t);
        return NIL;
      } else if (t->left == NIL) {
        t = leftRotate_(t);
        return delete_(t, k);
      } else if (t->right == NIL) {
        t = rightRotate_(t);
        return delete_(t, k);
      } else {
        if (t->left->pri > t->right->pri) {
          t = rightRotate_(t);
          return delete_(t, k);
        } else {
          t = leftRotate_(t);
          return delete_(t, k);
        }
      }
    }
  }

  Node *find_(Node *t, int k) {
    if (t == NIL) {
      return NIL;
    }
    if (k < t->key) {
      return find_(t->left, k);
    } else if (k > t->key) {
      return find_(t->right, k);
    } else {
      return t;
    }
  }

  void inorder_(Node *u) {
    if (u == NIL) return;
    inorder_(u->left);
    cout << " " << u->key;
    inorder_(u->right);
  }

  void preorder_(Node *u) {
    if (u == NIL) return;
    cout << " " << u->key;
    preorder_(u->left);
    preorder_(u->right);
  }

 public:
  Treap() { root = NIL; }

  void ins(int k, int p) { root = insert_(root, k, p); }

  void del(int k) { root = delete_(root, k); }

  void find(int k) {
    if (find_(root, k) != NIL) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  void print() {
    inorder_(root);
    cout << endl;
    preorder_(root);
    cout << endl;
  }
};

int main() {
  int n;
  cin >> n;

  Treap *tr;

  for (int i = 0; i < n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "insert") {
      int k, p;
      cin >> k >> p;
      tr->ins(k, p);
    } else if (cmd == "find") {
      int k;
      cin >> k;
      tr->find(k);
    } else if (cmd == "delete") {
      int k;
      cin >> k;
      tr->del(k);
    } else if (cmd == "print") {
      tr->print();
    }
  }
}