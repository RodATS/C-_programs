#include <iostream>
using namespace std;


//Tipo 1
int gVect[10];
int gnCount=0;

void Insert(int elem){
  if(gnCount<10){
    gVect[gnCount]=elem;
    gnCount++;
  }
}

void Remove(){
  if(gnCount>0){
    gVect[gnCount]=0;
    gnCount--;
  }
}

void Print(){
  for(int i=0;i<gnCount;i++){
    cout<<gVect[i]<<"\t";
  }
  cout<<endl;
}

int main() {
  Insert(5);
  Insert(1);
  Insert(2);
  Insert(8);
  Insert(20);
  Print();
  Remove();
  Print();
  
}
