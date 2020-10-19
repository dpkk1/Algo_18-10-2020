#include<bits/stdc++.h>
using namespace std;

// THE REMAMINDER WHEN (x^n mod M)


//ITERATIVE MODULAR EXPONENTIATION


long int Mod(long int x, long int n, long int m){
	long int res=1;
	x = x%m ;
	if(x==0)
	return 0;	
    while (n > 0)  
    {  
        // If y is odd, multiply x with result  
        if (n & 1)  
            res = (res*x) % m;  
  
        // n must be even now  
        n = n>>1; // n = n/2  
        x = (x*x) % m;  
    }  
    return res;  
}  
 
//RECURSIVE MODULAR EXPONENTIATION

long int Mod(long int x, long int n, long int m){
	 // Base cases  
    if (x == 0)  
        return 0;  
    if (n == 0)  
        return 1;  
  
    // If n is even  
    long int y;  
    if (n % 2 == 0) {  
        y = Mod(x, n / 2, m);  
        y = (y * y) % m;  
    }  
  
    // If n is odd  
    else {  
        y = x % m;  
        y = (y * Mod(x, n - 1, m) % m) % m;  
    }  
  
    return (int)((y + m) % m);
}

int main(){
	long int x,n,m;
	cin>>x>>n>>m;
	cout<<Mod(x,n,m)<<"\n";
	return 0;
}






