#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
const int N=5;
int graf[N][N];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int odw[N]={0};
int kolej[N]={-1};
int indeks=0;
queue <int> kolejka;
void dfs(int s){
	cout<<"jest"<<endl;
	odw[s]=1;
	kolej[indeks]=s;
	indeks++;
	for(int i=0;i<N;i++){
		if(graf[s][i]==1 && odw[i]==0){
			dfs(i);
		}
	}
}
void init(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			graf[i][j]=rand()%2;	
		}
	}
}
void bfs(int s){
	odw[s]=1;
	kolejka.push(s);
	while(!kolejka.empty()){
		int u=kolejka.front();
		kolej[indeks]=u;
		indeks++;
		for(int i=0;i<N;i++){
			if(odw[i]==0 && graf[u][i]==1){
				kolejka.push(i);
				odw[i]=1;
			}
		}
		kolejka.pop();
	}
}
int main(int argc, char** argv) {
	srand(time(NULL)); init();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<graf[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	//dfs(0);
	bfs(0);
	for(int j=0;j<N;j++){
		cout<<kolej[j]<<" ";
	}
	return 0;
}
