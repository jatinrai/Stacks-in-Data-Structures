#include <iostream>

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
    char d;
    if(top==-1){
        cout<<"Underflow";
        return '-1';
    }else{
        d=stk[top];
        top--;
        return d;
    }
}

char peep(){
    return stk[top];
}

int prec(char c){
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='-'||c=='+')
        return 1;
    else
        return -1;
}


void InfixToPostfix(string s){
    push('N');
    int l = s.length();
    string ans;
    for(int i=0; i<l; i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            ans+=s[i];
        }else if(s[i]=='('){
            push('(');
        }else if(s[i]==')'){
            while(peep()!='N'&& peep()!='('){
                    char d=peep();
                    pop();
                    ans+=d;
                }
            if(peep()=='('){
                pop();
               }
        }else{
            while(peep()!='N'&&prec(s[i])<=prec(peep())){
                char c = peep();
                pop();
                ans+=c;
            }
            push(s[i]);
        }
    }


    while(peep()!='N'){
        char c=peep();
        pop();
        ans+=c;
    }
    cout<<ans<<endl;
}


int main()
{
    string str;
    cout<<"Enter the infix string to convert it to postfix without any spaces"<<endl;
    getline(cin,str);
    cout<<"Postfix Expression: ";
    InfixToPostfix(str);

    return 0;
}
