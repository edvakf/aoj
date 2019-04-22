#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bubbleSort(vector<int> &nums) {
  int swapcount = 0;

  bool flag = true;

  while (flag) {
    flag = false;
    for (size_t j = nums.size() - 1; j > 0; --j) {
      if (nums[j] < nums[j-1]) {
        int tmp = nums[j];
        nums[j] = nums[j-1];
        nums[j-1] = tmp;
        swapcount++;
        flag = true;
      }
    }
  }

  return swapcount;
}

int main(int argc, char** argv) {
  vector<int> nums;

  size_t N;
  cin >> N;

  for (size_t i = 0; i < N; i++) {
    int ti;
    cin >> ti;
    nums.push_back(ti);
  }

  int swapcount = bubbleSort(nums);

  for (size_t i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << nums[i];
  }
  cout << endl;
  cout << swapcount << endl;

  return 0;
}

