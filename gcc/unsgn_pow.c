unsigned long long unsgn_pow(unsigned int x,unsigned int y)
{
	unsigned long long res=1;
	if(y==0)
	{
		res = 1;
	}
	else if(y==1)
	{
		res=x;
	}
	else
	{
		res = x * unsgn_pow(x,y-1);
	}
	return res;
}

