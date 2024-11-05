#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class SymbolTable{
    public:
    bool isDefined;
    bool isUsed;
};

//SYMBOL TABLE DISPLAY CODE
void display(map<string,string>symbol_table){
  cout<<"symbol\t";
  cout<<"type\n";
  for(auto i:symbol_table){
    cout<<i.first<<"\t";
    cout<<i.second<<endl;
  }
}

//ASSEMBLER CODE
void assembler(map<string,SymbolTable>Table){
    bool noErrors=false;
    cout<<"CHECKING FOR ERRORS>>>....."<<endl;
   for(auto i:Table){
    if(i.second.isUsed && !i.second.isDefined){
        cout<<"ERROR...."<<i.first<<" is used but not defined"<<endl;
        noErrors=true;
    }
    if(i.second.isDefined && !i.second.isUsed){
        cout<<"Warning...."<<i.first<<" is defined but not used"<<endl;
        noErrors=true;
    }
     if(!noErrors){
        cout<<"No Errors";
     }

   }
}

int main(){
    // map<string,string>symbol_table;
    // symbol_table["x"]="int";
    // symbol_table["y"]="float";

    // display(symbol_table);

    map<string,SymbolTable>Table;

    //defining
    Table["x"]={true,false};
    Table["w"]={true,false};
    Table["y"]={true,false};
    Table["z"]={true,false};

    //using
    Table["x"].isUsed=true;
    Table["z"].isUsed=true;
    Table["Q"].isUsed=true;
    assembler(Table);

}
