#include <iostream>

#include<stack>


using namespace std;
//char stack[MAX];
//char infix[MAX],postfix[MAX];
//int top=-1;
int pre(char c){
	if(c=='^'){
		return 3;
		
	}
	else if(c=='*'||c=='/'){
		return 2;
	}
	else if(c=='+'||c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}
string infixtoPostfix(string s){
	cout<<"enter a infix expression";
	cin>>s;
	
	stack<char> st;
	string output;
	for(int i=0;i<s.length();i++){
		if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z')){
			output+=s[i];
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty()&& st.top()!='('){
				output+=st.top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{
			while(!st.empty()&& pre(st.top())>pre(s[i])){
				output+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		output+=st.top();
		st.pop();
	}
	return output;
}
int main(){
	string s;
	cout<<infixtoPostfix(s);
	return 0;
//	cout<<"enter your expression";
//	
//	gets(infix);
//	cout<<infix;
}


