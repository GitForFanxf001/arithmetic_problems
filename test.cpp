# include <iostream>
# include <math.h>
using namespace std;


//���庯��������a��b����
int Power(int a,int b){
	int product = 1;
	for(int i=1;i<=b;i++){
		product *= a;
	}
	return product;
} 

int GetNumbers(int n,int k){//n=15,k=1
	int count = 0;
	int lenBase = 0;
	int lenPow = 0;
	int lenRes = 0;
	bool flag = false;
	int *arrayBase = new int[lenBase];
	int *arrayPow = new int[lenPow];
	int *arrayResult = new int[lenRes];
	for(int i=1;i<=n;i++){//�����ѭ������1-n���ж��Ƿ���д��ָ����ʽ    i=1
		if(i==16)cout<<"-------------------------------------"<<endl;
		flag == false;
		//cout<<"��һ��ѭ����"<<i<<"��ִ��"<<endl; 
		for(int j=1;j<=i;j++){//�ڶ���ѭ��������� 
		 	//cout<<"�ڶ���ѭ����"<<j<<"��ִ��"<<endl;
		 	for(int p=k;p<=n;p++){//������ѭ������ָ�� 
		 		//cout<<"������ѭ����"<<p<<"��ִ��"<<endl; 
		 		//cout<<j<<"��"<<p<<"����="<<Power(j,p)<<endl;	
				if(Power(j,p)==i){
					count++;                                                     
					lenBase++;            
					lenPow++;
					lenRes++;
					flag = true;
					arrayBase[lenBase-1] = j;
					arrayPow[lenPow-1] = p;
					arrayResult[lenRes-1] = Power(j,p);
					j = i+1;
					break;
				}
				//if(flag == true) break;
			} 
		} 
	} 
	cout<<"arrayBase:"; 
	for(int i=0;i<lenBase;i++){
		cout<<arrayBase[i]<<" ";
	}
	cout<<endl;
	cout<<"arrayPow:";
	for(int i=0;i<lenPow;i++){
		cout<<arrayPow[i]<<" ";
	}
	cout<<endl;
		cout<<"arrayResult:";
	for(int i=0;i<lenPow;i++){
		cout<<arrayResult[i]<<" ";
	}
	cout<<endl;
	delete [] arrayBase;
	delete [] arrayPow;
	delete [] arrayResult;
	return count;
} 

int main(){
	//˼·������һ�������������������n��ָ���½�K������Ϸ�������Լ���ϵĸ���
	int n,k,count;
	char start = 'n';
	while(1){
		cout<<"����'y'��ʼ�����⽡����  :" ;
		cin>>start;
		cout<<endl;
		if(start == 'y') {
			cout<<"������n:";
			cin>>n;
			cout<<endl;
			cout<<"������k:";
			cin>>k;
			cout<<endl;
			count = GetNumbers(n,k);
			cout<<"count = "<<count<<endl;
		}else break;
		
	}
	
	
} 














