/******************************
*                             *
*         火车车厢重排        *
*   DataStruct:LinkedQueue    *
*                             *
*                             *
******************************/

#include"LinkedQueue.h"

//---------------------------------
bool RailRoad(int *p,int n,int k)
{
	int minH=n+2;
	int minQ=k+1;
	int NowOut=1;
	LinkedQueue<int> *queue=new LinkedQueue<int>[k];
	for(int i=0;i<n;i++)
	{
		if(p[i]==NowOut)
		{
			NowOut++;
			cout<<"Move car "<<p[i]<<"from input to output\n";
			while(minH==NowOut)
			{
				NowOut++;
				queue[minQ].Delete(minH);
				cout<<"Move car "<<minH<<"from holding track "<<minQ<<" to output "<<endl;
				//找出新的minH;
				minH=n+2;
				for(int j=1;j<k;j++)
				{
					if(!queue[j].IsEmpty() && queue[j].First()<minH)
					{
						minH=queue[j].First();
						minQ=j;
					}
				}
			}

		}
		
		else//-------------放入缓冲轨--------
		{
			int BestTrack=0;
			int BestLast=0;
			for(int j=1;j<k;j++)
			{
				if(!queue[j].IsEmpty())
				{
					if(p[i]>queue[j].Last() && queue[j].Last()>BestLast)
					{
						BestLast=queue[j].Last();
						BestTrack=j;
					}
				}
				else
					if(!BestTrack)
						BestTrack=j;
				
			
			}
			if(!BestTrack)
				return false;
			queue[BestTrack].Add(p[i]);
			cout<<"Move car "<<p[i]<<"from input "<<"to holding track "<<BestTrack<<endl;
			if(p[i]<minH)
			{
				minH=p[i];
				minQ=BestTrack;
			}
			
		}
	}
	return true;


}
int main()
{
	int n,k;
	cout<<"Please Enter the size of the train:\n";
	cin>>n;
	cout<<"Please Enter the number of the holding track:\n";
	cin>>k;
	int *p=new int[n];
	cout<<"Please Enter the train from front to rear:\n";
	for(int i=0;i<n;i++)
		cin>>p[i];
	if(RailRoad(p,n,k))
		cout<<"The train can be resorted.\n";
	else
		cout<<"The train can't be resorted because the holding track is not enough.\n";

}
 
