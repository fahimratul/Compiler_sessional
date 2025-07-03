#include<bits/stdc++.h>
using namespace std;

#define size 100
#define id "202314402" // Your id, which is used to generate a hash value.
#define lastdigitofid 2; // Then left shift each ASCII value by the last digit of your student ID,

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

class symbolTable
{
public:
    vector<SymbolInfo> hashtable[size];
    int charnumber=numberofchar();

    // Function to calculate the hash index based on the symbol name
    int hashIndexfun(string name) {
        int sum=0;
        for(int i = 0; i < charnumber; i++) {
            int index = name[i];
            index= index<<lastdigitofid;
            sum += index;
        }
        int hashIndex = sum % size; 
        return hashIndex;
    }
    // Function to insert a symbol into the hash table
    void insert(SymbolInfo sym){
        pair<int,int> search=Lookup(sym.SymbolName); //lookup the symbol to check if it already exists
        if(search.first != -1) { 
            // If the symbol does not exist, insert it into the hash table
            hashtable[search.first].push_back(sym);
            cout <<"Inserted at position: " << search.first << ", " << search.second << endl;
        } else {
            cout << "Symbol already exists in the table." << endl;
        }
    }

    pair<int,int> Lookup(string name){
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
                return make_pair(hashIndex, i_row);
            } else {
                return make_pair(-1, -1); // Symbol not found
            }
        } else {
            return make_pair(-1, -1); // Symbol not found
        }
    }

    void Delete(string name){
        pair<int,int> search=Lookup(name);  // Lookup the symbol to check if it exists
        if(search.first != -1) {
            // If the symbol exists, remove it from the hash table
            hashtable[search.first].erase(hashtable[search.first].begin() + search.second);
            cout << "Deleted from " << search.first << ", " << search.second << endl;
        } else {
            cout << "Symbol not found in the table." << endl;
        }
    }
    void printf(){
        for(int i = 0; i < size; i++) {
            cout<<i << " ->";
            if(!hashtable[i].empty()) {
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
    string operation, name, type;
    while (cin>>operation>> name >> type) {
        SymbolInfo sym;
        sym.SymbolName = name;
        sym.symbolType = type;
        if(operation == "I") {
            st.insert(sym);
        }
         else if (operation == "L") {
            pair<int,int> search = st.Lookup(name);
            if(search.first != -1) {
                cout << "Found at " << search.first << ", " << search.second << endl;
            } else {
                cout << "Not found." << endl;
            }
        }
         else if (operation == "D") {
            st.Delete(name);
        }
         else  if (operation == "P") {
            st.printf();
        }
        else {
            cout << "Invalid operation." << endl;
        }
    }
    
    return 0;
}