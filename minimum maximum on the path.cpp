#include <bits/stdc++.h>

using namespace std;

#define MAX 100010
int n,r,d, p[MAX],dist[MAX];
vector<pair<int,int>> g[MAX];
set<pair<int,int>> s;
map<int,int> pai;
stack<int> caminho;
const int inf = 1e9+10;

bool check(int x, int pmax){
    for(int i=2;i<=n;i++) dist[i] = -1;
    dist[x] = 0;
    s.insert({0,x});
    pai[1] = 0;

    while(!s.empty()){
        int atual = s.begin()->second;
        s.erase(s.begin());

        for(int i=0;i<g[atual].size();i++){
            int next = g[atual][i].first;
            int w = g[atual][i].second;

            if(w>pmax) continue;

            if(dist[next]==-1 && dist[atual]<d && dist[atual]<=d){
                pai[next] = atual;
                dist[next] = dist[atual] + 1;
                s.insert({dist[atual]+1,next});
            }
        }
    }

    if(dist[n]>d) return false;
    else return true;
}

int busca (){
    int i = 1;
    int f = r+1;
    int ans = -1;

    while(f>=i){
        
        int m = (i+f)/2;
        if(check(1,p[m])==false) i = m+1;
        else{
            if(ans<0) ans = p[m];
            else ans = min(ans,p[m]);
            f = m-1;
        }

    }

    return ans;
}

int main(){

    cin>>n>>r>>d;

    for(int i=1;i<=r;i++){
        int a,b,c;
        cin>>a>>b>>c;

        p[i] = c;
        g[a].push_back({b,c});
    }

    sort(p,p+n+1);
    int ans = busca();

    if(ans==-1){
        printf("-1\n");
        return 0;
    }

    else{
        check(1,ans);
        cout<<dist[n]<<endl;
        int x = n;
        while(x!=0){
            caminho.push(x);
            x = pai[x];
        }

        while(!caminho.empty()){
            int x = caminho.top();
            caminho.pop();
            cout<<x;

            if(!caminho.empty()) cout<<" ";
            else cout<<endl;
        }
    }

    return 0;
}