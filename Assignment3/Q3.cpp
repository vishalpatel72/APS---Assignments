#include <bits/stdc++.h>
#define chunksize 1000000
#define ll long long int

using namespace std;

ll arr[chunksize]={0};

struct minNode{
public:
ll ele;
ll ind;

};

class heap{

public:
ll sz;
struct minNode *h;
ll hsize;

void swapping(struct minNode*,struct minNode*);
void heapify(ll);
ll parent(ll);
ll left(ll);
ll right(ll);
void inserting(ll,ll);
ll extract_fnum();
ll extract_min();
void remove_min();
ll total_element();


heap(ll total){
hsize=0;
sz=total;
h =(struct minNode *)malloc(sizeof(struct minNode)*sz);

}


};

  void heap::swapping(struct minNode *a,struct minNode *b){

    ll tmp = a->ele;
    a->ele = b->ele;
    b->ele = tmp;
    tmp = a->ind;
    a->ind = b->ind;
    b->ind = tmp;
}

void heap::heapify(ll i){

    ll l = left(i);
    ll r = right(i);


    ll smallest=i;
     if(l < hsize && (h+l)->ele < (h+i)->ele)
     smallest=l;
    if(r < hsize && (h+r)->ele < (h+smallest)->ele)
    smallest=r;


    if (smallest != i) {
        swapping(h+i, h+smallest);
        heapify(smallest);
        }
    }

 ll heap :: parent(ll i){
  return floor((i-1)/2);
}
  ll heap :: left(ll i){
  return (2*i+1);
}
  ll heap :: right(ll i){
  return (2*i+2);
}
  ll heap::total_element(){
  return hsize;
  }

   void heap :: inserting(ll ind,ll ele){
    hsize++;
    ll value = hsize - 1;
    ll z=parent(value);
    (h+value)->ele = ele;
    (h+value)->ind = ind;
    while (value != 0 && ((h+z)->ele) > ((h+value)->ele)){
       swapping(h+value,h+z);
       value = z;
       z=parent(value);
    }
  }

  ll heap::extract_fnum(){
  return h->ind;
}
  ll heap::extract_min(){
  return h->ele;
}
  void heap::remove_min(){
 swapping(h,h+hsize-1);
    hsize--;
    heapify(0);
  }









void merge(ll arr[], ll l, ll m, ll r)
{
    ll n1 = m - l + 1;
    ll n2 = r - m;

    ll L[n1], R[n2];

    for(ll i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(ll j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    ll i = 0;

    ll j = 0;

    ll k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
        ll m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

vector<string> create_smallFiles(ll size,ifstream &iff,ofstream &of,ll *arr){
bool flag=true;
int fn=0;
string newfile;
string number="";
vector<string>vec;

while(flag){
        for(ll i=0;i<chunksize;i++){
      if(getline(iff, number,',')){

        if(i==0){

          fn+=1;
          newfile="file"+to_string(fn)+".txt";
          of.open(newfile);}

        arr[i]=stoll(number, nullptr, 10);
      }
      else{

        size=i;
        flag=false;
        break;
      }
    }
     mergeSort(arr,0,size-1);
    for(ll i=0;i<size;i++){

      of<<arr[i]<<",";
    }
    of.close();
  }
  iff.close();


  //cout<<fn<<endl;
  //cout<<number<<endl;
  string t=to_string(fn);

vec.push_back(t);
vec.push_back(number);

return vec;

}








int main(int argc,char **argv){

  if(argc!=3){
  cout<<"less argument"<<endl;
  exit(1);
}


ifstream iff(argv[1]);
ofstream of;

string newfile;
ll size=chunksize;
int res;

vector<string> result= create_smallFiles(size,iff,of,arr);
res=stoi(result[0]);
//cout<<res<<endl;
//cout<<result[1]<<endl;



ifstream ff[res+1];
heap h1(res);
ofstream out;
out.open("output.txt");


for(long long k=1;k<=res;k++){

    string name="";

    name ="file"+to_string(k)+".txt";
    ff[k].open(name.data());
    getline(ff[k], result[1],',');
    h1.inserting(k,stoll(result[1], nullptr, 10));
  }


   while(h1.total_element()!=0){

    ll minimum=h1.extract_min();

    ll cnt=h1.extract_fnum();


    h1.remove_min();

    out<<minimum<<",";



    if(getline(ff[cnt], result[1],',')){
      h1.inserting(cnt,stoll(result[1], nullptr, 10));
    }
    else{
      ff[cnt].close();
}
  }
  out.close();



//cout<<"hello"<<endl;




return 0;
}

