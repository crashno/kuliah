#include <iostream>
using namespace std;

int main(){
    int a[10];
    int c;
    for(int i=1; i<=9; i++){
        cin >> c;
        a[i]=c;
    }
    for(int i=1; i<=9;i++){
        cout << a[i]<<" "<<endl;
    }
return 0;
}
