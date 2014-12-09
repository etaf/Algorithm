//  使用递归函数生成子集
#include<iostream>
using namespace std;
int n;
bool *x=new bool[n];
char *a=new char[n];
void Subsets(int i)

{// Output all subsets of x[1:n].

 // Only x[i:n] to be changed.

   if (i == n-1) {// x[n] can be 0 or 1

                // output subset without element n

                x[n-1] = 0;
				cout<<"{ ";

                for (int j = 0; j < n; j++)

				{ 
					if(x[j])cout << a[j] << " ";
					
				}
					cout <<"}"<< endl;
		
                

                // output subset with element n

                x[n-1] = 1;
					cout<<"{ ";
               for ( j = 0; j < n; j++)

				{ 
					if(x[j])cout << a[j] << " ";
					
				}
					cout <<"}"<< endl;

                return;

                }

                

    // leave element i out

    x[i] = 0;

    // generate all subsets with i out

    Subsets(i+1);

                

    // put element i into subset

    x[i] = 1;

    // generate all subsets with i included

    Subsets(i+1);

}



int main()
{
	while(cin>>n)
	{
	
		
		for(int i=0;i<n;i++)
			cin>>a[i];
		Subsets(0);
		
	}
	

	return 0;
}