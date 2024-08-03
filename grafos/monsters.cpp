#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

char mapa[MAX][MAX];
queue<pair<int,int>> q;
stack<char> caminho;
int dist[MAX][MAX],l,c,xi,yi,xf,yf;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int x, int y){
    if(x<1||x>l||y<1||y>c||mapa[x][y]=='#') return false;
    for(int i=0;i<4;i++){
        int nx = x+dx[i], ny= y+dy[i];
        if(mapa[nx][ny]=='M') return false;
    }

    return true;
}

int main(){

    cin>>l>>c;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='A') xi=i, yi=j;  
        } 
    }

    memset(dist,-1,sizeof(dist));
    dist[xi][xf] = 0;
    q.push({xi,yi});

    bool ans = false;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        if(x==l||x==1||y==c||y==1){
            ans = true;
            xf=x, yf=y;
            break;
        }

        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if(!valid(nx,ny)) continue;
            if(dist[nx][ny]==-1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }

        }
    }

    if(!ans) printf("NO\n");

    else{
        printf("YES\n");
        printf("%d\n", dist[xf,yf]);
    }




    return 0;
}