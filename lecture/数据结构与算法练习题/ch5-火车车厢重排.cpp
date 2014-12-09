/**************************************
*	  				                  *
*		    火车车厢重排			  *
*									  *
*									  *				
**************************************/


/*


#include<iostream>
#include<xcept.h>
#include"LinkedStack.h"
#include<time.h>
using namespace std;
//------------------------------------
bool RailRoad(int p[],int n,int k)
{
	int NowOut=1;
	int minH=n+1;
	int minS=k+1;
	LinkedStack<int> *s;
	s=new LinkedStack<int>[k+1];
	for(int i=0;i<n;i++)
	{
		if(p[i]==NowOut)
		{
			cout<<"Move car"<<p[i]<<" from input to output."<<endl;
			NowOut++;
			while(minH==NowOut)
			{
				int x;
				s[minS].Delete(x);
				cout<<"Move car"<<x<<" from holding track"<<minS << "to output."<<endl;
				
				//重新寻找minH和minS

				minH=n+2;
				for(int j=1;j<=k;j++)
				{
					if(!s[j].IsEmpty() && s[j].Top()<minH)
					{
						minH=s[j].Top();
						minS=j;
					}
				}
				NowOut++;

			}
		}
		else// 将该节车厢送至缓冲轨
		{
			int BestTop=n+1,BestTrack=0,y;
			for(int j=1;j<=k;j++)
			{
				if(!s[j].IsEmpty())
				{
					y=s[j].Top();
					if(p[i]<y && y<BestTop)
					{
						BestTop=y;
						BestTrack=j;
						
					}
				}
				else
					if(BestTrack==0)
					{
						BestTrack=j;
					
					}
											
			}
			if(BestTrack==0)
				return false;
			s[BestTrack].Add(p[i]);
			cout<<"Move car"<<p[i]<<" from input to holding track"<<BestTrack<<endl;
			if(p[i]<minH)
			{minH=p[i];minS=BestTrack;}

		}
		
	}
	return true;

}
//-------------------------------------
int main()
{
	int n,k;
	cout<<"******************************\n\n火车车厢重排问题\n\n*******************************\n";
	cout<<"now please enter the size of the train."<<endl;
	cin>>n;
	cout<<"now please enter the number of the holding tracks."<<endl;
	cin>>k;
	int *p=new int[n+1];
	
	cout<<"now please enter the train from top to end."<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	
	if(RailRoad(p,n,k))
		cout<<"The train can be resorted."<<endl;
	else
		cout<<"Error:There isn't enough holding track!"<<endl;

	return 0;
}
//------------------------------------------
//------------------------------------------


*/