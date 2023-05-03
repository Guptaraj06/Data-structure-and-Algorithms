#include<bits/stdc++.h> 
using namespace std;     
struct dsu{ 
    int n;    
    vector<int>p;    
    vector<int>sz; 
    dsu(int _n):n(_n){
        p.resize(n); 
        iota(p.begin(),p.end(),0);      
        sz.resize(n,1);
    }             
    inline int get(int x){
        if(p[x]==x){
            return x;
        } 
        else{
           return p[x]=get(p[x]); 
        }
    }      
    inline bool unite(int x,int y){
        x=get(x); 
        y=get(y); 
        if(x==y){
            return false;
        }  
        else{
            p[x]=y; 
            sz[y]+=sz[x]; 
            return true; 
        }
    } 
    inline int size(int x){
        return sz[get(x)]; 
    }
};
int main(){       
    cout<<"hello\n"; 
    return 0;
}