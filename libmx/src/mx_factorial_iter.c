int mx_factorial_iter(int n){
	if(n == 0)
		return 1;
	else if(n < 0 || n > 12)
		return 0;
	else if(n < 3 && n > 0)
		return n;
	else
		return n*mx_factorial_iter(n-1);
}
