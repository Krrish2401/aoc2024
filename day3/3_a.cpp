#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    if(!file){
        cout<<"unable to open file";
        return 1;
    }

    string line;
    regex expression(R"(mul\((\d+),(\d+)\))");
    smatch match;
    int sum=0;
    
    while(getline(file,line)){
        for(sregex_iterator i(line.begin(),line.end(),expression), end_i; i!=end_i; i++){
            sum+= stoi(i->str(1)) * stoi(i->str(2));
        }
    }
    
    file.close();

    cout<<sum;
    
    return 0;
}