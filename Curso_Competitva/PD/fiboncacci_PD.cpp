#include <iostream>
using namespace std;


int X[1000];


int fibonacci_PD(int n){
  if(X[n]!=0)return X[n];
  else{
    X[n]=fibonacci_PD(n-1)+fibonacci_PD(n-2);
    return X[n];
  }
}
int main() {
  X[1]=1;
  X[2]=1;
  int aux=fibonacci_PD(2);
  cout<<aux<<endl;
}
