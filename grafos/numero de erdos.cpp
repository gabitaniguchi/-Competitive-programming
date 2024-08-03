#include <bits/stdc++.h>

using namespace std;
#define MAX (int)(1e3 + 10)

vector<int> g[MAX];
int n=1,vis[MAX], e[MAX];
map<string,int> nome;


int main(){
    nome["P. Erdos"] = 1;
    int teste=1;
    
    while(true){
        cin>>n;
        if(n==0) break;
        cin.ignore();
        int temp=2;
        string a,b,linha;
        set<string> autores;
        vector<int> entrada[n+5];

        for(int i=1;i<=n;i++){
            
            getline(cin,a);

            for(int j=0;j<(int)a.size();j++){
                if(a[j]==',' || j==(int)a.size()-1) {
                    autores.insert(b);

                    auto it = nome.find(b);
                    if(it == nome.end()){
                        nome[b] = temp;
                        temp++;  
                    }   
                    entrada[i].push_back(nome[b]);

                    b = "";
                    j++;
                }
                else if(j+1!=(int)a.size()) b+= a[j];
            }

        }
        printf("Teste %d\n", teste);

        for(int j=0;j<n;j++){
            for(auto next: entrada[j]){
                cout<<next<<" ";
            }
            cout<<endl;
        }

        cout<<endl;

        for(auto x: autores){
            if(x!="P. Erdos") nome.erase(x);
        }

        teste ++;
    }






    return 0;
}
// 1 2
// 1 3 4
// 4 2 5
// 6 7
// 8 5
// P. Erdos, A. Selberg.
// P. Erdos, J. Silva, M. Souza.
// M. Souza, A. Selberg, A. Oliveira.
// J. Ninguem, M. Ninguem.
// P. Duarte, A. Oliveira.