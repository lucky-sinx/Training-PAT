#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int inf=99999999;
int mp1[N][N],mp2[N][N];
int dis[N],cost[N];
vector<int> pre[N],temppath,bestpath;
bool vis[N];
int n,m,s,d;
int mincost=inf;
void init()
{
    fill(mp1[0],mp1[0]+N*N,inf);
    fill(mp2[0],mp2[0]+N*N,inf);
    fill(dis,dis+N,inf);
    fill(cost,cost+N,inf);
    memset(vis,0,sizeof(vis));
}
void dfs(int t)
{
    temppath.push_back(t);
    if(t==s)
    {
        int c=0;
        for(int i=0;i<temppath.size()-1;i++)
            c+=mp2[temppath[i]][temppath[i+1]];
        if(c<mincost)
        {
            bestpath=temppath;
            mincost=c;
        }
    }
    for(int i=0;i<pre[t].size();i++)
        dfs(pre[t][i]);
    temppath.pop_back();
}
int main()
{
    cin>>n>>m>>s>>d;
    init();
    for(int i=0;i<m;i++)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        mp1[x][y]=mp1[y][x]=a;
        mp2[x][y]=mp2[y][x]=b;
    }
    dis[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,minn=inf;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&dis[j]<minn)
            {
                u=j;
                minn=dis[j];
            }
        }
        if(u==-1)break;
        vis[u]=true;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&mp1[u][j]!=inf)
            {
                if(dis[j]>dis[u]+mp1[u][j])
                {
                    pre[j].clear();
                    pre[j].push_back(u);
                    dis[j]=dis[u]+mp1[u][j];
                }
                else if(dis[j]==dis[u]+mp1[u][j])
                {
                    pre[j].push_back(u);

                }
            }
        }
    }
    dfs(d);
    for(int i=bestpath.size()-1;i>=0;i--)
    {
        cout<<bestpath[i];
        if(i!=0)cout<<' ';
    }
    cout<<' '<<dis[d]<<' '<<mincost;
}
