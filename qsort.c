#define MAX 10
#include<stdio.h>
int partition(int A[], int l , int h){
	int pi=A[h];
	int j, i=l-1;
	for(j=l;j<h;j++){
		if(A[j]<pi){
			i++;
			int temp;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	int temp;
	temp=A[i+1];
	A[i+1]=A[h];
	A[h]=temp;
	return(i+1);
}
void Qsort(int A[], int l, int h){
	if(l<h){
		int pi=partition(A,l,h);
		Qsort(A,l,pi-1);
		Qsort(A,pi+1,h);
	}
}
void main(){
	int A[MAX];
	int i, n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	Qsort(A,0,n-1);
	for(i=0;i<n;i++){
		printf("%d\t",A[i]);
	}
}