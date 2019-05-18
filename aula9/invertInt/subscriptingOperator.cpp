#include <iostream>
using namespace std;

class myClass{
    private:
        string *str;
    
    public:
        myClass(){};
        myClass(string dado){
            str = new string[10];
            str[2] = dado;
        }
    
        virtual string &operator[](int i){
            return str[i];
        }
};

int main(){
    myClass *bla;
    bla = new myClass("isso dá um monte de erros");
    //myClass bla("isso não dá erro");
    cout << (*bla)[2] << endl;
    return 0;
}

/*
subscriptingOperator.cpp: In function ‘int main()’:
subscriptingOperator.cpp:24:10: error: no match for ‘operator<<’ 
(operand types are ‘std::ostream {aka std::basic_ostream<char>}’ and 
‘myClass<std::basic_string<char> >’)
     cout << bla[2] << endl;
          ^
subscriptingOperator.cpp:24:10: note: candidates are:
In file included from /usr/include/c++/4.8/iostream:39:0,
                 from subscriptingOperator.cpp:1:

*/