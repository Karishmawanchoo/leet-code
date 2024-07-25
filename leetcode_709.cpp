#include<iostream>
#include<string>
using namespace std;

class Program{
    public:
    string toLowerCase(string s){
        string str;
        for(auto x:s){
            str += tolower(x);
        }
        return str;
    }
};

int main(){
    Program p;
    string s;
    cout << "Enter a string : ";
    cin>>s;
    cout<<p.toLowerCase(s);
    return 0;
}
