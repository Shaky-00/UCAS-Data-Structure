#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)

{
    int va[1000];
    int i = 0;
    int j = 0;
    int len, target;

    while(cin >> va[i]){
    	i++;
    }

    len = i;
    i--;
    target = va[i];
    for(j=i-1; j>=0; j--)
    {
    	if(va[j] > target)
    		continue;
    	else{
    		while(i>j+1)
    		{
    			va[i] = va[i-1];
    			i--;
			}
			va[i] = target;
			break;
		}
	}

    cout << va[0];
    
    for(i=1; i<len; i++){
    	cout << ' ';
    	cout << va[i]; 
	}
    	
	return 0;
}

