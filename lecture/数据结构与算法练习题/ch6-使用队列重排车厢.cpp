
/*

#include<iostream>
using namespace std;
bool RailRoad(int p[],int n,int k )
{
	int *last=new int[k+1];
	int *track=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		track[i]=0;
	}
	for(int i=0;i<=k;i++)
		last[i]=0;
	int NowOut=1;
	for(int i=0;i<n;i++)
	{
		if(p[i]==NowOut)
		{
			cout<<"Move car "<<p[i]<<" from input to output.\n";
			NowOut++;
			while(NowOut<=n && track[NowOut])
			{
				cout<<"Move car "<<NowOut<<"from holding track "<<track[NowOut]<<" to output."<<endl;
				if(NowOut==last[track[NowOut]])
					last[track[NowOut]]=0;
				NowOut++;
			}

			
		}
		else
		{
			int BestTrack=0,BestLast=0;

			for(int j=1;j<k;j++)
			{
				if(last[j])
				{
					if(p[i]>last[j] && last[j]>BestLast )
					{
						BestLast=last[j];
						BestTrack=j;
					}
				}
				else
					if(!BestTrack)
						BestTrack=j;
			}
			if(!BestTrack)
				return false;
			track[p[i]]=BestTrack;
			last[BestTrack]=p[i];
			cout<<"Move car "<<p[i]<<" form input to holding track "<<BestTrack<<endl;

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

*/