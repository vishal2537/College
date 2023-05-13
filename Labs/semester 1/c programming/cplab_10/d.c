#include <stdio.h>

int main()
{
    int temp;
    int *ptr;
    int **pptr;
    temp = 3000;
    /*take the address pf temp */
    ptr = &temp;
    /*teke the address of ptr using address of operator & */
    pptr = &ptr;
    /*take the value using pptr */
    printf("value of temp =%d \n", temp);
    printf("value avilable at *ptr =%d \n", *ptr);

    printf("value availble at**pptr =%d \n", **pptr);

    return 0;
}