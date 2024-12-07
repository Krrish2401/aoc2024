#include <bits/stdc++.h>
using namespace std;

bool f(vector<int> v){
    for(int i=1; i<v.size(); i++){
        if(v[i]<=v[i-1]){
            return false;
        }
        int d = v[i]-v[i-1];
        if(1>d || 3<d){
            return false;
        }
    }
    return true;
}

bool f2(vector<int> v){
    for(int i=1; i<v.size(); i++){
        if(v[i]>=v[i-1]){
            return false;
        }
        int d = v[i-1]-v[i];
        if(1>d || 3<d){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream file("input.txt");
    if(!file){
        cerr<<"unable to open file";
    }

    int c=0;
    string line;
    
    while(getline(file,line)){
        stringstream ss(line);
        int num;
        vector<int> v;
        while(ss>>num){
            v.push_back(num);
        }
        if(f(v) || f2(v)){
            c++;
        }
    }
    cout<<c;
    
    return 0;
}