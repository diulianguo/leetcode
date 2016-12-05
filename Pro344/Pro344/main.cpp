#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseString(string s){
	int len=s.size();
	int i=0;
	string revs;
	revs.resize(len);
	while(i<len){
		revs[i]=s[len-i-1];
		i++;
	}
	return revs;
}

void reverseword(string &s,int i,int j){
	while(i<j){
		char t=s[i];
		s[i]=s[j];
		s[j]=t;
		i++;
		j--;
	}
}

string reverseVowels(string s){
	int len=s.size();
	int i=0;
	int j=len-1;
	while(i<=j){
		if(s[i]=='a' || s[i]=='i' || s[i]=='u' || s[i]=='e' || s[i]=='o' 
			|| s[i]=='A' || s[i]=='I' || s[i]=='U' || s[i]=='E' || s[i]=='O'){
				if(s[j]=='a' || s[j]=='i' || s[j]=='u' || s[j]=='e' || s[j]=='o' 
			|| s[j]=='A' || s[j]=='I' || s[j]=='U' || s[j]=='E' || s[j]=='O'){
				char tmp=s[i];
				s[i]=s[j];
				s[j]=tmp;
				i++;
				j--;
				}else
					j--;
		}else
			i++;
	}
	return s;
}

int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' || op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

/*void reverseWords(string &s){
	int len=s.size();
	int i=0;
	int j=0;
	int k=0;
	int blank=0;
	int start=0;
	int end=0;
	while(i<len && s[i]==' ')
		i++;
	if(i!=0){
		blank=i;
		while(blank+k<len){
			s[k]=s[blank+k];
			k++;
		}
		s.resize(len-blank);
	}
	len=s.size();
	i=len-1;
	while(i>=0 && s[i]==' ')
		i--;
	if(len-1-i!=0){
		s.resize(i+1);
	}
	//start=i;
	len=s.size();
	while(i<len){
		while(s[i]!=' ' && i<len){
			i++;
		}
		end=i-1;
		reverseString(s,start,end);
		start=end+2;
		i=start;
	}
}*/

void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') 
				i++;  // skip spaces in front of the word
            if(i==len) 
				break;
            if(wordcount) 
				s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') 
			{
				s[j]=s[i]; 
				j++; 
				i++;
			} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }

int main(){
	string s;
	getline(cin,s);
	cout<<s.length()<<endl;
	//string revs;
	//cout<<calculate(s);
	//revs=reverseString(s);
	//revs=reverseVowels(s);
	//cout<<revs;
	reverseWords(s);
	cout<<s;
	system("pause");
	return 0;
}