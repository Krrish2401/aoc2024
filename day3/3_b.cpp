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
    regex d(R"(do\(\))");
    regex dd(R"(don't\(\))");
    
    vector<tuple<int,string,smatch>> inst;

    int sum=0;
    bool e=true;

    getline(file,line);

    for(sregex_iterator it(line.begin(),line.end(),expression),end; it!=end; it++){
        inst.emplace_back(it->position(),"mul",*it);
    }
    for(sregex_iterator it(line.begin(),line.end(),d),end; it!=end; it++){
        inst.emplace_back(it->position(),"do",*it);
    }
    for(sregex_iterator it(line.begin(),line.end(),dd),end; it!=end; it++){
        inst.emplace_back(it->position(),"dont",*it);
    }

    sort(inst.begin(),inst.end(),[](const auto& a,const auto& b){
        return get<0>(a) < get<0>(b); 
    });

    for(const auto &i : inst){
        int pos = get<0>(i);
        string type = get<1>(i);
        smatch m = get<2>(i);

        if(type=="mul"){
            if(e){
                int x = stoi(m[1].str());
                int y = stoi(m[2].str());
                sum += x * y;
            }
        }
        else if(type=="do"){
            e=true;
        }
        else if(type=="dont"){
            e=false;
        }
    }

    file.close();
    
    cout<<sum;
    
    return 0;
}