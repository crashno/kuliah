#include <iostream>
#include "header_compression.h"
using namespace std;
int round_key_tmp[100]={0};
int round_key[100]={0};

void compress(){
    round_key[0]=round_key_tmp[13];
    round_key[1]=round_key_tmp[16];
    round_key[2]=round_key_tmp[10];
    round_key[3]=round_key_tmp[23];
    round_key[4]=round_key_tmp[0];
    round_key[5]=round_key_tmp[4];
    round_key[6]=round_key_tmp[2];
    round_key[7]=round_key_tmp[27];

    round_key[8]=round_key_tmp[14];
    round_key[9]=round_key_tmp[5];
    round_key[10]=round_key_tmp[20];
    round_key[11]=round_key_tmp[9];
    round_key[12]=round_key_tmp[22];
    round_key[13]=round_key_tmp[18];
    round_key[14]=round_key_tmp[11];
    round_key[15]=round_key_tmp[3];

    round_key[16]=round_key_tmp[25];
    round_key[17]=round_key_tmp[7];
    round_key[18]=round_key_tmp[15];
    round_key[19]=round_key_tmp[6];
    round_key[20]=round_key_tmp[26];
    round_key[21]=round_key_tmp[19];
    round_key[22]=round_key_tmp[12];
    round_key[23]=round_key_tmp[1];

    round_key[24]=round_key_tmp[40];
    round_key[25]=round_key_tmp[51];
    round_key[26]=round_key_tmp[30];
    round_key[27]=round_key_tmp[36];
    round_key[28]=round_key_tmp[46];
    round_key[29]=round_key_tmp[54];
    round_key[30]=round_key_tmp[29];
    round_key[31]=round_key_tmp[39];

    round_key[32]=round_key_tmp[50];
    round_key[33]=round_key_tmp[44];
    round_key[34]=round_key_tmp[32];
    round_key[35]=round_key_tmp[47];
    round_key[36]=round_key_tmp[43];
    round_key[37]=round_key_tmp[48];
    round_key[38]=round_key_tmp[38];
    round_key[39]=round_key_tmp[55];

    round_key[40]=round_key_tmp[33];
    round_key[41]=round_key_tmp[52];
    round_key[42]=round_key_tmp[45];
    round_key[43]=round_key_tmp[41];
    round_key[44]=round_key_tmp[49];
    round_key[45]=round_key_tmp[35];
    round_key[46]=round_key_tmp[28];
    round_key[47]=round_key_tmp[31];
}

int main()
{

    //initial permutation
    int data_awal[100]= {0, 1,0,1,0, 0,0,0,0, 0,1,1,1, 0,0,0,1,
                            1,0,1,1, 1,0,0,0, 0,0,0,1, 0,0,1,1,
                            0,0,1,1, 0,1,0,1, 0,1,1,1, 1,0,0,1,
                            1,0,0,1, 0,1,1,1, 1,0,1,0, 1,1,0,0};
    int data_akhir[100]={0};

    int data_satu[29]={0};
    int data_dua[29]={0};

    int data_temp_satu[29]={0};
    int data_temp_dua[29]={0};
    int data_tmp[29]={0};

    int a;
    int i;
    cout << "Random Key Awal"<<endl;
    for(i=1; i<=64; i++){
        cout << data_awal[i];
        if(i%4==0 ) cout <<" ";
    }

    a=57;
    for(i=1; i<=8; i++)
    {
        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=58;
    for(i=9; i<=16; i++)
    {
        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=59;
    for(i=17; i<=24; i++)
    {
        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=60;
    for(i=25; i<=28; i++)
    {

        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=63;
    for(i=29; i<=36; i++)
    {

        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=62;
    for(i=37; i<=44; i++)
    {

        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=61;
    for(i=45; i<=52; i++)
    {
        data_akhir[i]= data_awal[a];
        a-=8;
    }

    a=28;
    for(i=53; i<=56; i++)
    {
        data_akhir[i]= data_awal[a];
        a-=8;
    }

    //print data_parity
    cout << endl<<"Reduce Bit parity :"<<endl;
    for(int j=1; j<=56; j++)
    {
        cout << data_akhir[j];
        if(j%4==0) cout << " ";
    }

    //round1
    cout <<endl << endl<< "//dibagi 2 :";
    cout << endl<<endl << "L0: "<<endl;

    for(i=0; i<28;i++){
        data_satu[i]=data_akhir[i+1];

        cout << data_satu[i];
        if((i+1)%4==0) cout << " ";
    }

    cout << endl << "R0: "<<endl;

    for(i=0; i<28;i++){
        data_dua[i]=data_akhir[i+29];
        cout << data_dua[i];
        if((i+1)%4==0) cout << " ";
    }

    //ini buat shifting
    for(i=0; i<28; i++){
        if(i==27){
        data_temp_satu[i]=data_satu[1];
        data_temp_dua[i]=data_dua[1];
        }else{
        data_temp_satu[i]=data_satu[i+1];
        data_temp_dua[i]=data_dua[i+1];
        }
    }

    for(i=0; i<28; i++){
        data_satu[i]=data_temp_satu[i];
        data_dua[i]=data_temp_dua[i];
    }

    cout <<endl<< endl<<"Ronde 1"<<endl<<"Ini hasil shift left 1 bit" <<endl<<"ini hasil shif  L:"<<endl;
    for(i=0; i<28; i++){
        cout << data_satu[i];
        if((i+1)%4==0) cout << " ";
    }

    cout << endl<< "ini hasil shift R :"<<endl;
    for(i=0; i<28;i++){
        cout << data_dua[i];
        if((i+1)%4==0) cout << " ";
    }

    for(i=0; i<28; i++){
        round_key_tmp[i]=data_satu[i];
    }
    for(i=28; i<56; i++){
        round_key_tmp[i]=data_dua[i-28];
    }

    cout << endl<< "ini hasil compression table (Round Key 1) :"<<endl;
    compress();

    for(i=0; i<48;i++){
        cout << round_key[i];
        if((i+1)%4==0) cout << " ";
    }

    cout << endl<< "Selesai Round Key 1, hitung sendiri hasil diatasnya"<<endl<<endl << "//RoundKey2"<<endl;

    //ini buat shifting
    for(i=0; i<28; i++){
        data_temp_satu[i]=data_satu[i+1];
        data_temp_dua[i]=data_dua[i+1];
    }
    data_temp_satu[27]=data_satu[0];
    data_temp_dua[27]=data_dua[0];

    for(i=0; i<28; i++){
        data_satu[i]=data_temp_satu[i];
        data_dua[i]=data_temp_dua[i];
    }

    cout <<endl<< endl<< "ini shift left  L lagi:"<<endl;
    for(i=0; i<28; i++){
        cout << data_satu[i];
        if((i+1)%4==0) cout << " ";
    }

    cout << endl<< "ini hasil shift left R lagi :"<<endl;
    for(i=0; i<28;i++){
        cout << data_dua[i];
        if((i+1)%4==0) cout << " ";
    }

    for(i=0; i<28; i++){
        round_key_tmp[i]=data_satu[i];
    }
    for(i=28; i<56; i++){
        round_key_tmp[i]=data_dua[i-28];
    }


    cout << endl<< "ini hasil compression table (Round Key 2) :"<<endl;
    compress();

    for(i=0; i<48;i++){
        cout << round_key[i];
        if((i+1)%4==0) cout << " ";
    }

    return 0;
}
