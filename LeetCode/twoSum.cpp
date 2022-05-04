#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;

pair<int, int> twoSum(vector<int>& nums, int target){
  int _size = nums.size();
  unordered_set<int> found_values;
  for(int i=0; i < _size; ++i){
    if(found_values.count(target - nums[i])){
      for(int j=0; j < i; ++j)
        if(nums[j] == target- nums[i])
          return {i, j};
    }
    found_values.insert(nums[i]);
  }
  return {-1, -1};
}

int main(){
  vector<int> nums = {3, 2, 4};
  int target = 6;
  pair<int, int> two_sum = twoSum(nums, target);
  cout << "[" << two_sum.first << "," << two_sum.second << "]\n";
  return 0;
}