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

    void hashfunction(SymbolInfo sym){
        string name = sym.SymbolName;
        int sum=0;
        for(int i = 0; i < name.length(); i++) {
            int index = name[i];
            index= index<<2;
            sum += index;
        }
        int hashIndex = sum % size; 
        cout << "Indexing value: " << hashIndex << endl;
        hashtable[hashIndex].push_back(sym);
    }
    void insert(SymbolInfo sym){
        cout<<"Inserting symbol: " << sym.SymbolName << " of type " << sym.symbolType << endl;
        hashfunction(sym);
    }
    void Lookup(){

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

    return 0;
}