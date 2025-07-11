#include<bits/stdc++.h>
using namespace std;

#define size 10
#define id "202314402" //MD FAHIM MORSHED RATUL
#define lastdigit 2 // ID: 202314402, Section A

class SymbolInfo{
    public:
    string SymbolName;
    string symbolType;
};

int numberofchar(){
    string str=id;
    int sum=0;
    for(int i=0;i<str.length();i++){
        sum += str[i];
    }
    sum=sum%9+1;
    return sum;
}   

class symbolTable{

    vector<SymbolInfo> hashtable[size];
    int charnumber = numberofchar();
    
    int hashIndexfun(string name) {
        int sum=0;
        for(int i = 0; i <charnumber && i<name.length(); i++) {
            int index = static_cast<int>(name[i]);
            index= index << lastdigit;
            sum += index;
        }
        int hashIndex = sum % size; 
        return hashIndex;
    }

    int hashfunction(SymbolInfo sym){
        string name = sym.SymbolName;
        int hashIndex = hashIndexfun(name);
        hashtable[hashIndex].push_back(sym);
        return hashIndex;
    }

    public:  
    
    void insert(SymbolInfo sym){
        pair<int, int> search = Lookup(sym.SymbolName);
        if(search.first != -1) {
            cout <<"Already exists"<< endl;
            return;
        }
        int hashIndex=hashfunction(sym);
        cout<<"Inserted at position:"<<hashIndex<< ", " << search.second << endl;
    }

    pair<int,int> Lookup(string name){
        int hashIndex = hashIndexfun(name);
        int i_row=-1;
        if(!hashtable[hashIndex].empty()) {
            SymbolInfo s;
            for(auto &sym : hashtable[hashIndex]) {
                i_row++;
                if(sym.SymbolName == name) {
                    s= sym;
                    return make_pair(hashIndex, i_row);
                }
            }
                return make_pair(-1,i_row+1);
            }
        else {
            return make_pair(-1, 0);
        }

    }
    
    void Delete(string name){
        pair<int,int> search=Lookup(name);
        if(search.first != -1) {
            hashtable[search.first].erase(hashtable[search.first].begin() + search.second);
            cout << "Deleted from " << search.first << ", " << search.second << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }

    void printf(){
        for(int i = 0; i < size; i++) {
            if(!hashtable[i].empty()) {
                cout<<i << " ->";
                for(auto &sym : hashtable[i]) {
                    cout<<"<" << sym.SymbolName << ", " << sym.symbolType << "> ";
                }
                cout << endl;
            }
        }
    }

};

int main() {
    symbolTable st;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string operation;
    string name, type;
    
    while (cin >> operation) {
        if (operation == "I") {
            cin >> name >> type;
            SymbolInfo sym;
            sym.SymbolName = name;
            sym.symbolType = type;
            st.insert(sym);
        }
        else if (operation == "L") {
            cin >> name;
            pair<int,int> search = st.Lookup(name);
            if(search.first != -1) {
                cout << "Found at " << search.first << ", " << search.second << endl;
            } else {
                cout << "Not found." << endl;
            }
        }
        else if (operation == "D") {
            cin >> name;
            st.Delete(name);
        }
        else if (operation == "P") {
            st.printf();
        }
        else {
            cout << "Invalid operation." << endl;
        }
    }

    return 0;
}