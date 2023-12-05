#include<stdio.h>
#include<string.h>

int main()
{
	int n,k,a[51][51],b[51][51];
	scanf("%d%d",&k,&n);
	int i=0,j=0,p=0,flag=0;
	for(i=1;i<=k;i++)
	scanf("%s",&a[i][0]);
	for(i=1;i<=n;i++)
	scanf("%s",&b[i][0]);
	for(i=1;i<=n;i++)
	{
		p=0;
		flag=0;
		//for(p=0;b[i][p]!='\0';p++);
		p=strlen(b[i]);
		//printf("%d\n",p);
		if(p>=47)
		{
			flag=1;
		}
		else
		{
			for(j=1;j<=k;j++)
			{
				if(strstr(&b[i][0],&a[j][0])!=NULL)
				{
					flag=1;
					break;
				}	
			}
		}
if(flag == 1)
printf("Good\n");
else
printf("Bad\n");
}
return 0;
}