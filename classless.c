#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int binaryNum[32],t=0,first[32],last[32];

int combine(int *arr,int l){
	int i=0,val=0,temp=0;
	temp=l;
	for(i=0;i<l;i++){
	val=val+(arr[i]*pow(10,temp-1));
	temp--;
	}
	return val;
}

void decToBinary(int n)
{
    int temp[9],i=0,j;
    for(i=0;i<8;i++){
        temp[i] = n % 2;
        n = n / 2;
    }
    for (j = i-1; j >= 0; j--){
	
    	binaryNum[t]=temp[j];
    	t++;
    }
}

int binarytoDec(int*arr,int k,int l){
	int i=0,val=0,temp=7;
	for(i=k;i<l;i++){
		val=val+arr[i]*pow(2,temp);
		temp--;
	}
	return val;
}

void firstIp(int n){
	int i,j,k,l;
	for(i=0;i<n;i++){
		first[i]=1;
	}
	for(i=0;i<n;i++){
		first[i]=first[i]*binaryNum[i];
	}
	for(i=n;i<32;i++){
		first[i]=0;
	}
	printf("\nFIRST-IP:%d.%d.%d.%d\n",binarytoDec(first,k=0,l=8),binarytoDec(first,k=8,l=16),binarytoDec(first,k=16,l=24),binarytoDec(first,k=24,l=32));
}

void lastIp(int n){
	int i,j,k,l;
	for(i=0;i<n;i++){
		last[i]=1;
	}
	for(i=0;i<n;i++){
		last[i]=last[i]*binaryNum[i];
	}
	for(i=n;i<32;i++){
		last[i]=1;
	}
	printf("\nLAST-IP:%d.%d.%d.%d\n",binarytoDec(last,k=0,l=8),binarytoDec(last,k=8,l=16),binarytoDec(last,k=16,l=24),binarytoDec(last,k=24,l=32));
}


int main(){
	char ip[30];
	int ip1[4],l1=0,ip2[4],l2=0,ip3[4],l3=0,ip4[4],l4=0;
	int i,l,n,d,s;
	
	printf("Enter Classless I.P:");
	scanf("%s",ip);
	printf("\nIP:%s",ip);
	
	l=strlen(ip);
		
	
	for(i=l;i>1;i--){
		if(ip[i]=='/'){
			s=i;
			n=((((int)ip[i+1]-48)*10)+((int)ip[i+2]-48));
			break;
		}
	}
	printf("\n1's bits:%d\n",n);
	
	for(i=0;i<l;i++){
		if(ip[i]=='.'){
			d=i;
			break;
		}
		else{
		ip1[i]=(int)ip[i]-48;
		l1++;
		}
	}
	int p1=combine(ip1,l1);
	decToBinary(p1);
	
	for(i=d+1;i<s;i++){
		if(ip[i]=='.'){
			d=i;
			break;
		}
		else{
		ip2[i-(d+1)]=(int)ip[i]-48;
		l2++;
		}
	}
	int p2=combine(ip2,l2);
	decToBinary(p2);
	
	for(i=d+1;i<s;i++){
		if(ip[i]=='.'){
			d=i;
			break;
		}
		else{
		ip3[i-(d+1)]=(int)ip[i]-48;
		l3++;
		}
	}
	int p3=combine(ip3,l3);
	decToBinary(p3);
	
	for(i=d+1;i<s;i++){
		if(ip[i]=='.'){
			d=i;
			break;
		}
		else{
		ip4[i-(d+1)]=(int)ip[i]-48;
		l4++;
		}
	}
	int p4=combine(ip4,l4);
	decToBinary(p4);
	
	firstIp(n);
	lastIp(n);
	
	return 0;
}
