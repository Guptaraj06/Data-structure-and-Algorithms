#include<bits/stdc++.h>   
#define all(x) x.begin(),x.end()    
using namespace std;     
typedef vector<int> vi;
struct fenwick{
    int n; 
    vector<int> bit;
    fenwick(int _n):n(_n){
     bit.resize(n+1);
    }      
     int query(int ind){
      int sum=0;
      ind+=1;
      while(ind){
         sum+=bit[ind];
         ind-=(ind & (-ind));
      }    
      return sum; 
    }            
    void update(int ind,int val){
      ind+=1;
      while(ind<=n){
          bit[ind]+=val; 
          ind+=ind&(-ind);
      }
    }              
};
int main(){     
     int n;
     fenwick f1(n);
     return 0;
}