#include<bits/stdc++.h>
using namespace std;

#define size 100
class SymbolInfo{
    public:
    string SymbolName;
    string symbolType;

};

class symbolTable
{
public:
    vector<SymbolInfo> hashtable[size];
    int hashIndexfun(string name) {
        int sum=0;
        for(int i = 0; i < name.length(); i++) {
            int index = name[i];
            index= index<<2;
            sum += index;
        }
        int hashIndex = sum % size; 
        return hashIndex;
    }

    void hashfunction(SymbolInfo sym){
         string name = sym.SymbolName;
           int hashIndex = hashIndexfun(name);     
        cout << "Indexing value: " << hashIndex << endl;
        hashtable[hashIndex].push_back(sym);
    }
    void insert(SymbolInfo sym){
        hashfunction(sym);
    }
    void Lookup(string name){
        int hashIndex = hashIndexfun(name);
        if(!hashtable[hashIndex].empty()) {
            int i_row=-1;
            SymbolInfo s;
            for(auto &sym : hashtable[hashIndex]) {
                i_row++;
                if(sym.SymbolName == name) {
                    s= sym;
                    break;
                }
            }
            if(i_row != -1) {
                cout << "Symbol found at index " << hashIndex << "," << i_row << ": " 
                     << s.SymbolName << ", Type: " << s.symbolType << endl;
            } else {
                cout << "Symbol not found in the table." << endl;
            }
        } else {
            cout << "Symbol not found in the table." << endl;
        }

    }
    void Delete(){

    }
    void printf(){

    }
};

int main() {
    symbolTable st;
    // Example usage of the symbol table
    SymbolInfo sym1;
    sym1.SymbolName = "int";
    sym1.symbolType = "int";

    st.insert(sym1);

    SymbolInfo sym2;
    sym2.SymbolName = "y";
    sym2.symbolType = "float";

    st.insert(sym2);

    st.printf();
    st.Lookup("int");

    return 0;
}