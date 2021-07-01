#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
  int N,M,X,Y;
  cin>>N>>M>>X>>Y;
  --X;--Y;
  vector<vector<P>> e(N);
  const ll INF = 1e18;
  vector<ll> T(N,INF);
  rep(i,M){
    int a,b,t;
    cin>>a>>b>>t;
    --a;--b;
    e[a].emplace_back(b,t);
    e[b].emplace_back(a,t);
  }
  priority_queue<P, vector<P>, greater<P>> q;
  q.push({0,X});
  T[X] = 0;
  while(!q.empty()){
    auto [t,n] = q.top();q.pop();
    if(t!=T[n])continue;
    // printf("%d %d\n",t,n);
    // for(ll x:T) cout<<x<<" ";
    // cout<<"\n";
    for(auto [to,w]:e[n]){
      ll time = t + w;
      if(T[to] <= time) continue;
      T[to] = time;
      q.push({time,to});
    }
  }
  ll ans = T[Y];
  if(T[Y] == INF) ans = -1;
  cout<<ans<<"\n";
}
