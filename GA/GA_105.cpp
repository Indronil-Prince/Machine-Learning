#include<bits/stdc++.h>
using namespace std;

int v[4][6]={0};
int d[4]={0};
int f[4]={0}, c[4]={0}, b[2]={0};
int temp[2][6]={0};
int plc, plc2, plc3, k, prob, p=-99999999;


void initialize()
{
    srand(time(NULL));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<6; j++)
        {
            v[i][j]=rand()%2;
        }
    }
}

void fitness()
{
    for(int i=0; i<4; i++)
    {
        f[i]=0;
        d[i]=0;
    }
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<6; j++)
        {
            d[i]=d[i]+((pow(2,5-j))*v[i][j]);
        }
        if(v[i][0]==1) d[i]=d[i]*(-1);
        f[i]=-(d[i]*d[i])+5;
    }
}

void selection()
{
    for(int i=0; i<4; i++)
    {
        c[i]=f[i];
    }
    sort(c, c+4);
    for(int i=0; i<4; i++)
    {
        if(c[3]==f[i]) {b[0]=i; break;}
    }
    for(int i=3; i>=0; i--)
    {
        if(c[2]==f[i])
        {
            if(b[0]!=i)
            {b[1]=i; break;}
        }
    }
    sort(b, b+1);
}

void crossover()
{
    plc=rand()%5;
//    cout << plc << endl;
//    cout << b[0] << " " << b[1] << endl;
    for(int i=plc; i<6; i++)
    {
        swap(v[b[0]][i], v[b[1]][i]);
    }
}

void mutaion()
{
    srand(time(NULL));
    prob=rand()%50;
    if(prob==20)
    {
    srand(time(NULL));
    plc2=rand()%3;
    plc3=rand()%5;
    v[plc2][plc3]=1-v[plc2][plc3];
    }
}

int main()
{
initialize();
for(int x=0; x<1000; x++){
cout <<"Iteration - " << x+1 << " : " << endl;
cout << "Chromosomes : " << endl;
for(int i=0; i<4; i++)
    {
    for(int j=0; j<6; j++)
    {
        cout << v[i][j] << " ";
    }
    cout << endl;
    }
fitness();
selection();
cout << "Decimals : " << endl;
for(int i=0; i<4; i++)
    {
        cout << d[i] << " ";
    }
cout << endl;
//for(int i=0; i<4; i++)
//    {
//        cout << f[i] << " ";
//    }
//    cout << endl;
//for(int i=0; i<2; i++)
//    {
//        cout << b[i] << " ";
//    }
//    cout << endl;
crossover();
//    for(int i=0; i<4; i++)
//    {
//    for(int j=0; j<6; j++)
//    {
//        cout << v[i][j] << " ";
//    }
//    cout << endl;
//    }
mutaion();
//for(int i=0; i<4; i++)
//    {
//    for(int j=0; j<6; j++)
//    {
//        cout << v[i][j] << " ";
//    }
//    cout << endl;
//    }
for(int i=0; i<4; i++)
    {
    for(int j=0; j<6; j++)
    {
        cout << v[i][j] << " ";
    }
    cout << endl;
    }

fitness();
cout << "Fitness Values : " << endl;
for(int i=0; i<4; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
for(int i=0; i<4; i++)
    {
        cout << f[i] << " ";
    }
    cout << endl;
sort(f, f+4);
if(p<f[3]) p=f[3];
cout << "Optimal Value : " << p << endl;
cout << endl;
}
}
