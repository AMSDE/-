#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,K,Ans,Mod[3],dis[20005];
int tot,nxt[40005],lnk[20005],son[40005],w[40005];
int Root,Sum,Num,Size[20005],F[20005];
bool vis[20005];
inline void add(int x,int y,int z){son[++tot]=y;w[tot]=z;nxt[tot]=lnk[x];lnk[x]=tot;}
inline void getrt(int x,int fa){
	F[x]=0;Size[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]||son[i]==fa) continue;
		getrt(son[i],x);
		Size[x]+=Size[son[i]];
		F[x]=max(F[x],Size[son[i]]);
	}
	F[x]=max(F[x],Sum-Size[x]);
	if (F[x]<F[Root]) Root=x;
}
inline void dfs(int x,int fa){
	Mod[dis[x]]++;
	for (int i=lnk[x];i;i=nxt[i]){
		if (son[i]==fa||vis[son[i]]) continue;
		dis[son[i]]=(dis[x]+w[i])%3;
		dfs(son[i],x);
	}
}
inline int Get(int x,int v){
	dis[x]=v;Mod[0]=Mod[1]=Mod[2]=0;dfs(x,0);
	return Mod[0]*Mod[0]+Mod[1]*Mod[2]*2;
}
inline void Solve(int x){
	Ans+=Get(x,0);
	vis[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]) continue;
		Ans-=Get(son[i],w[i]);
		Root=0;Sum=Size[son[i]];
		getrt(son[i],0);
		Solve(Root);
	}
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<N;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);z%=3;
		add(x,y,z);add(y,x,z);
	}
	Root=0;Ans=0;
	F[0]=Sum=N;
	getrt(1,0);
	Solve(Root);
	int p=__gcd(Ans,N*N);
	printf("%d/%d\n",Ans/p,N*N/p);
	return 0;
}
