#include <stdio.h>
#include <string.h>
int main() {
	int t;
	printf("Enter t : ");
	scanf("%d", &t);
	while(t-- > 0) {
	    char a[1005];
	    printf("Enter string : ");
	    
	    scanf("%s",&a);
	    int l;
	    l =strlen(a);
	    int i, j, sum=0, digit, count;
	    for(i =0; i<l; i= i+count) {
	        count = 0;
	        for(j = 0; j<l; j++) {
	            if(a[j] == a[i])
	            count++;
	            else break;
	        }
	        digit = (count/10) + 1;
	        sum = sum + count + digit;
	        
	    }
	    if(sum < l) {
	        printf("YES\n");
	    }
	    else printf("NO\n");
	}
	return 0;
}