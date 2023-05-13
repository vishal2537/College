
#include<stdio.h>

int main(){

    int i,n;

    printf("Enter the size of array : ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements of the array : ");
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    int maximum = arr[0];

    for(i=0;i<n;i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    printf("The maximum value is : %d", maximum);

    int second_max = arr[0];
    for(i=0;i<n;i++) {
        if(arr[i] > second_max && arr[i]!=maximum) {
            second_max = arr[i];
        }
    }
    printf("\nThe second maximum value is : %d", second_max);
}
