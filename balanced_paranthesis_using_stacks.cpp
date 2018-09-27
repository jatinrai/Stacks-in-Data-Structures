#include <iostream>

using namespace std;

class Stack{
 char arr[10];
 int s=10,top=-1,flag=0;
 public:
     void push(int item){
     if(top == s)
        cout<<"overflow";
     else{
        top++;
        arr[top]=item;

     }
        }
    void pop(){
    if(top==-1){
       cout<<"underflow";
       }
       else{
        int temp = arr[top];
        top--;

       }

    }

    void peep(){
     if(top==-1)
        cout<<"underflow";
     else
        cout<<arr[top];
    }

    void traverse(){
        cout<<endl;
     for(int i=top; i>=0; i--){
        cout<<arr[i]<<endl;
     }
    }

    bool checkPair(char opening, char closing){
        if(opening == '(' && closing == ')')
            return true;
        else if(opening == '{' && closing == '}')
            return true;
        else if(opening == '[' && closing == ']')
            return true;
        return false;
    }

    bool checkSequence(char arr[], int n){
        for(int i=0; i<n; i++){
            if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
                push(arr[i]);
            }
            else if(arr[i]==')' || arr[i]=='}' || arr[i]==']'){
                if(checkPair(arr[top],arr[i])){
                        pop();
                }
                else{
                    return false;

                }
            }
        }
        return true;


    }

};

int main()
{
    char arr[10];
    int n;
    cout<<"Enter number of brackets to enter"<<endl;
    cin>>n;
    cout<<"Enter the sequence for parenthesis:"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    Stack s;
    if(s.checkSequence(arr,n))
        cout<<"Balanced"<<endl;
    else
        cout<<"Unbalanced"<<endl;
    return 0;

}
