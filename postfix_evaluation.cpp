#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define Max 100
int stk[Max];
int top=-1;


void push(char n){
    if(top+1==Max){
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

int Evaluate(string s){
    for(int i=0; i<s.length(); i++){
        if(isdigit(s[i])){
            push(s[i]-'0');
        }else{
            int val1=pop();
            int val2=pop();
            switch(s[i]){
                case '+':push(val2+val1); break;
                case '-':push(val2-val1); break;
                case '*':push(val2*val1); break;
                case '/':push(val2/val1); break;
            }
        }
    }
    cout<<(int)pop();
}
using namespace std;

int main()
{

    string str;
    cout<<"Enter the postfix string to evaluate without any spaces"<<endl;
    getline(cin,str);
    cout<<"Answer after Evaluation: ";
    Evaluate(str);
    return 0;
}
