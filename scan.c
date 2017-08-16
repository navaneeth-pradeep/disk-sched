#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void swap(int* a,int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void sort_procs(int p[],int n){
	int i,j;
	for(i=0;i<n-1;++i){
		for(j=0;j<n-i-1;++j)
			if(p[j] > p[j+1]){
				swap(&p[j],&p[j+1]);			
			}	
	}
}


int main(void){
	int *q,n,i,dir,pos,high=0,low=INT_MAX;
	scanf("%d",&n);
	scanf("%d",&pos);
	scanf("%d",&dir);
	q = (int*) malloc(sizeof(int)*n);
    
	for(i=0;i<n;++i){ 
		scanf("%d",q+i);
		if(high < q[i]){
			high = q[i];
		}
		if(low > q[i]){
			low = q[i];
		}
	}


	printf("seek time: %d\n",
		 pos >= low && pos <= high?
		 					dir?2*high - pos -low:pos + high - 2*low
		 					:
		 					pos<low?high - pos : pos - low 
	 );



	return 0;
}