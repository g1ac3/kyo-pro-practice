#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
int N,M,Q;
vector<int> UF;
int topof(int a){
  if(UF[a]<0) return a;
  else return topof(UF[a]);
}
int main(){
  cin>>N>>M;
  UF.resize(N,-1);
  rep(i,M){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int ah = topof(a);
    int bh = topof(b);
    if(ah==bh) continue;
    if(UF[ah]>UF[bh]){
      int tmp = UF[ah];
      UF[ah] = bh;
      UF[bh] += tmp;
    }else{
      int tmp = UF[bh];
      UF[bh] = ah;
      UF[ah] += tmp;
    }
  }
  cin>>Q;
  while(Q--){
    int a,b;
    cin>>a>>b;
    a--;b--;
    int ah = topof(a);
    int bh = topof(b);
    if(ah==bh){
      cout<<"Yes "<<-UF[ah]<<"\n";
    }else{
      cout<<"No "<<-UF[ah]<<" "<<-UF[bh]<<"\n";
    }
  }
}
