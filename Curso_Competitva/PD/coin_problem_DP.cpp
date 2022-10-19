#include <iostream>
#include <queue>
using namespace std;

int X[1000];

int coin(int n, int dp[3]){
  if(n==0)return X[n];
  if(n<0) return 10000;
  if(X[n]!=0) return X[n];
  priority_queue<int, vector<int>, greater<int> > sol;
  for(int i=0;i<3;i++){
    int s=coin(n-dp[i],dp);
    sol.push(s);
  }
  X[n]=sol.top()+1;
  return X[n];
}

int main() {
  const int n=3;
  int dp[n]={1,3,4};
  X[0]=1;
  for(int i=0;i<n;i++)
    X[dp[i]]=1;
  
  cout<<coin(10,dp)<<endl;

  
}
