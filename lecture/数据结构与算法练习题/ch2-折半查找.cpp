//从小到大的有序数组中折半查找
template<typename T>
int BinarySearch(T *a,const T& x,int n)
{
	int left=0,right=n-1,middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x<a[middle])
			right=middle-1;
		else
			left=middle+1;
	}
	return -1;
}