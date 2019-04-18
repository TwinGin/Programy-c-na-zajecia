#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>    
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N = 10;
int graf[N][N];
int odwiedzony[N]={0};
int kolejnosc[N]={0};
int indeks = 0;
int pi[N]={0};
int d[N]={1000};
queue <int> kolejka;
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graf[i][j]=rand()%2;	
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
		pi[i]=NULL;
		odwiedzony[i]=0;
	}
	odwiedzony[s]=1;
	d[s]=0;
	kolejka.push(s);
	while(!kolejka.empty()){
		int u=kolejka.front();
		for(int v=0;v<N;v++){
			if(odwiedzony[v]==0 && graf[u][v]==1){
				odwiedzony[v]=1;
				d[v]=d[u]+1;
				pi[v]=u;
				kolejka.push(v);
			}
		}
	}
	kolejka.pop();
}
int main(int argc, char** argv) {
	srand(time(NULL)); init();
	for(int i=0;i<N;i++){
		for(int j=0; j<N;j++){
			cout<<graf[i][j]<<" ";
		}	
		cout<<endl;
	}
	//dfs(0);
	for(int i=0;i<N;i++)
		cout<<"w:"<<kolejnosc[i]<<" ";
	return 0;
}
