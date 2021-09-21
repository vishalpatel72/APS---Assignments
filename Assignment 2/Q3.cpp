#include <iostream>
using namespace std;

int n=1;
template<typename T,typename U>
struct Node
{
    T key;
    U value;
    Node *left, *right;
    Node(const T &k,const U &v):key(k),value(v),left(nullptr),right(nullptr){}
};
template<typename T,typename U>
class ordered_map
{
public:
    ordered_map<T,U>(){root=nullptr;}
    Node<T,U> *root;
    inline int getHeight(Node<T,U> *node);
    inline int getBalance(Node<T,U> *node);
    inline Node<T,U>* rotationLeft(Node<T,U> *node);
    inline Node<T,U>* rotationRight(Node<T,U> *node);
    inline Node<T,U>* successor(Node<T,U> *node);
    inline void print(Node<T,U> *node);
    inline void preOrder(Node<T,U> *node);
    Node<T,U>* insert(Node<T,U>* &node, const T &key,const U &value);
    Node<T,U>* erase(Node<T,U> *node, const T &key);
     bool find(Node<T,U> *node,const T &key);
    void find(const T &key);
     //Node<T,U>* search(Node<T,U> *node,const T &key);
    int size(Node<T,U> *node);
    void size();
    void clear(Node<T,U> *node);
    void clear();
    // U operator [](const T &key);
   U& get_val(Node<T,U> *node,const T &key);
   U& operator [](const T &key);

    inline void insert(const T &key,const U &value);
    inline void erase(const T &key);
    inline void print();
    inline void preOrder();
};
template<typename T,typename U>
inline int ordered_map<T,U>::getHeight(Node<T,U> *node)
{
    if(node == nullptr)
        return -1;
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}
template<typename T,typename U>
inline int ordered_map<T,U>::getBalance(Node<T,U> *node)
{
    if(node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
template<typename T,typename U>
inline Node<T,U>* ordered_map<T,U>::rotationLeft(Node<T,U>* x)
{
    Node<T,U> *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
template<typename T,typename U>
inline Node<T,U>* ordered_map<T,U>::rotationRight(Node<T,U>* x)
{
    Node<T,U> *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
template<typename T,typename U>
inline Node<T,U>* ordered_map<T,U>::successor(Node<T,U> *node)
{
    while(node->left != nullptr)
        node = node->left;
    return node;
}

template<typename T,typename U>
Node<T,U>* ordered_map<T,U>::insert(Node<T,U>* &node, const T &key,const U &value)
{
    if(node == nullptr)
        return new Node<T,U>(key,value);
        else if(key==node->key)
        return new Node<T,U>(key,value);
    else if(key < node->key)
        node->left = insert(node->left, key,value);
    else if(key > node->key)
        node->right = insert(node->right, key,value);
    else
        return node;
    int balance = getBalance(node);
    if(balance > 1)
    {
        if(key < node->left->key)
            return rotationRight(node);
        if(key > node->left->key)
        {
            node->left = rotationLeft(node->left);
            return rotationRight(node);
        }
    }
    else if(balance < -1)
    {
        if(key > node->right->key)
            return rotationLeft(node);
        if(key < node->right->key)
        {
            node->right = rotationRight(node->right);
            return rotationLeft(node);
        }
    }
    return node;
}
template<typename T,typename U>
inline void ordered_map<T,U>::insert(const T &key,const U &value)
{
    root = insert(root, key,value);
}
template<typename T,typename U>
inline Node<T,U>* ordered_map<T,U>::erase(Node<T,U> *node, const T &key)
{
    if(node == nullptr)
        return node;
    if(key < node->key)
        node->left = erase(node->left, key);
    else if(key > node->key)
        node->right = erase(node->right, key);
    else
    {
        Node<T,U> *tmp = nullptr;
        if(node->left != nullptr && node->right != nullptr)
        {
            tmp = successor(node->right);
            node->key = tmp->key;
            node->right = erase(node->right, tmp->key);
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
template<typename T,typename U>
inline void ordered_map<T,U>::erase(const T &key)
{
    root = erase(root, key);
}
template<typename T,typename U>
inline void ordered_map<T,U>::print(Node<T,U> *node)
{
    if(node == nullptr)
        return;
    print(node->left);
    cout << node->key << ","<<node->value<<" ";
    print(node->right);
}
template<typename T,typename U>
inline void ordered_map<T,U>::preOrder(Node<T,U> *node)
{
    if(node == nullptr)
        return ;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T,typename U>
inline bool ordered_map<T,U>::find(Node<T,U>* node,const T &key)
{
    if (node == NULL)
        return false;

    if (node->key == key)
        return true;

    bool res1 = find(node->left, key);

    if(res1) return true;
    bool res2 = find(node->right, key);

    return res2;
}
 template<typename T,typename U>
inline void ordered_map<T,U>::find(const T &key)
{
    bool x=find(root,key);
    if(x)
    cout << "found";
    else
    cout<< "Not found";
}


 template<typename T,typename U>
inline int ordered_map<T,U>::size(Node<T,U> *node)
{
    if(node==NULL)
    return 0;
    if(node->left!=NULL)
    {
        n=n+1;
        n=size(node->left);
    }
    if(node->right!=NULL)
    {
        n=n+1;
        n=size(node->right);
    }
    return n;

}


 template<typename T,typename U>
inline void ordered_map<T,U>::size()
{
    int s=size(root);
    cout << s;
}


 /*template<typename T,typename U>
inline Node<T,U>* ordered_map<T,U>::search(Node<T,U> *node,const T &key)
{
    if (node == NULL || node->key == key)
       return node;

    if (node->key < key)
       return search(node->right, key);

    return search(node->left, key);
}


template<typename T,typename U>
inline U ordered_map<T,U>::operator [](const T &key)
{
Node<T,U> *tmp=search(root,key);
    if(tmp)
    return tmp->value;
    return -1;
}*/

template<typename T,typename U>
inline U& ordered_map<T,U>:: get_val(Node<T,U> *node,const T &key)
{
if(node->key==key)
return node->value;
else if(key<node->key)
return get_val(node->left,key);
else
return get_val(node->right,key);
}


template<typename T,typename U>
inline U& ordered_map<T,U>::operator [](const T &key)
{
if(!find(root,key))
root=insert(root,key,0);
return get_val(root,key);
}


 template<typename T,typename U>
inline void ordered_map<T,U>::clear(Node<T,U> *node)
{
if(node==NULL)
return;
clear(node->left);
clear(node->right);
delete node;
}


 template<typename T,typename U>
inline void ordered_map<T,U>::clear()
{
clear(root);
cout<<"map cleared";
}

template<typename T,typename U>
inline void ordered_map<T,U>::print()
{
    cout << " map content: " ;
    print(root);
    cout << endl;
}


int main()
{
    ordered_map<int,char> m1;
     int key;
     char value;
        m1.insert(1,'a');
        m1.insert(2,'b');
        m1.insert(3,'c');
        m1.insert(4,'a');
        m1.insert(1,'d');

        //m1.erase(1);

    //}
    m1.print();
    cout<<endl;
    //m1.erase(1);
   // m1.print();
    //cout<<endl;
    //m1.find(2);
    cout<<endl;
    //m1.size();
   // cout<<endl;
    //m1.clear();
    //cout<<endl;
    m1.insert(10,'z');
    m1.print();
    cout<<endl;
    //cout << m1[10];
    cin>>key;
    cin>>value;
    m1[key]=value;
    m1.print();
    //cout << m1[key];



    return 0;
}
