#include<iostream>
using namespace std;
enum sign{plus,minus};
class Currency
{
private:
	long amount ;
public:
	Currency(sign s=plus,unsigned long d=0,unsigned int c=0);
	~Currency(){};
	bool Set(sign s,unsigned long d,unsigned int c);
	bool Set(double a);
	long Amount()
	{return amount;}
	sign Sign()const
	{
		if(amount<0)return minus;
		else return plus;
	}
	unsigned long Dollars()
	{
		if(amount<0)
			return -amount/100;
		return amount/100;
	}
	unsigned int Cents()
	{
		if(amount<0)
			return -(amount%100);
		return amount%100;
	}
	Currency operator+(const Currency &x)const;
	Currency& operator+=(const Currency &x);
	friend ostream& operator<<(ostream& out,const Currency& x);

};
Currency::Currency(sign s,unsigned long d,unsigned int c)
{
	if(c>99)
	{
		cerr<<"Cents should be < 100 !"<<endl;
		exit(1);
	}
	amount=d*100+c;
	if(s==minus)
		amount=-amount;
}
bool Currency::Set(sign s,unsigned long d,unsigned int c)
{
	if(c>99)
	{
		cerr<<"Cents should be < 100 !"<<endl;
		return false;
	}
	amount=d*100+c;
	if(s==minus)
		amount=-amount;
	return true;
}
bool Currency::Set(double a )
{
	sign sgn;
	if(a<0){sgn=minus;a=-a;}
	else sgn=plus;
	amount=(a+0.001)*100;
	if(sgn==minus)amount=-amount;
	return true;
}
Currency Currency::operator+(const Currency &x)const
{
	Currency y;
	y.amount=amount+x.amount;
	return y;
}
Currency& Currency::operator+=(const Currency &x)
{
	amount+=x.amount;
	return *this;
}
ostream& operator<<(ostream& out,const Currency& x)
{
	long a=x.amount;
	if(a<0)
	{out<<'-';a=-a;}
	out<<'$'<<a/100<<'.';
	int c=a%100;
	if(c<10)
		out<<'0';
	out<<c;
	return out;
}
int main()
{
	Currency  g,h(plus,3,50),i,j;
	g.Set(minus,2,25);
	i.Set(-6.45);
	cout<<i.Amount()<<endl;
	cout<<i.Dollars()<<endl;
	cout<<i.Cents()<<endl;
	i+=h;
	cout<<i;
	j=(i+=h);
	cout<<j<<endl;
	


	return 0;
}