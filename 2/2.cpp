#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size()/2;
    vector<int> animal, trap;
    vector<char> out;
    int out_sort[n+1];
    int count_animal=1, count_trap=0;
    for(int i=0; i<s.size(); i++){
        if(islower(s[i])){
            animal.push_back(count_animal);
            count_animal++;
        }
        else
        {
            trap.push_back(count_trap);
            count_trap++;
        }
        if(out.empty()){
            out.push_back(s[i]);
        }
        else{
            if((isupper(out.back()) && islower(s[i]) || islower(out.back()) && isupper(s[i]) )
            && tolower(out.back())== tolower(s[i])){
                out_sort[trap.back()] = animal.back();
                animal.pop_back();
                trap.pop_back();
                out.pop_back();
            }
            else
                out.push_back(s[i]);
        }
    }

    if (out.empty()){
        cout<<"Possible" << endl;
        for(int i =0; i< n; i++){
            cout<< out_sort[i]<< " ";
        }
    }
    else
        cout<< "Impossible";
    return 0;
}
