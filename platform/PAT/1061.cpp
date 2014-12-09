#include<stdio.h>
char a1[64],b1[64],a2[64],b2[64];

void print_day(char c)
{
	if(c == 'A')printf("MON ");
	else if(c == 'B')printf("TUE ");
	else if(c == 'C')printf("WED ");
	else if(c == 'D')printf("THU ");
	else if(c == 'E')printf("FRI ");
	else if(c == 'F')printf("SAT ");
	else if(c == 'G')printf("SUN ");
}

int get_day()
{
	int p;
	for(int i=0;a1[i];++i)
	{
		if(a1[i] == b1[i] && 'A'<=a1[i] && a1[i] <= 'G')
		{
			
			print_day(a1[i]);
			return i;
		}
			
	}
}
void print_hh(char c)
{
	int hh=0;
	if('0'<=c && c <='9')
	{
		hh = c-'0';
	}
	else
	{
		hh = c - 'A'+10;
	}
	printf("%02d:",hh);
}

void get_hh(int p)
{
	for(int i=p+1;a1[i];++i)
	{
		if(a1[i] == b1[i] && ( ('A'<=a1[i] && a1[i]<='N')|| ('0'<=a1[i] && a1[i] <='9') ) )
		{
			print_hh(a1[i]);
			return ;
		}
	}
}


void get_mm()
{
	for(int i=0;a2[i];++i)
	{
		if(a2[i] == b2[i] && ( ('a'<=a2[i] && a2[i]<='z') || ('A'<=a2[i] && a2[i]<='Z') ) )
		{
			printf("%02d\n",i);
			return;
		}
	}
}
int main()
{

	scanf(" %s %s %s %s",a1,b1,a2,b2);
	int p=get_day();
	get_hh(p);
	get_mm();

	return 0;
}