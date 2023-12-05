#include <stdio.h>

void tween(int x)
{
    switch(x)
{
    case 11:
    printf("elven ");
    break;
    case 12:
    printf("twelve ");
    break;
    case 13:
    printf("thirteen ");
    break;
    case 14:
    printf("fourteen ");
    break;
    case 15:
    printf("fifteen ");
    break;
    case 16:
    printf("sixteen ");
    break;
    case 17:
    printf("seventeen ");
    break;
    case 18:
    printf("eighteen ");
    break;
    case 19:
    printf("nineteen ");
}
	// fixes 3 digit numbers
	}
 	void fix(int a)
 	{
 	    switch(a/100)
 	 { case 1:
 	  printf("one hundred ");break;
 	  case 2:
 	  printf("two hundred ");break;
 	  case 3:
 	  printf("three hundred ");break;
 	  case 4:
 	  printf("four hundred ");break;
 	  case 5:
 	  printf("five hundred ");break;
 	  case 6:
 	  printf("six hundred ");break;
 	  case 7:
 	  printf("seven hundred ");break;
 	  case 8:
 	  printf("eight hundred ");break;
 	  case 9:
 	  printf("nine hundred");break;
 	  }
 	  switch((a%100)/10)
 	  {
 	      case 1:
 	    tween(a%100);
 	    return;
 	    case 2:
 	    printf("twenty "); break;
 	      case 3:
 	    printf("thirty "); break;
 	      case 4:
 	    printf("forty "); break;
 	      case 5:
 	    printf("fifty "); break;
 	    case 6:
 	    printf("sixty "); break;
 	      case 7:
 	    printf("seventy "); break;
 	      case 8:
 	    printf("eighty "); break;
 	      case 9:
 	    printf("ninety "); break;
 	   }
 	   switch(a%10)
 	 {
      case 1:
 	  printf("one ");break;
 	  case 2:
 	  printf("two ");break;
 	  case 3:
 	  printf("three ");break;
 	  case 4:
 	  printf("four ");break;
 	  case 5:
 	  printf("five ");break;
 	  case 6:
 	  printf("six ");break;
 	  case 7:
 	  printf("seven ");break;
 	  case 8:
 	  printf("eight ");break;
 	  case 9:
 	  printf("nine ");break;
 	  }
 		}
 		//to generate the required word
 	void generate(int x,int y)
 	{
 		if(x==0)//number has come to 0
 		return;
 	else
      generate(x/1000,y+3); //removes last 3 digits and increases the count by 3
        int z=x%1000; // z takes 3 digits
 		fix(z); //fixing the digits
 		if(y>9) //y stores number of digits and accordingly adds suffix
 		printf("billion ");
 		else if(y>6)
 		printf("million ");
 		else if(y>3)
 		printf("thousand ");

 		}
int main()
{
    int n;
    printf("ENTER THE NUMBER: ");
    scanf("%d",&n);
	generate(n,1);
	return 0;
}
