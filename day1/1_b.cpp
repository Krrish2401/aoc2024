#include <bits/stdc++.h>
using namespace std;

int f(vector<pair<int,int>> input) {
    vector<int> f;
    unordered_map<int,int> freq;

    for(auto &p : input){
        f.push_back(p.first);
        freq[p.second]++;
    }

    int ans=0;

    for(int i : f){
        if(freq.count(i)){
            ans += i*freq[i];
        }
    }

    return ans;
}

int main(){
    ifstream file("input.txt");
    if(!file){
        cerr<<"unable to open file";
    }

    vector<pair<int,int>> input;
    int left,right;

    while(file>>left>>right){
        input.emplace_back(left,right);
    }

    file.close();

    int ans = f(input);
    cout<<"ans is "<<ans;
    return 0;
}