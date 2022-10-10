//https://atcoder.jp/contests/abc272/tasks/abc272_b
#include<iostream>
#include<set>
#include<vector>
using namespace std;
 
 
int main(){
    int N,M;
    cin>>N>>M;
    set<int> lis[200];//no guarda elementos repetidos
    while(M--)
    {
        int x;cin>>x;
        vector<int> ingresados(x);
        for(int i=0;i<x;i++)
            cin>>ingresados[i];
 
        for(int i=0;i<x-1;i++)
        {
           for(int j=i+1;j<x;j++)
           {
 
               lis[ingresados[i]].insert(ingresados[j]);
               lis[ingresados[j]].insert(ingresados[i]);
           }
        }
    }
 
    for(int i=1;i<=N;i++) {
       if(lis[i].size()<N-1)
       { cout<<"No\n";return 0;}
    }
    cout<<"Yes\n";
 
 
    return 0;
}
