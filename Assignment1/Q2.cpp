
#include <bits/stdc++.h>
using namespace std;

//exponentiation
void expo_multiplication(int *a,int no,int &n){ //expo multiplication function

int carry=0;
for( int i=0;i<n;i++){
int product=a[i]*no+carry;
a[i]=product%10;
carry=product/10;
}


while(carry!=0){
a[n]=carry%10;
carry=carry/10;
n++;
}

}



void big_power(int p,int q){     //p^q
if(q==1){
cout << p;
return;
}
else if(p==0){
cout << 0;
return;
}
else if(q==0){
cout << 1;
return;
}
int *a=new int[4000];
int n=0;
 int y=p;


 while(y!=0){
 a[n]=y%10;
 y=y/10;
 n++;

 }

 for(int i=2;i<=q;i++){
expo_multiplication(a,p,n);
}
for(int i=n-1;i>=0;i--){
cout << a[i];
}
delete[] a;
cout <<endl;

}



//factorial


void fact_multiplication(int *a,int no,int &n){

int carry=0;
for( int i=0;i<n;i++){
int product=a[i]*no+carry;
a[i]=product%10;
carry=product/10;

}


while(carry!=0){
a[n]=carry%10;
carry=carry/10;
n++;
}

}

void big_factorial(int number){

int *a=new int[4000];


for(int i=0;i<3000;i++)
a[i]=0;

a[0]=1;
int n=1;

for(int i=2;i<=number;i++){
fact_multiplication(a,i,n);
}
for(int i=n-1;i>=0;i--){
cout << a[i];
}
delete[] a;

}



int main(){
int n;
int query_no;
cin>>n;

for (int i=0;i<n;i++){
cin>>query_no;
if(query_no==1){
//exponentiation
int p,q;
cin>>p>>q;
big_power(p,q);
}
else if(query_no==2){
string s1,s2;
cin>>s1>>s2;
cout <<"sorry!couldn't make gcd program"<<endl;
}
else if(query_no==3){
//factorial

int number;
cin>>number;
big_factorial(number);
 }
}
return 0;
}
