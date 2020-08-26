#include<stdio.h>
#define MAX 20
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void quicksort(int [10],int,int);
void main()
{
int a[10],i,n,x;

printf(“\n ————————-“);
printf(“Enter the no of element:”);
scanf(“%d”,&n);

printf(“enter the elements:”);
for(i=0;i<n;i++)
scanf(“%d”,&a[i]);

x=fork();

if(x==0)
{
printf(“\nchild process = %d”,getpid()); 

quicksort(a,0,n-1); 
printf(“\nAfter quick sorting elements are: “);

for(i=0;i<n;i++)
printf(” %d”,a[i]);
}
else 
{
printf(“\nparent process=%d \n”,getpid());
partition(a,0,n-1); 
printf(“\nAfter merge sorting elements are: “);
for(i=0;i<n;i++)
printf(“%d “,a[i]);
}
}

void partition(int arr[],int low,int high)
{

int mid;
if(low<high)
{
mid=(low+high)/2;
partition(arr,low,mid);
partition(arr,mid+1,high);
mergeSort(arr,low,mid,high);
}
}

void mergeSort(int arr[],int low,int mid,int high)
{
int i,m,k,l,temp[MAX];
l=low;
i=low;
m=mid+1;
while((l<=mid)&&(m<=high))
{
if(arr[l]<=arr[m])
{
temp[i]=arr[l];
l++;
}
else
{
temp[i]=arr[m];
m++;
}
i++;
}
if(l>mid)
{
for(k=m;k<=high;k++)
{
temp[i]=arr[k];
i++;
}
}
else
{
for(k=l;k<=mid;k++)
{
temp[i]=arr[k];
i++;
}
}

for(k=low;k<=high;k++)
{
arr[k]=temp[k];
}
}

void quicksort(int x[10],int first,int last)
{
int pivot,j,temp,i;
if(first<last)
{
pivot=first;
i=first;
j=last;
while(i<j)
{
while(x[i]<=x[pivot]&&i<last)
i++;
while(x[j]>x[pivot])
j–;
if(i<j)
{
temp=x[i];
x[i]=x[j];
x[j]=temp;
}
}
temp=x[pivot];
x[pivot]=x[j];
x[j]=temp;
quicksort(x,first,j-1);
quicksort(x,j+1,last);
}
}
