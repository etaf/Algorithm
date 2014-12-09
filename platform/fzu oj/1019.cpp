#include<iostream>
using namespace std;
int main()
{
	char a[10][10];
	int n,i,j,mi,mj,ci,cj,sum,cdir,mdir,mx,my,cx,cy;
	cin>>n;
	while(n--)
	{
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='c')
				{
					ci=i;cj=j;
				}
				if(a[i][j]=='m')
				{
					mi=i;mj=j;
				}
		
			}
		sum=0;
		cdir=mdir=0;
		mx=cx=-1;my=cy=0;
		do
		{
			switch(cdir)
			{
			case 0:
				if((a[ci+cx][cj+cy]=='.'|| a[ci+cx][cj+cy]=='m') && ci>0)
				{
					a[ci][cj]='.';
					a[ci+cx][cj+cy]='c';
					ci+=cx;cj+=cy;

				}
				else
				{
						cx=0;cy=1;cdir=1;

				}	
				break;
			case 1:
					if((a[ci+cx][cj+cy]=='.'|| a[ci+cx][cj+cy]=='m')&& cj<9)
				{
					a[ci][cj]='.';
					a[ci+cx][cj+cy]='c';
					ci+=cx;cj+=cy;

				}
						else
						{
						cx=1;cy=0;cdir=2;
						}
						break;
			case 2:
				if((a[ci+cx][cj+cy]=='.'|| a[ci+cx][cj+cy]=='m') && ci<9)
				{
					a[ci][cj]='.';
					a[ci+cx][cj+cy]='c';
					ci+=cx;cj+=cy;

				}
				else
				{
						cx=0;cy=-1;cdir=3;

				}
				break;
			case 3:
				if((a[ci+cx][cj+cy]=='.'|| a[ci+cx][cj+cy]=='m') && cj>0)
				{
					a[ci][cj]='.';
					a[ci+cx][cj+cy]='c';
					ci+=cx;cj+=cy;

				}
				else
				{
						cx=-1;cy=0;cdir=0;

				}
				break;

			}
			switch(mdir)
			{
				case 0:
				if((a[mi+mx][mj+my]=='.'||a[mi+mx][mj+my]=='c') && mi>0)
				{
					a[mi][mj]='.';
    					a[mi+mx][mj+my]='m';
					mi+=mx;mj+=my;

				}
				else
				{
						mx=0;my=1;mdir=1;

				}	
				break;
			case 1:
				
				if((a[mi+mx][mj+my]=='.'||a[mi+mx][mj+my]=='c') && mj<9)
				{
					a[mi][mj]='.';
					a[mi+mx][mj+my]='m';
					mi+=mx;mj+=my;

				}
				else
				{
						mx=1;my=0;mdir=2;

				}	
				break;
			case 2:
				
				if((a[mi+mx][mj+my]=='.'||a[mi+mx][mj+my]=='c') && mi<9)
				{
					a[mi][mj]='.';
					a[mi+mx][mj+my]='m';
					mi+=mx;mj+=my;

				}
				else
				{
						mx=0;my=-1;mdir=3;

				}	
				break;
			case 3:
				
				if((a[mi+mx][mj+my]=='.'||a[mi+mx][mj+my]=='c') && mj>0)
				{
					a[mi][mj]='.';
					a[mi+mx][mj+my]='m';
					mi+=mx;mj+=my;

				}
				else
				{
						mx=-1;my=0;mdir=0;

				}	
				break;

			}


			sum++;
			if(sum>500){sum=0;break;}
		}while(mi!=ci || mj!=cj);
		cout<<sum<<endl;

	}
	
	return 0;
}