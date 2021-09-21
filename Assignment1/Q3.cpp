#include<iostream>
using namespace std;

#define MAX 25

template <class T>

class Deque
{

public:

T *array;
int  f;
int  r;
int  sz;
T    x;
int counter;

Deque(int sz){
this->sz = sz;
f=-1;
r=0;
counter=0;
array=new T[sz];
}



Deque(){
array=new T[MAX];
f=-1;
r=0;
}




Deque(int sz,T x) {
this->sz = sz;
this->x=x;
array=new T[MAX];
counter=0;
f = -1;
r = 0;
for(int i=0;i<sz;i++){
if (f == -1) {
f = 0;
r = 0;
}
else if (r==sz-1)
r = 0;
else
r = r+1;
array[r] = x ;
counter++;
    }
}



bool  isFull(){
return ((f == 0 && r == MAX-1)||f == r+1);
}



bool  empty(){
return (f == -1);
}




T D(int x){
if(!empty()){
int var=f;
var = (var + x ) % MAX;
return array[var];
    }
}




void push_back(T key){
if (isFull()) {
cout << "Deque Overflow !!\n " << endl;
return;
}
else if (f == -1) {
f = 0;
r = 0;
array[r] = key ;
}
else if (r == MAX-1) {
r = 0;
array[r] = key ;
}
else{
r = r+1;
array[r] = key ;
}
counter++;
}





void pop_back() {
if (empty()) {
cout << " Underflow!!\n" << endl ;
return ;
}
if (f == r) {
f = -1;
r = -1;
}
else if (r == 0)
r = MAX-1;
else
r = r-1;
counter--;
}




T back(){
if(empty() || r < 0){
cout << " Underflow!!\n" << endl;
return -1 ;
}
return array[r];
}




void push_front(T x){
 if(isFull())
 cout << "overflow"<<endl;
else if (f == -1)  {
f = 0;
r = 0;
array[f] = x ;
}
else if(f==0){
f = MAX - 1 ;
array[f] = x ;
}
else{
f = f-1;
array[f] = x ;
}
counter++;
}




void pop_front() {
if(f==-1 && r==-1)
cout <<"Deque empty";
else if (f == r){
f = -1;
r = -1;
}
else {
f = (f+1)%MAX;
}
counter--;
}




T front(){
if (empty()){
cout << " Deque Underflow!!\n" << endl;
return -1 ;
}
return array[f];
}




void clear(){
    f=-1;
    r=0;
    counter=0;
}

void size(){
    cout << counter<<endl;
}



void resize(int x){
T *arr;
arr=new T[x];
for(int i=0;i<MAX;i++)
arr[i]=array[i];
delete [] array;
array=arr;
arr=NULL;

}


void print(){
 int i = f;
 while(i!=r){
cout << array[i]<<" ";
i=(i+1)%MAX;
 }
cout <<array[r] << " ";
}

};




int main(){
Deque<float>d1(15);
d1.push_back(4.5);
d1.push_back(5.89);
d1.push_back(6.85);
d1.push_front(2.15);
d1.print();
cout <<endl;
cout << d1.D(1)<<endl;
d1.size();
d1.resize(25);
d1.print();

/*int x=d1.back();
cout << x<<endl;
int y=d1.front();
cout <<y<<endl;
d1.pop_back();
d1.print();
cout << endl;

int a= d1.front();
cout << a <<endl;
int b= d1.back();
cout << b <<endl;
cout << d1.isFull()<<endl;
cout << d1.empty()<<endl;



Deque<int> d2(5,8);

d2.print();*/


return 0;
   }
