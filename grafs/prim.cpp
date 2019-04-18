#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
const int N=5;
int graf[N][N]={
{0,2,100,100,6},
{100,0,1,3,100},
{4,100,0,1,2},
{100,100,100,0,1},
{3,100,100,100,0}
};
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
int min(){
	int poz;
	int min=1000;
	for(int i=0;i<N;i++){
		if(odw[i]==0 && min>d[i]){
			min=odw[i];
			poz=i;
		}
	}
	odw[poz]=1;
	return poz;
}
void prim(int r){
	for(int i=0;i<N;i++){
		d[i]=1000;
		odw[i]=0;
		pi[i]=-1;
	}
	d[r]=0;
	pi[r]=0;
	odw[r]=1;
	for(int i=0;i<N;i++){
		int u=min();
		for(int j=0;j<N;j++){
			if(odw[j]==0 && graf[u][j]<d[j]){
				pi[j]=u+1;
				d[j]=graf[u][j];
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
	prim(0);
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<d[i]<<" ";
	cout<<endl;
	for(int i=0;i<N;i++)
		cout<<pi[i]<<" ";
	return 0;
}
