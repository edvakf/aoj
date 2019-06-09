// #include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  int stack[100];
  size_t head = 0;

  string term;

  while (cin >> term) {
    if (term == "+") {
      head--;
      stack[head - 1] = stack[head - 1] + stack[head];
    } else if (term == "-") {
      head--;
      stack[head - 1] = stack[head - 1] - stack[head];
    } else if (term == "*") {
      head--;
      stack[head - 1] = stack[head - 1] * stack[head];
    } else {
      // cout << term << endl << endl;
      int num = atoi(term.c_str());
      stack[head] = num;
      head++;
    }
  }
  // assert(head == 1);
  cout << stack[head - 1] << endl;

  return 0;
}
