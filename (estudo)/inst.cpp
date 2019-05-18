#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main(){
    srand(time(NULL));
    char c;

    cout << rand()%20 << endl;
    for(int i=0;i<120;i++){
        int m = rand()%20, rnd = rand()%5;
        if(rnd==0)c='I';
        if(rnd==1)c='E';
        if(rnd==2)c='B';
        if(rnd==3)c='C';
        if(rnd==4)c='M';
        if(c!='M'){
            cout << c << " " << m << endl;
        }else{
            cout << c << endl;
        }
    }
    return 0;
}

