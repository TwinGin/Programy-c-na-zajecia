#include <iostream>
#include <cmath>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
string txt,pat;
int base=4;
int h2(string s){
	int h=0;
	for(int i=0;i<pat.length();i++)
		h+=s[i]*pow(base,pat.length()-i-1);
	return h;
}
int main(int argc, char** argv) {
	cin>>txt>>pat;
	int ht=h2(txt);
	int hp=h2(pat);
	int i=0;
	int j;
	while(i<=txt.length()-pat.length()){
		j=pat.length()-1;
		while(j>-1 && pat[j]==txt[i+j])
			j--;
		if(j==-1)
			cout<<"pat: "<<i<<endl;
		else{
			ht-=txt[i]*pow(base,pat.length()-1);
			ht*=base;
			ht+=txt[i+pat.length()];
		}
		i++;
	}
}

