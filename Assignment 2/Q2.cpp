#include<bits/stdc++.h>
#define ll long long
#define BUCKETS 200
#define prime 31

using namespace std;

template <typename T, typename U>
class Unordered_map{
    public:

    class node{
        public:
        T key;
        U value;
        node* next;
    };

    node* hashtable[BUCKETS];

    Unordered_map(){
        for(ll i=0;i<BUCKETS;i++){
            hashtable[i]=NULL;
        }
    }


    ll hash(T k){
        ostringstream os;
        os << k;
        string key=os.str();

        ll answer = key[0];
        for (int i=1; i<key.size(); i++){
            answer = ((answer*prime)%BUCKETS + key[i])%BUCKETS;
        }
        return answer%BUCKETS;
    }

    bool insert(T key, U value){
        ll index=hash(key);
        // cout<<index<<endl;
        if(hashtable[index]!=NULL){
            node* tmp=hashtable[index];
            while(tmp){
                if(tmp->key!=key){
                    tmp=tmp->next;
                }
                else{
                    return false;
                }
            }
        }
        node* new_node = new node();
        new_node->key=key;
        new_node->value=value;
        node* temp=hashtable[index];
        new_node->next=temp;
        hashtable[index]=new_node;
        return true;
    }


    void find(T key){
        ll index=hash(key);
        node* tmp=hashtable[index];
        while(tmp){
            if(tmp->key!=key){
                tmp=tmp->next;
            }
            else break;
        }
        if(tmp==NULL)
        cout<<"not found";
        else{
        cout<<"found";
        }
    }

    void operator[](T key){
        ll index=hash(key);
        node* tmp=hashtable[index];
        while(tmp){
            if(tmp->key!=key){
                tmp=tmp->next;
            }
            else break;
        }
        if(tmp==NULL)
        cout<<"not found";
        else
        cout<< tmp->value;


    }

    void erase(T key){
        ll index=hash(key);

        node* tmp=hashtable[index];
        node* prev=NULL;

        if(tmp!=NULL && tmp->key==key){
            hashtable[index]=tmp->next;
            free(tmp);
            return;
        }

        while(tmp!=NULL && tmp->key!=key){
            prev=tmp;
            tmp=tmp->next;
        }

        if(tmp==NULL)  return;

        prev->next=tmp->next;
        free(tmp);
        return;

    }


    void printhashtable(){
        for(ll i=0;i<BUCKETS;i++){
            if(hashtable[i]!=NULL){
                ll count=0;
                node* t=hashtable[i];
                cout<<i<<" -----> ";
                while(t){
                    count++;
                    cout<< t->key << ", "<< t->value ;
                    t=t->next;
                }
                cout<<endl;

            }
        }
    }

};

int main(){


    Unordered_map<string,int> m1;
    Unordered_map<float,string> m2;
    Unordered_map<int,int>m3;

     m1.insert("vish",545);
     m1.insert("bsh",554);
     m1.insert("dha",422);
     m1.insert("dhc",423);
     m1.insert("car",546);
     m1.insert("vatsal",45);
     m1.insert("mohit",809);
     m1.printhashtable();
     cout<<endl;
     m1.erase("mohit");
     m1.find("vatsal");
     //m1.printhashtable();
     cout <<endl;
    // m1.search("vatsal");
     cout<<endl;
     //m1.erase("vish");
     //m1.printhashtable();
     m2.insert(4.50,"rucha");
     m2.insert(36.5,"riddhi");

     m3.insert(5,8);
     m3.insert(29,7);
     m3.insert(456,7);
     m3.insert(31,7);
     m3.insert(7,7);
     m3.insert(36,7);
     m3.insert(7210,78);
     //m3.printhashtable();
     //cout<<endl;
    m3[5];



     //m2.printhashtable();
return 0;
}
