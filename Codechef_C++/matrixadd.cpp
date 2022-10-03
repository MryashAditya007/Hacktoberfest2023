#include<iostream>
using namespace std;
class Matrix
{
    private:
        int a[3][3];
    public:
        void read()
        {
            int i,j;
            cout<<"\n enter elements of matrix ";
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
              {
               cin>>a[i][j];
              }

            }
        }
        void print()
        {
             int i,j;
            for(i=0;i<3;i++)
            {
                cout<<"\n";
                for(j=0;j<3;j++)
              {
               cout<<a[i][j]<<"\t";
              }

            }

        }

        friend Matrix add( Matrix , Matrix );


};

int main()
{
    Matrix m1,m2,m3;
    m1.read();
    m2.read();
    m3=add(m1,m2);
    cout<<"\n m1 is ";
    m1.print();
    cout<<"\n m2 is ";
    m2.print();
    cout<<"\n addition is ";
    m3.print();

    return 0;


}

 Matrix add(Matrix x,Matrix y)
        {
         Matrix t;
         int i,j;
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
              {
               t.a[i][j]=x.a[i][j] + y.a[i][j];
              }

            }
            return t;

        }
