#include<bits/stdc++.h>
using namespace std;      
vector<int> p; 
struct seg{   
   int n;  
   vector<int> a; 
   seg(int _n):n(_n){
       a.resize(4*n); 
   }   
   void build(int cur,int tl,int tr){   
       if(tl==tr){
           a[cur]=p[tl];   
           return; 
       }      
       int mid=(tl+tr)>>1; 
       build(2*cur,tl,mid); 
       build(2*cur+1,mid+1,tr); 
       a[cur]=a[2*cur]+a[2*cur+1]; 
   }    
    int get(int cur,int tl,int tr,int l,int r){
      if(l<=tl && tr<=r)return a[cur]; 
      if(tl>r||tr<l)return 0; 
      int mid=(tl+tr)>>1; 
      return get(2*cur,tl,mid,l,r)+get(2*cur+1,mid+1,tr,l,r);
   }               
   void update(int cur,int tl,int tr,int idx,int new_val){
       if(tl==tr){
           a[cur]=new_val; 
           return;
       }   
       int mid=(tl+tr)>>1; 
       if(idx<=mid){
           update(2*cur,tl,mid,idx,new_val); 
       }    
       else{
           update(2*cur+1,mid+1,tr,idx,new_val); 
       }         
       a[cur]=a[2*cur]+a[2*cur+1]; 
   }   
};
int main(){
    int n;   
    cin>>n; 
    seg s1(n); 
    for(int i=1;i<=n;i++){
        int x;
        cin>>x; 
        s1.update(1,1,n,i,x); 
    } 
    int q;
    cin>>q; 
    while(q--){
        int l,r;  
        cin>>l>>r;
        cout<<s1.get(1,1,n,l,r)<<"\n"; 
    }
    return 0; 
}     
/*
{
struct data{
    int pref,suf,val,sum;
}   
data merge(data a,data b){
    data c; 
    c.sum=a.sum+b.sum; 
    c.pref=max(a.pref,a.sum+b.pref);
    c.suf=max(b.suf,b.sum+a.suf);
    c.val=max(max(a.val,b.val),a.suf+b.pref);  
    return c; 
}
}
*/