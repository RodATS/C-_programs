#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
 
 
int main(){
    int N;
    cin>>N;
    vector<int> el(N);
    for(int i=0;i<N;i++){
      cin>>el[i];
    }
    sort(el.begin(),el.end());
  
    for(int i=N-1;i>0;i--){
      for(int j=i-1;j>=0;j--){
        if((el[i]+el[j])%2==0)
        { cout<<el[i]+el[j]<<endl;return 0;
          }
      }
    }
    cout<<-1;
    return 0;
    
}
