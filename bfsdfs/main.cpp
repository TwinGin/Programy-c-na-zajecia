#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>    
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N = 5;
int graf[N][N]={
{0,2,100,100,6},
{100,0,1,3,100},
{4,100,0,1,2},
{100,100,100,0,1},
{3,100,100,100,0}
};
int odwiedzony[N]={0};
int key[N]={1000};
int kolejnosc[N]={0};
int indeks = 0;
int pi[N]={0};
int d[N]={1000};
int usuniete[N]={0};
int id=0;
queue <int> kolejka;
queue <int> djkstr;
queue <int> prm;

int min()
{
	int poz;
	int min=100;
	for(int j=0;j<N;j++)
	{
		if(usuniete[j]==0 && min>key[j]) 
			{
				min=key[j];
				poz=j;
			}	
	}
	usuniete[poz]=1;
	return poz;
}


void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graf[i][j]=rand()%10;	
		}
	}
}
void dfs(int u){
	odwiedzony[u]=1;
	kolejnosc[indeks]=u;
	indeks++;
	for(int i=0;i<N;i++){
		if(odwiedzony[i]==0 && graf[u][i]==1){
			dfs(i);
		}
	}
}
void bfs(int s){
	for(int i=0;i<N;i++){
		odwiedzony[i]=0;
	}
	odwiedzony[s]=1;
	d[s]=0;
	kolejka.push(s);
	while(!kolejka.empty()){
		int u=kolejka.front();
		cout<<"w:"<<u<<" ";
		for(int v=0;v<N;v++){
			if(odwiedzony[v]==0 && graf[u][v]==1){
				odwiedzony[v]=1;
				d[v]=d[u]+1;
				pi[v]=u;
				kolejka.push(v);
			}
		}
		kolejka.pop();
	}
}
void relax(int u, int v){
	if(d[v]>d[u]+graf[u][v]){
		d[v]=d[u]+graf[u][v];
		pi[v]=u+1;
	}
}
void dijkstra(int s){
	for(int i=0;i<N;i++){
		d[i]=1000;
		pi[i]=NULL;
		djkstr.push(i);
		odwiedzony[i]=0;
	}
	d[s]=0;
	odwiedzony[s]=1;
	while(!djkstr.empty()){
		int u=djkstr.front();
		djkstr.pop();
		for(int i=0;i<N;i++){
			if(odwiedzony[i]==0 && graf[u][i]>0)
				relax(u,i);
		}
	}
}

void prim(int r){
	for(int i=0;i<N;i++){
		key[i]=1000;
		usuniete[i]=0;
		pi[i]=-1;
	}
	key[r]=0;
	pi[r]=0;
	usuniete[r]=1;
	for( int i=0;i<N;i++){
		int u=min();
		for(int v=0;v<N;v++){
			if(usuniete[v]==0 && graf[u][v]<key[v]){
				pi[v]=u+1;
				key[v]=graf[u][v];
			}
		}
	}
}
int main(int argc, char** argv) {
	srand(time(NULL)); //init();
	for(int i=0;i<N;i++){
		for(int j=0; j<N;j++){
			cout<<graf[i][j]<<" ";
		}	
		cout<<endl;
	}
	//dfs(0);
	//bfs(0);
		//dijkstra(0);
		prim(0);
	for(int i=0;i<N;i++)
		cout<<key[i]<<" ";
		cout<<endl;
		for(int i=0;i<N;i++)
		cout<<pi[i]<<" ";
	
	return 0;
}
