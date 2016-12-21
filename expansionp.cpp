#include <iostream>
using namespace std;

int main()
{
    int data_dua[100]= {1,1,1,1,0,1,1,0,0,0,0,1,1,1,1,1,
                         0,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1};
    int data_ekspan[100]={0};
    int i;
    for(i=; i<48;i++){
        if(i==0)
        data_ekspan[i]=data_dua[31];

        else if(i<=5)
        data_ekspan[i]=data_dua[i-1];

        else if(i<=11)
        data_ekspan[i]=data_dua[i-3];

        else if(i<=17)
        data_ekspan[i]=data_dua[i-5];

        else if(i<=23)
        data_ekspan[i]=data_dua[i-7];

        else if(i<=29)
        data_ekspan[i]=data_dua[i-9];

        else if(i<=35)
        data_ekspan[i]=data_dua[i-11];

        else if(i<=41)
        data_ekspan[i]=data_dua[i-13];

        else if(i<=46)
        data_ekspan[i]=data_dua[i-15];

        else
            data_ekspan[i]=data_dua[0];
    }

     for(i=0; i<48;i++){
        if(i%4==0 && i>0) cout << " ";
        cout << data_ekspan[i];
     }
    return 0;
}
