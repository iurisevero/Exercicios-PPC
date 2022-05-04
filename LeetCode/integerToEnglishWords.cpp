#include <bits/stdc++.h>

using namespace std;

map<int, string> complement {
  {0, "Hundred"}, {1, "Thousand"}, {2, "Million"}, {3, "Billion"}
};

map<int, string> unit {
  {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
  {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}
};

map<int, string> ten {
  {1, ""}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"},
  {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
};

map<int, string> ten_corner_cases {
  {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
  {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
};

string intToString(int num){
  if(num == 0)
    return "Zero";

  vector<string> numbers;
  int count = 0;
  while(num != 0){
    if(count > 0 && num % 1000 > 0) numbers.push_back(complement[count]);

    if(ten_corner_cases.count(num % 100)){
      numbers.push_back(ten_corner_cases[num % 100]);
      num /= 100;
    }else{
      if(num%10 > 0)
        numbers.push_back(unit[num%10]);
      num /= 10;

      if(num%10 > 0)
        numbers.push_back(ten[num%10]);
      num /= 10;
    }

    if(num % 10 > 0){
      numbers.push_back(complement[0]);
      numbers.push_back(unit[num%10]);
    }
    num /= 10;
    count++;
  }

  string out = "";
  size_t _size = numbers.size();
  reverse(numbers.begin(), numbers.end());
  for(size_t i=0; i < _size; ++i) out += numbers[i] + (i+1 < _size? " " : "");

  return out;
}

int main(){
  int num;
  cin >> num;
  cout << intToString(num) << endl;
  return 0;
}