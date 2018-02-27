#include<cstdio>
#include<algorithm>
#define maxn 10005
#define maxe 20005
using namespace std;
int N,M,Num,dis[maxn],S[maxn],Ans[10000005];
int tot,lnk[maxn],nxt[maxe],son[maxe],w[maxe];
int Sum,Root,F[maxn],Size[maxn];
bool vis[maxn];
inline int read(){
	int Res=0;char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') Res=Res*10+ch-'0',ch=getchar();
	return Res;
}
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
	S[++Num]=dis[x];
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]||son[i]==fa) continue;
		dis[son[i]]=dis[x]+w[i];
		dfs(son[i],x);
	}
}
inline void Get(int x,int v,int del){
	dis[x]=v;Num=0;dfs(x,0);
	for (int i=1;i<=Num;i++) for (int j=1;j<=Num;j++) Ans[S[i]+S[j]]+=1+del*-2;
}
inline void Solve(int x){
	Get(x,0,0);
	vis[x]=1;
	for (int i=lnk[x];i;i=nxt[i]){
		if (vis[son[i]]) continue;
		Root=0;Sum=Size[son[i]];
		Get(son[i],w[i],1);
		getrt(son[i],0);
		Solve(Root);
	}
}
inline void add(int x,int y,int z){son[++tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;w[tot]=z;}
int main()
{
	N=read();M=read();
	for (int i=1;i<N;i++){
		int x=read(),y=read(),z=read();
		add(x,y,z);add(y,x,z);
	}
	Sum=N;F[0]=2e9;
	getrt(1,0);
	Solve(Root);
	for (int i=1;i<=M;i++){
		int x=read();
		if (Ans[x]) printf("AYE\n");else printf("NAY\n");
	}
	return 0;
}
