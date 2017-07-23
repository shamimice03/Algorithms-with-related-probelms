#include<bits/stdc++.h>
#define   inf            100000000000000000
#define   X              first
#define   Y              second
#define   B              begin()
#define   E              end()
#define   mp             make_pair
#define   pb             push_back
#define   loop1(i,n)     for(int i=1; i<=(n); i++)
#define   loop2(j,n)     for(int j=1; j<=(n); j++)
#define   loop0(i,n)     for(int i=0; i<(n); i++)
#define   valid(nx,ny)   nx>=1 && nx<=8 && ny>=1 && ny<=8
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           120
using namespace std;

int edges[SIZE][SIZE];
vector<int>result;
int indegree[SIZE];
int n,m;

int topsort(){
       queue<int>q;
       for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
       }

       while(!q.empty()){

           int u=q.front();
           q.pop();
           result.pb(u);
           for(int i=1; i<=n; i++){

               if(edges[u][i]==1){
                   indegree[i]--;
                   if(indegree[i]==0) {q.push(i);}
               }
           }
       }
}

int main()
{
    cin>>n>>m;
    printf("n is number of task\n");
    printf("m is number of related task\n");

    int u,v;

    memset(indegree,0,sizeof(indegree));
    memset(edges,0,sizeof(edges));

     for(int i=1; i<=m; i++){
        cin>>u>>v;
        edges[u][v]=1;
        indegree[v]++;
     }

      topsort();
      cout<<"Order of Task"<<endl;
     for(int i=0; i<result.size(); i++) {cout<<result[i]<<" ";}
}

