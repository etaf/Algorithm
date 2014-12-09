#include"LinkedQueue.h"
#include<fstream>
using namespace std;
class Position
{
public:
	int row;
	int col;
};
int r,c;
int **pix;
//---------------------------
void Label()
{
	Position offset[4];
	offset[0].row=0;offset[0].col=1;
	offset[1].row=1;offset[1].col=0;
	offset[2].row=0;offset[2].col=-1;
	offset[3].row=-1;offset[3].col=0;
//--------------Î§±ß---------------
	for(int i=0;i<=r+1;i++)
		pix[i][0]=pix[i][c+1]=0;
	for(int i=0;i<=c+1;i++)
		pix[0][i]=pix[r+1][i]=0;
//----------------------------------
	int label=0;
	Position now,nbr;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			if(pix[i][j]==1)
			{
				++label;
				LinkedQueue<Position> Q;
				now.row=i;
				now.col=j;
				pix[i][j]+=label;
				while(1)
				{
					for(int k=0;k<4;k++)
					{
						nbr.row=now.row+offset[k].row;
						nbr.col=now.col+offset[k].col;
						if(pix[nbr.row][nbr.col]==1)
						{
							pix[nbr.row][nbr.col]+=label;
							Q.Add(nbr);
						}
					}
					if(Q.IsEmpty())
						break;
					Q.Delete(now);
				}

			}
		}

}

int main()
{
	
	cout<<"Please Enter the row and col:\n";
	ifstream fin("define.txt");
	fin>>r>>c;
	cout<<"Please Enter the pixel:\n";
	pix=new int*[r+2];
	for(int i=0;i<r+2;i++)
		pix[i]=new int[c+2];
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			fin>>pix[i][j];
	Label();
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
			cout<<pix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}