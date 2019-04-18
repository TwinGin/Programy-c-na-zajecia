#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N = 157;
int n;
struct element{
	char *s;
	element *next;
};
element*H[N]={NULL};
//… T[N]; //tablica
int Hash(char* slowo){
	int potega=0;
	for(int i=0;i<N;i++){
		if(slowo[i]=='\0')
			break;
		potega++;
	}
	int hasz=0;
	for(int i=0;i<N;i++){
		if(slowo[i]=='\0')
			break;
		else{
			hasz+=37 * (int)slowo[i]^ potega;
			potega--;
		}
	}
	hasz=hasz%157;
	//cout<<potega<<" "<<hasz<<endl;
	return hasz;
} //funkcja haszuj¹ca
char* init(){ //generuje losowy ci¹g n-znakowy
n =rand()%9+1;
int i;
char *t = new char[n+1];
for(i=0;i<n;i++)
 t[i] = (char)(rand()%28 + 65);
t[i]='\0';
return t;
}
void dodaj(char* slowo){
	int i=Hash(slowo);
	element *nowy=new element;
	nowy->next=NULL;
	nowy->s=slowo;
	nowy->next=H[i];
	H[i]=nowy;
	
}
int main(int argc, char *argv[]){
 srand(time(NULL));
 for(int i =0; i< N;i++){
 char *s = init();
 dodaj(s);
}
for(int i=0;i<10 ;i++){
 	element *hh=H[i];
 	while(hh!=NULL){
 		cout<<i<<": "<<hh->s<<" ";
 		hh=hh->next;
	 }
	 cout<<endl;
 }
}
