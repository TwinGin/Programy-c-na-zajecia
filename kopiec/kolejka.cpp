#include <iostream>
#include <cstdlib>
#include <time.h>  
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N=0;
int rozmiar =-1;
int kopiec[100]={0};

void down(int N,int i){
		int l,r,wiekszy;
	l=2*i+1;
	r=2*i+2;
	if(l<N && kopiec[l]>kopiec[i])
	wiekszy=l;
	else
	wiekszy=i;
	if(r<N && kopiec[r]>kopiec[wiekszy])
	wiekszy=r;
	if(wiekszy!=i)
	{
		swap(kopiec[i],kopiec[wiekszy]);
		down(N,wiekszy);
		}	
}

void up(int id){
	int father = (id-1)/2;
	if(id>0){	
	if(kopiec[id] > kopiec[father]){
		swap(kopiec[id],kopiec[father]);
		up(father);
	}
}
}

void sortuj(){
int X=N-1;
	for(int i=X;i>0;i--)
	{
		swap(kopiec[0],kopiec[i]);
		
		X--;
		down(X,0);
	}
}
void tworzenie()
{
	for(int i=N/2;i>=0;i--)
	down(N,i);
}

void insert(int element){
	rozmiar++;
	kopiec[rozmiar]=element;
	up(rozmiar);
}
void extract_max(){
	if(rozmiar<1)
		return;
	else{
		swap(kopiec[0],kopiec[rozmiar]);
		rozmiar--;
		down(rozmiar,0);
		cout<<kopiec[rozmiar+1]<<endl;
		kopiec[rozmiar+1]=0;
	}
}
int main(int argc, char** argv) {
	insert(10);
	insert(2);
	insert(15);
	insert(16);
	insert(54);
	insert(21);
	insert(11);
	for(int i=0;i<=rozmiar;i++){
		cout<<kopiec[i]<<" ";
	}
	extract_max();
	for(int i=0;i<=rozmiar;i++){
		cout<<kopiec[i]<<" ";
	}
	extract_max();
	for(int i=0;i<=rozmiar;i++){
		cout<<kopiec[i]<<" ";
	}	
	return 0;
}
