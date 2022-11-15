#include <iostream>
using namespace std;

int d[10001][10001]; //pesos
int c[10001][10001]; //caminos

void Floyd(int n){
  for(int k=1;k<n;k++){
    for(int i=1;i<n;i++){
      //if(i==k){
        for(int j=1;j<n;j++){
          //if(j==k || j==i){
            if(d[i][j] > d[i][k]+d[k][j]){
              d[i][j]=d[i][k]+d[k][j];
              c[i][j]=k;
            }
          //}
        }
      //}
    }
  }
  return;
}

void Print(int n){
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      cout<<d[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main() {
  int n;//vertices
  cin>>n;
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      d[i][j]=9999;
    }
  }
  int ar;//aristas
  cin>>ar;
  while(ar--){
    int i,j,v;
    cin>>i>>j>>v;
    d[i][j]=v;
  }
  cout<<endl;
  Print(n+1);
  Floyd(n+1);
  cout<<endl;
  Print(n+1);
}
