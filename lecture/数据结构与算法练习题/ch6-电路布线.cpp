/********************************
*                               *
*        电路布线问题           * 
*   DataStructure：LinkedQueue  *
*                               *
********************************/


#include"LinkedQueue.h"
#include<fstream>
class Position
{
public:
	int row;
	int col;
};

Position start,finish;

int m;
int ** grid;
Position* path;
int PathLen;

bool FindPath()
{
	if(start.row==finish.row && start.col==finish.col)
	{
		PathLen=0;
		return true;
	}
//-------------围上边-------------
	for(int i=0;i<=m+1;i++)
	{
		grid[i][m+1]=grid[i][0]=1;
		grid[m+1][i]=grid[0][i]=1;

	}
	Position offset[4];
	offset[0].row=0;offset[0].col=1;
	offset[1].row=1;offset[1].col=0;
	offset[2].row=0;offset[2].col=-1;
	offset[3].row=-1;offset[3].col=0;
	Position now=start;
	grid[now.row][now.col]=2;
	LinkedQueue<Position> Q;
	Position nbr;
	while(1)
	{
		for(int i=0;i<4;i++)
		{
			nbr.row=now.row+offset[i].row;
			nbr.col=now.col+offset[i].col;
			if(grid[nbr.row][nbr.col]==0)
			{
				grid[nbr.row][nbr.col]=grid[now.row][now.col]+1;
				if(nbr.row==finish.row && nbr.col==finish.col)
					break;
				Q.Add(nbr);

			}

		}
		if(nbr.row==finish.row && nbr.col==finish.col)
			break;
		if(Q.IsEmpty())
			return false;
		Q.Delete(now);
	}
	
	PathLen=grid[finish.row][finish.col]-2;
	path=new Position[PathLen];
	now=finish;
	for(int i=PathLen-1;i>=0;i--)
	{
		path[i]=now;
		for(int j=0;j<4;j++)
		{
			nbr.row=now.row+offset[j].row;
			nbr.col=now.col+offset[j].col;
			if(grid[nbr.row][nbr.col]==i+2)break;

		}
		now=nbr;
	}
	return true;
	

}
int main()
{
	ifstream in("grid.txt");
	cout<<"The district is a square, please Enter the row:\n";
	in>>m;
	cout<<m<<endl;//
	cout<<"Enter the district:\n";
	grid=new int*[m+2];
	for(int i=0;i<=m+1;i++)
		grid[i]=new int[m+2];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			in>>grid[i][j];
	cout<<"please input the start and the finish:\n";
	in>>start.row>>start.col>>finish.row>>finish.col;
	cout<<start.row<<start.col<<finish.row<<finish.col<<endl;
	if(FindPath())
	{
		cout<<"ok\n";
		cout<<PathLen<<endl;
		for(int i=0;i<PathLen;i++)
			grid[path[i].row][path[i].col]=-1;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<grid[i][j]<<" ";
			cout<<endl;
									
		}
	}
	else
	{
		cout<<"No Path !"<<endl;
	}



	return 0;
}