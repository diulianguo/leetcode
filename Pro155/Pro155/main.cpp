#include <iostream>
#include <stack>
#include <string>
using namespace std;

class MinStack{
private:
	stack<int> minStk;
	stack<int> allStk;
public:
	MinStack(){
		return;
	}
	void push(int x){
		if(minStk.empty() || x<=minStk.top()){
			minStk.push(x);
		}
		allStk.push(x);
	}
	void pop(){
		if(minStk.top()==allStk.top()){
			minStk.pop();
		}
		allStk.pop();
	}
	int top(){
		return allStk.top();
	}
	int getMin(){
		return minStk.top();
	}
};

int infix_onlyaddminus_calculate(string s){
	stack<int> numStk;
	stack<char> opStk;
	int length=s.size();
	int i=0;
	int res=0;
	while(i<length){
		if(s[i]==' ')
			i++;
		else if(isdigit(s[i])){
			int num=s[i++]-'0';
			while(i<length && isdigit(s[i])){
				num=num*10+s[i++]-'0';
			}
			numStk.push(num);

			while(!opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else
					numStk.push(nums1-nums2);
			}
		}else if(s[i]=='('|| s[i]=='+' || s[i]=='-'){
			opStk.push(s[i++]);
		}else if(s[i]==')'){
			while(opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else
					numStk.push(nums1-nums2);
			}
			i++;
			opStk.pop();
			while(!opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else
					numStk.push(nums1-nums2);
			}
		}
	}
	if(!numStk.empty())
		res=numStk.top();
	return res;
}

int infix_calculate(string s){
	stack<int> numStk;
	stack<char> opStk;
	int length=s.size();
	int i=0;
	int res=0;
	while(i<length){
		if(s[i]==' ')
			i++;
		else if(isdigit(s[i])){
			int num=s[i++]-'0';
			while(i<length && isdigit(s[i])){
				num=num*10+s[i++]-'0';
			}
			numStk.push(num);

			/*while(!opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else
					numStk.push(nums1-nums2);
			}*/
		}else if(s[i]=='('){
			opStk.push(s[i++]);
		}else if(s[i]==')'){
			while(opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else if(ch=='-'){
					numStk.push(nums1-nums2);
				}else if(ch=='*'){
					numStk.push(nums1*nums2);
				}else{
					numStk.push(nums1/nums2);
				}
			}
			i++;
			opStk.pop();
			while(!opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else if(ch=='-'){
					numStk.push(nums1-nums2);
				}else if(ch=='*'){
					numStk.push(nums1*nums2);
				}else{
					numStk.push(nums1/nums2);
				}
			}
		}else{
			//s[i]=='+' || s[i]=='-' || s[i]='*' || s[i]=='/'
			//仅当当前栈中优先级大于或等于当前的运算符，已经计算完成后，才将当前运算符压入栈中
			while((s[i]=='+'||s[i]=='-') && !opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else if(ch=='-'){
					numStk.push(nums1-nums2);
				}else if(ch=='*'){
					numStk.push(nums1*nums2);
				}else{
					numStk.push(nums1/nums2);
				}
			}
			opStk.push(s[i++]);
		}
	}
		while(!opStk.empty()){
			char ch=opStk.top();
				opStk.pop();

				int nums2=numStk.top();
				numStk.pop();

				int nums1=numStk.top();
				numStk.pop();

				if(ch=='+'){
					numStk.push(nums1+nums2);
				}else if(ch=='-'){
					numStk.push(nums1-nums2);
				}else if(ch=='*'){
					numStk.push(nums1*nums2);
				}else{
					numStk.push(nums1/nums2);
				}
		}
		if(!numStk.empty()){
			res=numStk.top();
		}
	return res;
}

void infix_to_suffix(string s){
	string suff;
	stack<char> opStk;
	int length=s.size();
	suff.resize(length);
	int i=0;
	int j=0;
	while(i<length){
		if(isdigit(s[i])){
			//suff[j++]=s[i++];
			int num=s[i++]-'0';
			while(i<length && isdigit(s[i])){
				num=num*10+s[i++]-'0';
			}
			cout<<num<<" ";
		}else if(s[i]=='(')
			opStk.push(s[i++]);
		else if(s[i]==')'){
			while(!opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();
				//suff[j++]=ch;
				cout<<ch<<" ";
			}
			opStk.pop();
			i++;
		}else{
			if((s[i]=='+' || s[i]=='-') && !opStk.empty() && opStk.top()!='('){
				char ch=opStk.top();
				opStk.pop();
				if(ch!='('){
					//suff[j++]=ch;
					cout<<ch<<" ";
				}
			}
		    opStk.push(s[i]);
			i++;
		}
	}
	while(!opStk.empty()){
		char ch=opStk.top();
		opStk.pop();
		//suff[j++]=ch;
		cout<<ch<<" ";
	}
	//return suff;
}

int main(){
	/*MinStack obj;
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	cout<<obj.getMin();*/
	string s;
	cin>>s;
	//cout<<infix_onlyaddminus_calculate(s)<<endl;
	cout<<infix_calculate(s)<<endl;
	//infix_to_suffix(s);
	system("pause");
	return 0;
}