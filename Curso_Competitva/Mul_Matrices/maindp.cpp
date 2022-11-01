#include <iostream>
#include <climits>
#include <vector>
using namespace std;



int m[5][5];


int Mul_Mat_n(vector<int> p){
  int n=p.size()-1;
  int s[5][5];   //guarda k
  
  for(int i=1;i<=n;i++){
    m[i][i]=0;
  }

  
  for(int i=n;i>=1;i--){
    for(int j=i;j<=n;j++){
      int min = INT_MAX;
      for(int k=i;k<j;k++){
        int q =  m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if(q < min){
          min=q;
          m[i][j]=min;
        }
      }
      
        
    }
  }
  return m[1][n];
}




int main() {
  vector<int> p={10,20,50,1,100};
  
  cout<<Mul_Mat_n(p)<<endl;
  
  int n=p.size()-1;
  //impresion
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<m[i][j]<<"\t";
    }
    cout<<endl;
  }
  
}
