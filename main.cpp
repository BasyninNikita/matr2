#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool proverka(float mat[][]){
   string str;
   getline(cin, str);
   istringstream stream(str);
   unsigned int i;
   unsigned int f;
   stream >> i;
   stream.ignore( numeric_limits<streamsize>::max(), ',' );
   stream >> f;
    
    float **matrix = new float *[rows];
    for( int i = 0; i < rows; ++i ) {
        matrix[ i ] = new float[ columns ];
        for( int j = 0; j < columns; ++j ) {
            matrix[i][j] = 0.0;
        }
    }
}
int main()
{
    int n;int k;
    cin>>n;cin>>k;
    int matr[n][k];
    char op;
    if (proverka(matr)){
        cin>>op;
        if (op=='+')
        {
            int n1,k1;
            cin>>n1;cin>>k1;
            int matr1[n1][k1];
            if (n==n1) && (k==k1)
            {
                for (int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        matr[i][j]=matr[i][j]+matr1[i][j];
                    }
                }
            }
            else cout>>"it's impossible">>endl;
        }
        else if (op=='-')
        {
            int n1,k1;
            cin>>n1;cin>>k1;
            int matr1[n1][k1];
            if (n==n1) && (k==k1)
            {
                for (int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        matr[i][j]=matr[i][j]+matr1[i][j];
                    }
                }
            }
            else cout>>"it's impossible">>endl;
        }
        else if (op=='*')
        {
            if(n==k1)
            {
                int resmatr[n][n];int s;
                for(int i=0; i<n; i++) 
                {
                    for(int j=0; j<n; j++) 
                    {
                        s = 0;
                        for(k=0; k<n; j++) 
                        {
                            s= s+a[i][k]*b[k][j];
                        }
                        c[i][j] = s;
                    }
                }
            }
            else cout>>"it's impossible">>endl;
        }
        else if(op=='T')
        {
            int matr2[k][n];
            for(int i=0; i<n; i++) 
                {
                    for(int j=0; j<k; j++) 
                    {
                        matr2[i][j]=matr[j][i];
                        matr2[j][i]=matr[i][j];
                    }
                }
        }
                        
            
            
        
}
}
