#include <iostream>
#include <string>
#include <vector>

using namespace std;

int selectionSort(vector<int> &nums) {
  int swapcount = 0;

  for (size_t i = 0; i < nums.size() - 1; i++) {
    size_t minj = i;
    for (size_t j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      // cout << "swap " << nums[i] << " and " << nums[minj] << endl;
      int tmp = nums[minj];
      nums[minj] = nums[i];
      nums[i] = tmp;
      swapcount++;
    }
  }

  return swapcount;
}

void printVector(vector<int> v) {
  for (size_t i = 0; i < v.size(); i++) {
    if (i > 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
}

int main(int argc, char **argv) {
  vector<int> nums;

  size_t N;
  cin >> N;

  for (size_t i = 0; i < N; i++) {
    int ti;
    cin >> ti;
    nums.push_back(ti);
  }
  // printVector(nums);

  int swapcount = selectionSort(nums);

  printVector(nums);
  cout << swapcount << endl;

  return 0;
}
