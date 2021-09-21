#include <bits/stdc++.h>

#define MAX 50

using namespace std;

double stk1[30];
int top1=-1;

void push1(double key)
{
    if(top1==MAX-1)
    {
        cout<<"full";
    }

    else
    {
        top1++;
        stk1[top1]=key;
    }
}

double pop1()
{
    double n;
    if(top1==-1)
    {
        cout<<"empty";
    }
    else
    {
        n=stk1[top1];
        top1--;
        return(n);
    }
    return 0;
}




char stk[30];
int top=-1;

void push(char key)
{
    if(top==MAX-1)
    {
        cout<<"stackfull!!!!";
    }

    else
    {
        top++;
        stk[top]=key;
    }
}
char pop()
{
    char ch;
    if(top==-1)
    {
        cout<<"empty";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int prec ( char oprtor )
{
    if(oprtor == '+' || oprtor =='-')
    {
        return 1;
    }

    if(oprtor == '*' || oprtor =='/'|| oprtor=='%')
    {
        return 2;
    }
    if(oprtor == '^' )
    {
        return 3;
    }

    return 0;
}


string infix_to_postfix(string inf){

    int i=0;
    string post = "";
    while(inf[i]!='\0'){

        if(inf[i]>='0' && inf[i]<='9'){
        string str="";
        while(isdigit(inf[i])||inf[i]=='.'){
        str+=inf[i];
            i++;
        }
        post+=str;
        post+=" ";
        }
        else if(inf[i]=='(')
        {
            push(inf[i]);
            i++;
        }
        else if(inf[i]==')')
        {
            if(inf[i]==')'){

                while(stk[top]!='(')
                { post.insert(post.end(),pop());
                post+=" ";
                }
                pop();
                i++;
            }
            if(inf[i]==']'){

                while(stk[top]!='['){

                    post.insert(post.end(),pop());
                }
                pop();
                i++;
            }

            if(inf[i]=='}'){

                while(stk[top]!='{'){

                    post.insert(post.end(),pop());
                }
                pop();
                i++;
            }
        }
        else{

            if(top==-1){

                push(inf[i]);
                i++;
            }

            else if( prec(inf[i]) <= prec(stk[top])){
                post.insert(post.end(),pop());
                post+=" ";

                while(prec(stk[top]) == prec(inf[i])){
                    post.insert(post.end(),pop());
                    post+=" ";
                    if(top < 0) {
                        break;
                    }
                }
                push(inf[i]);
                i++;
            }
            else if(prec(inf[i]) > prec(stk[top])) {
                push(inf[i]);
                i++;
            }
        }
    }
    while(top!=-1){

        post.insert(post.end(),pop());
        post+=" ";
    }
    return post;
}


void expr_evaluation(string exp){

int i=0;
for(i=0;i<exp.length();i++){

if(exp[i]==' ')
continue;

else if((exp[i]>='0' && exp[i]<='9')|| exp[i]=='.'){
string num="";
while(isdigit(exp[i])|| exp[i]=='.'){
        num+=exp[i];
            i++;
        }
double a=stod(num);

push1(a);
}
else {
double x=pop1();
double y=pop1();


if (exp[i] == '+')
				push1(y + x);

			else if (exp[i] == '-')
				push1(y - x);

			else if (exp[i] == '*')
				push1(y * x);

			else if (exp[i] == '/')
				push1(y / x);

				else if (exp[i] == '%')
				push1(smod(y,x));

				else if (exp[i] == '^')
				push1(pow(y,x));
				}


}
double d=stod(stk1[top1]);
cout << stk1[top1];


}







int main()
{
cout <<fixed<<setprecision(9);
    int cont;
    string infix;
    string postfix;
    //cout<<Enter infix here:";
    cin>>infix;
    postfix = infix_to_postfix(infix);
    //cout << post;
    c
    expr_evaluation(postfix);
    //cout << d;

    return 0;
}
