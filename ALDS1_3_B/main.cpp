#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue {
  size_t head;
  size_t tail;
  T q[1000000];

 public:
  Queue() : head(0), tail(0) {}

  void enqueue(T item) {
    q[tail] = item;
    tail++;
  }

  T dequeue() {
    // assert(head < tail);
    return q[head++];
  }

  bool isempty() { return head >= tail; }
};

struct Proc {
  string name;
  int time;

  Proc(string _name, int _time) : name(_name), time(_time) {}
};

int main(int argc, char **argv) {
  size_t num;
  int quantum;
  int time = 0;
  Queue<Proc *> queue;

  cin >> num >> quantum;

  for (size_t i = 0; i < num; i++) {
    string name;
    int time;
    cin >> name >> time;
    Proc *p = new Proc(name, time);
    queue.enqueue(p);
  }

  while (true) {
    // cout << "time: " << time << endl;
    if (queue.isempty()) {
      break;
    }
    Proc *p = queue.dequeue();
    if (p->time > quantum) {
      time += quantum;

      p->time -= quantum;
      queue.enqueue(p);
      // cout << "send " << p->name << " back" << endl;
    } else {
      cout << p->name << " " << time + p->time << endl;
      time += p->time;
      delete p;
    }
  }

  return 0;
}