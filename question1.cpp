# include <iostream>
# include <vector>
using namespace std;

vector<int> constructPrefixSum(vector<int> &numbers){
  vector<int> result;
  result.push_back(0);
  for(int num : numbers){
    result.push_back(result.back() + num);
  }
  return result;
}

int getSum(vector<int> &prefixSum, int from, int to){
  return prefixSum[to+1] - prefixSum[from];
}

int findPosition(vector<int> &numbers){
  vector<int> prefixSum = constructPrefixSum(numbers);
  int n = numbers.size();
  for(int i=0; i<n; i++){
    if(getSum(prefixSum, 0, i-1) == getSum(prefixSum, i+1, n-1))
      return i;
  }
  return -1;
}

int main(){
  int n;
  cin >> n;
  vector<int> numbers;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    numbers.push_back(x);
  }
  cout << findPosition(numbers) << endl;
}