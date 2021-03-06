#include <cstdio>
#include <cstring>

struct ListItem {
  int key;
  ListItem *next;
  ListItem *prev;
};

class List {
  ListItem *nil;

 public:
  List() {
    nil = new ListItem;
    nil->next = nil;
    nil->prev = nil;
  }

  ~List() { delete nil; }

  void insert(int key) {
    // printf("insert %d\n", key);
    ListItem *item = new ListItem;
    item->key = key;
    item->prev = nil;
    item->next = nil->next;
    nil->next = item;
    item->next->prev = item;
    // printAll();
    // printf("\n");
  }

  void del(int key) {
    // printf("delete %d\n", key);
    ListItem *item = nil->next;
    while (item != nil) {
      if (item->key == key) {
        // connect item->prev and item->next
        item->prev->next = item->next;
        item->next->prev = item->prev;
        delete item;
        break;
      }
      item = item->next;
    }
    // printAll();
    // printf("\n");
  }

  void deleteFirst() {
    // printf("deleteFirst\n");
    ListItem *item = nil->next;
    if (item != nil) {
      item->next->prev = item->prev;
      item->prev->next = item->next;
      delete item;
    }
    // printAll();
    // printf("\n");
  }

  void deleteLast() {
    // printf("deleteLast\n");
    ListItem *item = nil->prev;
    if (item != nil) {
      item->next->prev = item->prev;
      item->prev->next = item->next;
      delete item;
    }
    // printAll();
    // printf("\n");
  }

  void printAll() {
    // printf("printAll\n");
    ListItem *item = nil->next;
    // printf("%p\n", beforeFirst);
    // printf("%p\n", item);
    // printf("%p\n", afterLast);

    if (item == nil) {
      return;
    }
    printf("%d", item->key);

    while (nil != (item = item->next)) {
      printf(" %d", item->key);
      // printf("%d item:%p prev:%p next:%p [nil:%p]\n", item->key, item, item->prev, item->next, nil);
      // item = item->next;
    }
    printf("\n");
  }
};

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  List *l = new List();

  for (int i = 0; i < n; i++) {
    char op[20];
    scanf("%s", op);
    if (strcmp(op, "insert") == 0) {
      int k;
      scanf("%d", &k);
      l->insert(k);
    } else if (strcmp(op, "delete") == 0) {
      int k;
      scanf("%d", &k);
      l->del(k);
    } else if (strcmp(op, "deleteFirst") == 0) {
      l->deleteFirst();
    } else if (strcmp(op, "deleteLast") == 0) {
      l->deleteLast();
    }
  }

  l->printAll();
  delete l;
}