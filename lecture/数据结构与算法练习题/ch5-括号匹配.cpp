/*********************
*                    *
*      ¿®∫≈∆•≈‰      *
*       Stack        *
*					 *	
*********************/


/*


#include<iostream>
#include"LinkedStack.h"
#include<xcept.h>
#include<string>
#include<fstream>
using namespace std;
//----------------------------
ifstream fin("pair.txt");
ofstream fout("PrintPair.txt");
//------------------------------
void PrintPairs(char *a)
{
	LinkedStack<int> s;
	int x;
	int length=strlen(a);
	for(int i=0;i<length;i++)
	{
		if(a[i]=='(')
			s.Add(i);
		else
			if(a[i]==')')
			try{
				s.Delete(x);
				fout<<x+1<<" "<<i+1<<endl;
				
				cout<<x+1<<" "<<i+1<<endl;
			}catch(OutOfBounds)
			{
				fout<<"No match for the right parenthesis at "<<i+1<<" ."<<endl;
				cout<<"No match for the right parenthesis at "<<i+1<<" ."<<endl;
			}

	}
	while(!s.IsEmpty())
	{
		s.Delete(x);
		fout<<"No match for the left parenthesis at "<<x+1<<" ."<<endl;
		cout<<"No match for the left parenthesis at "<<x+1<<" ."<<endl;
	}

}
//------------------------------------------------------------------

int main()
{
	char a[100];
	while(fin.getline(a,100))
	{
		fout<<"The expression is : "<<endl<<a<<endl;
		cout<<"The expression is : "<<endl<<a<<endl;
		PrintPairs(a);
	
	}
	return 0;
}



*/
