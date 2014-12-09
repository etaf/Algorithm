template<typename T>
int SequentialSearch(T a[],const T& x,int n)
{
	int i;
	for(i=0;i<n&&a[i]!=x;i++);
	if(i==n)return -1;
	return i;
}