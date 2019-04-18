#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
const int N=5;
int graf[N][N]={{0,2,0,0,6},{0,0,1,3,0},{4,0,0,0,2},{0,0,1,0,1},{3,0,0,0,0}};
int d[N]={1000};
int pi[N]={-1};
int odw[N]={0};
queue <int> kolejka;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graf[i][j]=rand()%10;	
		}
	}
}
void relax(int u,int v){
	if(d[v]>d[u]+graf[u][v]){
		d[v]=d[u]+graf[u][v];
		pi[v]=u+1;
	}
}
void dijkstra(int s){
	for(int i=0;i<N;i++){
		kolejka.push(i);
		d[i]=1000;
		pi[i]=NULL;
		odw[i]=0;
	}
	odw[s]=1;
	d[s]=0;
	while(!kolejka.empty()){
		int u=kolejka.front();
		kolejka.pop();
		for(int i=0;i<N;i++){
			if(graf[u][i]>0){
				relax(u,i);
			}
		}
	}
}
int main(int argc, char** argv) {
	srand(time(NULL)); //init();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<graf[i][j]<<" ";
		}
		cout<<endl;
	}
	dijkstra(0);
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<d[i]<<" ";
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<pi[i]<<" ";
	return 0;
}
