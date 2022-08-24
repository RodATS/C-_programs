#include <iostream>
using namespace std;


int expo_rap_2(int valor, int n){
  if(n==1) return valor;
  else{
    return expo_rap_2(valor,n/2)*expo_rap_2(valor,n/2);
  }
}


int expo_rap_1(int valor, int n){
  if(n%2!=0){
    n-=1;
    return valor*expo_rap_2(valor, n);
  }
  return expo_rap_2(valor,n);
  
}


int main() {
  cout<<(expo_rap_1(3,4));
}
