#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;
#define MAX 100
char stk[MAX];
int top=-1;

void push(char n){
    if(top+1==MAX){
        cout<<"Overflow";
    }else{
        stk[++top]=n;
    }
}

char pop(){
    char r;
    if(top==-1){
        cout<<"Underflow";
        return '-1';
    }else{
        r=stk[top];
        top--;
    }
    return r;
}

char peep(){
    return stk[top];
}

int prec(char c){
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return 0;
}

string ConvertToPostfix(string s){
    s = '('+s+')';
    int l = s.length();
    string ans;
    for(int i=0; i<l; i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
            ans+=s[i];
        else if(s[i]=='(')
            push(s[i]);
        else if(s[i]==')'){
            while(peep()!='('){
                char d=peep();
                pop();
                ans+=d;
            }
            pop();
        }
        else{
                if(!isalpha(peep())&&!isdigit(peep())){
            while(prec(s[i])<=prec(peep())){
                char c=peep();
                pop();
                ans+=c;
            }
            push(s[i]);
        }
        }
    }


    return ans;

}

void InfixToPrefix(string s){
    int n;
    n=s.length();
    reverse(s.begin(),s.end());
    for(int i=0; i<n; i++){
        if(s[i]=='('){
            s[i]=')';
            i++;
        }else if(s[i]==')'){
            s[i]='(';
            i++;
        }
    }

    string prefix=ConvertToPostfix(s);
    reverse(prefix.begin(),prefix.end());
    cout<<prefix;
}


int main()
{
    string str;
    cout<<"Enter the infix string to convert it to Prefix without any spaces"<<endl;
    getline(cin,str);
    cout<<"Prefix Expression: ";
    InfixToPrefix(str);
    return 0;
}
