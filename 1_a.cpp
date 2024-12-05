#include <bits/stdc++.h>
using namespace std;

int f(vector<pair<int,int>> input){

    vector<int> f,s;

    for(auto &p : input){
        f.push_back(p.first);
        s.push_back(p.second);
    }

    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    
    int sum=0;
    for (size_t i = 0; i < f.size(); ++i) {
        sum += abs(f[i] - s[i]);
    }

    return sum;
}

int main(){
    ifstream file("input.txt");
    if(!file){
        cerr<<"Cannot open file!"<<endl;
    }

    vector<pair<int,int>> v;
    int left,right;

    while(file>>left>>right){
        v.emplace_back(left,right);
    }

    file.close();


    int res = f(v);
    cout<<"ans is "<<res;
    return 0;
}