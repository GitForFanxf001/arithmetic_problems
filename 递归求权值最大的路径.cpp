# include<iostream>
using namespace std;
/*
8 ��1��1�� 
7 9 ��2��1�� ��2��2�� 
6 13 5  ��3��1����3��2����3��3�� 
˼·��
1. �ȶ���һ����������1��1��ߵ�������˭��˭��ͷ��ظ����������Һ�1��1���
2. �ڶ��庯������7��9���ҵ����֣���˭�������������� 
*/
# define M 3
# define N 3

// ���������ϴ���
int Max(int num1,int num2){
	if((num1-num2)>0){
		return num1;
	}else{
		return num2;	
	} 
} 

//��Σ�1��1�����꣬��ֵ�����غͽϴ���
void Step1(int x,int y,int array[M][N]){
	array[x][y] = Max(array[x+1][y],array[x+1][y+1])+array[x][y];
} 

// ��ӡ���� 
void PrintNumber(int array[M][N]){
	for(int i=0;i<M;i++){
		for(int j=0;j<=i;j++){
			cout<<"input a["<<i<<"]"<<"["<<j<<"]"<<"="<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int array[M][N];
	for(int i=0;i<M;i++){
		for(int j=0;j<=i;j++){
			cout<<"a["<<i<<"]"<<"["<<j<<"]"<<endl;
			cin>>array[i][j];
		}
	}
	PrintNumber(array);
	Step1(1,0,array);
	Step1(1,1,array);
	Step1(0,0,array);
	PrintNumber(array);
} 
