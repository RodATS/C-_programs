#include <iostream>
using namespace std;

int *gpVector = NULL;
int gnCount=0;
int gnMax=0;

void Resize(){
  const int delta=10;
  //gpVector=realloc(gpVector, sizeof(int)*(gnMax+delta));
  int *pTemp, i;
  pTemp=new int[gnMax+delta];
  for(int i=0;i<gnMax;i++){
    pTemp[i]=gpVector[i];
  }
  delete [] gpVector;
  gpVector = pTemp;
  gnMax += delta;
}

void Insert(int elem){
  if(gnCount==gnMax)
    Resize();
  gpVector[gnCount]=elem;
  gnCount++;
}

void Remove(){
  if(gnCount==0){
    gpVector[gnCount]=0;  
    return;
  }
  gpVector[gnCount]=0;
  gnCount--;
}

void Print(){
  for(int i=0;i<gnCount;i++){
    cout<<gpVector[i]<<"\t";
  }
  cout<<endl;
}


int main() {
  Insert(5);
  Print();
  Insert(15);
  Insert(3);
  Insert(2);
  Print();
  Remove();
  Print();
}
