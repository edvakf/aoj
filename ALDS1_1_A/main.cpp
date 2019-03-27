#include <iostream>
#include <string>
#include <vector>
#include <iterator>  // std::ostream_iterator
#include <algorithm> // std::copy
#include <sstream>   // std::stringstream
//#include <iterator>  // std::back_inserter

using namespace std;

void output(vector<int> nums) {
  copy(nums.begin(), nums.end()-1, ostream_iterator<int>(cout, " "));
  cout << nums.back() << endl;
}

int main(int argc, char** argv) {
  vector<int> nums;

  string tmp;

  getline(cin, tmp); // drop 1st line
  getline(cin, tmp); // 2nd line

  stringstream ss(tmp);
  int ti;
  while (ss >> ti) {
    nums.push_back(ti);
  }

  //copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(nums));

  output(nums);

  for(int i = 1; i < (int)nums.size(); ++i) {
    int v = nums[i];
    int j = i - 1;
    while(j >= 0 && nums[j] > v) {
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = v;

    output(nums);
  }

  return 0;
}

