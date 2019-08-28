/*
 ID: lolxuda1
 TASK: cowland
 LANG: C++
 */

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 1e5+10;
#define INF 1111111111;
#define M(a) memset(a,0,sizeof(a))
int val[MAXN],fa[MAXN],dep[MAXN],siz[MAXN],id[MAXN],top[MAXN],ran[MAXN],son[MAXN];

typedef struct ee
{
    int u,v;
    int next;
}ee;

ee edge[MAXN*2];
int head[MAXN],cnt;
int num,n;

typedef struct node
{
    int ii;
    int sum;
}node;

node Btree[MAXN*4];

void addedge(int u,int v)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs1(int x,int f,int d)
{
    dep[x]=d;
    siz[x]=1;
    son[x]=0;
    fa[x]=f;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int tmp=edge[i].v;
        if(tmp==f) continue;
        dfs1(tmp,x,d+1);
        siz[x]+=siz[tmp];
        if(siz[son[x]]<siz[tmp])
        {
            son[x]=tmp;
        }
    }
}

void dfs2(int x,int tp)
{
    top[x]=tp;
    id[x]=++num;
    ran[num]=x;
    if(son[x]) dfs2(son[x],tp);
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int tmp=edge[i].v;
        if(tmp==fa[x]||tmp==son[x]) continue;
        dfs2(tmp,tmp);
    }
    
}

void Pushup(int root)
{
    Btree[root].sum=Btree[2*root].sum^Btree[2*root+1].sum;
}

void build(int stu[],int l,int r,int root)
{
    if(l>r) return;
    if(l==r)
    {
        Btree[root].ii=l;
        Btree[root].sum=stu[ran[l]];
        return;
    }
    
    int mid=(l+r)/2;
    build(stu,l,mid,root*2);
    build(stu,mid+1,r,root*2+1);
    
    Pushup(root);
}

void update(int root,int l,int r,int index,int val)
{
    if(l>r) return;
    if(l==r)
    {
        if(l==index)
        {
            Btree[root].sum=val;
        }
        return;
        
    }
    
    int mid=(l+r)/2;
    if(index<=mid)
        update(root*2,l,mid,index,val);
    else
        update(root*2+1,mid+1,r,index,val);
    
    Pushup(root);
}



int querysum(int root,int l,int r,int s,int e)
{
    if(r<s||l>e)
    {
        return 0;
    }
    if(l>r) return 0;
    if(s<=l&&r<=e)
    {
        return Btree[root].sum;
    }
    int mid=(l+r)/2;
    
    int lan=querysum(2*root,l,mid,s,e);
    int ran=querysum(root*2+1,mid+1,r,s,e);
    
    return lan^ran;
}




int solvesum(int a,int b)
{
    if(dep[top[a]]<dep[top[b]])
    {
        swap(a,b);
    }
    int ans=0;
    while(top[a]!=top[b])
    {
        //int tmp=top[a];
        ans^=querysum(1,1,n,id[top[a]],id[a]);
        a=fa[top[a]];
        if(dep[top[a]]<dep[top[b]])
        {
            swap(a,b);
        }
    }
    if(id[a]>id[b]) swap(a,b);
    ans^=querysum(1,1,n,id[a],id[b]);
    printf("%d\n",ans);
    return 0;
}


int main()
{
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    int q;
    while(scanf("%d%d",&n,&q) != EOF)
    {
        num=0;
        M(Btree);
        M(son);
        cnt=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,1);
        dfs2(1,1);
        int mode,a,b;
        build(val,1,n,1);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d%d",&mode,&a,&b);
            if(mode==1)
            {
                val[a]=b;
                update(1,1,n,id[a],b);
            }
            else if(mode==2)
            {
                solvesum(a,b);
            }
        }
    }
    return 0;
}
