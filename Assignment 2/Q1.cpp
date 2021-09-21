#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

template <class T> struct islessthn{
	bool operator()(const T &lft,const T &rght){
		return lft<rght;
	}
};

template<typename T>
struct Node
{
    T key;
    Node *left, *right;
    int count;
    Node(const T &k):key(k),left(nullptr),right(nullptr),count(1){}
};

template <class T,class comparator=islessthn<T>>
class AVLTree
{
public:

    Node<T> *root;
    comparator c;
    AVLTree(){root=nullptr;c=comparator();}

 int getHeight(Node<T> *node)
{
    if(node == nullptr)
        return -1;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalance(Node<T> *node)
{
    if(node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}


Node<T>* rotationLeft(Node<T>* x)
{
    Node<T> *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node<T>* rotationRight(Node<T>* x)
{
    Node<T> *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}


 Node<T>* successor(Node<T> *node)
{
    while(node->left != nullptr)
        node = node->left;
    return node;
}

Node<T>* insert(Node<T>* &node, const T &key)
{
    if(node == nullptr)
        return new Node<T>(key);
         if (!c(key,node->key)&&!c(node->key,key)) {
        (node->count)++;
        return node;
         }
    else if(c(key,node->key))
        node->left = insert(node->left, key);
    else if(c(node->key,key))
        node->right = insert(node->right, key);
    else
        return node;
    int balance = getBalance(node);
    if(balance > 1)
    {
        if(c(key,node->left->key))
            return rotationRight(node);
        if(c(node->left->key,key))
        {
            node->left = rotationLeft(node->left);
            return rotationRight(node);
        }
    }
    else if(balance < -1)
    {
        if(c(node->right->key,key))
            return rotationLeft(node);
        if(c(key,node->right->key))
        {
            node->right = rotationRight(node->right);
            return rotationLeft(node);
        }
    }
    return node;
}

void insert(const T &key)
{
    root = insert(root, key);
}

 Node<T>* deletion(Node<T> *node, const T &key)
{
    if(node == nullptr)
        return node;
    if(c(key,node->key))
        node->left = deletion(node->left, key);
    else if(c(node->key,key))
        node->right = deletion(node->right, key);
    else
    {
         if (node->count > 1) {
            (node->count)--;
            return node;
        }
        Node<T> *tmp = nullptr;
        if(node->left != nullptr && node->right != nullptr)
        {
            tmp = successor(node->right);
            node->key = tmp->key;
            node->right = deletion(node->right, tmp->key);
        }
        else if(node->right == nullptr)
        {
            tmp = node;
            node = node->left;
            delete tmp;
        }
        else if(node->left == nullptr)
        {
            tmp = node;
            node = node->right;
            delete tmp;
        }
        else
        {
            delete node;
        }
    }
    int balance = getBalance(node);
    if(balance > 1)
    {
        if(getBalance(node->left) >= 0)
            return rotationRight(node);
        else
        {
            node->left = rotationLeft(node->left);
            return rotationRight(node);
        }
    }
    else if(balance < -1)
    {
        if(getBalance(node->right) <= 0)
            return rotationLeft(node);
        else
        {
            node->right = rotationRight(node->right);
            return rotationLeft(node);
        }
    }
    return node;
}


 void deletion(const T &key)
{
    root = deletion(root, key);
}

Node<T>* occurence(Node<T>* node,const T &key){
if(node==NULL)
return node;
if (!c(node->key,key)&&!c(key,node->key))
return node;
Node<T>* tmp=occurence(node->left,key);
if(tmp!=NULL)
return tmp;
Node<T>* temp=occurence(node->right,key);
return temp;
}
void occurence(const T &key){
Node<T>* x=occurence(root,key);
cout << x->count;
}

bool search(Node<T>* node,const T &key)
{
    if (node == NULL)
        return false;

    if (!c(node->key,key)&&!c(key,node->key))
        return true;

    bool res1 = search(node->left, key);

    if(res1) return true;
    bool res2 = search(node->right, key);

    return res2;
}

 void search(const T &key)
{
    int x=search(root,key);
    if(x)
    cout << "found";
    else
    cout<< "Not found";

}

T lowerbound(Node<T>* node,const T &key)
{
    T result=0;
while(true){
    if(node==nullptr)
   // cout << result<<endl;
    return result;

     else if(!c(node->key,key)&& !c(key,node->key))
    return key;
    else if(c(key,node->key)){
        result=node->key;
        node=node->left;
    }
    else{
        node=node->right;
    }

}

}

void  lowerbound(const T &key)
{
    T a=lowerbound(root,key);
   cout << a;
}

T upperbound(Node<T> *node,const T &key)
{
    T result=0;
while(true){
    if(node==NULL)
    return result;

    else if(c(key,node->key)){
        result=node->key;
        node=node->left;
    }
    else{
        node=node->right;
    }

}

}

void upperbound(const T &key)
{
    T a=upperbound(root,key);
    cout << a;
}



T closest_element(Node<T> *node,const T &key){
T lower=lowerbound(node,key);
if(!c(lower,key)&&!c(key,lower))
return lower;
int result=0;
while(true){
    if(node==nullptr)
    break;
    else if(c(node->key,key)){
        result=node->key;
        node=node->right;
    }
    else
    {
        node=node->left;
    }

}
if(lower==0)
return result;
else if(result==0)
return lower;
else if(key - result > lower - key)
return lower;
else
{
    return result;
}

}


void closest_element(const T &key)
{
    T a=closest_element(root,key);
    cout<<a;
}

T kthLargest(Node<T>* node, int *i, int k)
{
	if (node == nullptr)
		return 0;

	T val = kthLargest(node->right, i, k);

	if (val != 0)
		return val;

	if (++*i == k)
		return node->key;

	return kthLargest(node->left, i, k);
}

void kthLargest(int k)
{
	int i = 0;

	T res=kthLargest(root, &i, k);
	cout<<res;
}

int count_in_range(Node<T> *node,const T &low,const T &high){
if (node==nullptr)
return 0;

    if ((!c(node->key,high)&&!c(high,node->key)) && (!c(node->key,low)&&!c(low,node->key)))
        return node->count;

    if (!c(high,node->key) && !c(node->key,low))
         return node->count + count_in_range(node->left, low, high) +
                    count_in_range(node->right, low, high);

    else if (c(node->key,low))
         return count_in_range(node->right, low, high);

    else
    return count_in_range(node->left, low, high);

}

void count_in_range(const T &low,const T &high){
int a=count_in_range(root,low,high);
cout << a;

}


void inOrder(Node<T> *node)
{
    if(node == nullptr)
        return ;
    inOrder(node->left);
    cout << node->key << "("<<node->count<<")"<<" ";
    inOrder(node->right);
}

void preOrder(Node<T> *node)
{
    if(node == nullptr)
        return ;
    cout << node->key << "("<<node->count<<")"<<" ";
    preOrder(node->left);
    preOrder(node->right);
}


 void inOrder()
{
    cout << " inoder: " ;
    inOrder(root);
    cout << endl;
}

void preOrder()
{
    cout << "pre: ";
    preOrder(root);
    cout << endl;
}

};



int main()
{
    AVLTree<int> av;
    int array[15]={1,2,3,2,1,1,5,7,9,3,5,5,17,17,9};
    //cout << "insert: " << endl;
    for(int i=0;i<15;i++)
    {
        av.insert(array[i]);

    }

//cout<<endl;

    av.inOrder();
    cout <<endl;
   av.occurence(1);
    cout <<endl;
av.search(3);
cout <<endl;
av.lowerbound(9);
cout<<endl;
av.upperbound(9);
cout <<endl;
av.closest_element(10);
cout<<endl;
av.kthLargest(5);
cout<<endl;
av.count_in_range(3,17);
    return 0;
}
