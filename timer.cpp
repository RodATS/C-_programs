#include<iostream>
#include <time.h>
using namespace std;

int main(){

  unsigned t0, t1;
  t0=clock();
  //funcion
  t1=clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
