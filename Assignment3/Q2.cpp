#include <bits/stdc++.h>
using namespace std;

class trie{
public:
trie *zero;
trie *one;
};

void insert(int val,trie *head){
trie *curr=head;
for(int i=63;i>=0;i--){
int bit=(val >> i) & 1;
if(bit==0){
if(curr->zero==NULL){
curr->zero=new trie();
}
curr=curr->zero;
}
else{
if(curr->one==NULL){
curr->one=new trie();
}
curr=curr->one;

      }
  }

}

unsigned long long int  find_MaxXOR(trie *head,unsigned long long int *arr,int n,int el){
unsigned long long int res=0;
trie* curr=head;
int val=el;
int curr_max=0;
for(int i=63;i>=0;i--){
int bit=(val >> i) & 1;
if(bit==0){
if(curr->one!=NULL){
curr=curr->one;
curr_max+=(unsigned long long int )pow(2,i);
}
else{
curr=curr->zero;
  }
}
else{
if(curr->zero!=NULL){
curr=curr->zero;
curr_max+=(unsigned long long int)pow(2,i);
}
else{
curr=curr->one;
}

        }
     }
     if (curr_max>res)
     res=curr_max;
     return res;
   }


int main()
{
int n,q;
cin>>n>>q;
trie *head=new trie();
unsigned long long int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
insert(arr[i],head);
}
for(int i=0;i<n;i++){
int el;
cin>>el;
    cout << find_MaxXOR(head,arr, n,el) << endl;
    }
    return 0;
}
