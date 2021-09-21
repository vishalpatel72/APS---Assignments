
#include<bits/stdc++.h>


using namespace std;

bool comparator(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2){
    if(p1.second.first == p2.second.first){

        if(p1.second.second < p2.second.second){
          return true;
        }
        else {
        return false;
      }
    }
    else{
        if(p1.second.first < p2.second.first){
             return true;
        }
        else {
    return false;
     }
  }
}

long long int LCP(string s1,string s2)
{
    long long int l1=s1.length();
    long long int l2=s2.length();
    long long int count=0;
    long long int len = min(l1,l2);
    for(long long int i=0;i<len;i++)
    {
        if(s1[i]==s2[i])
            count++;
        else
            break;
    }
    return count;
}


void longestAppears_Ktimes(string s,long long int k){
 long long int n = s.size();
    vector<pair<long long int,pair<long long int,long long int>>> mapper(n);

    vector<long long int> vec(n);

    for(long long int i=0;i< n ;i++){
        long long int val1=s[i]-'0';
        long long int val2;
        if((i+1)<n)
        val2=s[i+1]-'0';
        else val2=-1;
        mapper[i]={i,{val1,val2}};
    }

    sort(mapper.begin(), mapper.end(), comparator);

    for(long long int k = 4;k < (n*2);k*=2){

        long long int value=0;
                mapper[0].second.first=value;
        long long int pre=mapper[0].second.first;

        vec[mapper[0].first]=0;

        for(long long int i=1;i< n ;i++){
            if(mapper[i].second.first==pre && mapper[i].second.second==mapper[i-1].second.second){
                pre=mapper[i].second.first;
                mapper[i].second.first=value;
            }
            else{
                pre=mapper[i].second.first;
                value++;
                mapper[i].second.first=value;
            }
            vec[mapper[i].first]=i;
        }

        for(long long int i=0;i<n;i++){
            long long int new_value;
            long long int next=mapper[i].first + (k/2);

            if(next<n){
                new_value=mapper[vec[next]].second.first;
            }
            else{
                new_value=-1;
            }
            mapper[i].second.second=new_value;
        }
        sort(mapper.begin(), mapper.end(), comparator);
    }

    vector<long long int> v(n);
    for(long long int i=0;i<n;i++){
        v[i]=mapper[i].first;
    }
        //for(long long int i=0;i<n;i++)
//cout << v[i]<<endl;
 int maximum = 0;
    int result;

    for(long long int i=0;i<=n-k;i++)
    {
        string s1=s.substr(v[i]);
        string s2=s.substr(v[i+k-1]);
        //cout << s1 <<"   "<<s2<<endl;
        result = LCP(s1,s2);
        //cout << result<<endl;
        if(maximum<result)
        {
            maximum=result;
        }

    }

    if(maximum==0){
        cout << "-1";
    }

else{
 cout << maximum ;
  }
}

int main(){


    string s;
    cin>>s;
    long long int k;
    cin>>k;

    longestAppears_Ktimes(s,k);



    return 0;
}
