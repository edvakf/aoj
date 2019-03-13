#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  vector<int> nums;

  string tmp;

  getline(cin, tmp); // drop 1st line

  while (getline(cin, tmp)) {
    stringstream ss(tmp);
    int ti;
    ss >> ti;
    nums.push_back(ti);
  }

  int minv = nums[0];
  int diff = nums[1] - nums[0];

  //for(int n: nums){
  for(int i = 1; i < (int)nums.size(); ++i) {
    int n = nums[i];
    if (diff < n - minv) {
      //cout << n << " " << minv << endl;
      diff = n - minv;
    }
    if (n < minv) {
      //cout << n << endl;
      minv = n;
    }
  }

  cout << diff << endl;
  return 0;
}
