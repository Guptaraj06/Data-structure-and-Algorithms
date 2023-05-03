#include<bits/stdc++.h> 
using namespace std;     
template<typename T,class F=function<T(const T&,const T&)>>
class sparse_table{    
  public:
      int n;  
      vector<vector<T>> mat;
      F func;
      sparse_table(const vector<T> & a,const F& f):func(f){
        n=a.size();
        int max_log=32-__builtin_clz(n);
        mat.resize(max_log);  
        mat[0]=a;
        for(int i=1;i<max_log;i++){  
          mat[i].resize(n-(1<<i)+1);
          for(int j=0;j+(1<<i)<=n;j++){
            mat[i][j]=func(mat[i-1][j],mat[i-1][j+(1<<(i-1))]);
          }
        }
      }            
      T get(int from,int to){
        int log1=32-__builtin_clz(to-from+1)-1;
        T res=func(mat[log1][from],mat[log1][to-(1<<log1)+1]); 
        return res;
      }
};
int main(){ 
    int n;   
    vi a;
    sparse_table<int> s1(a,[&](int i,int j){return min(i,j);});   
    return 0;
}