# include<iostream>
using namespace std;
/*
8 （1，1） 
7 9 （2，1） （2，2） 
6 13 5  （3，1）（3，2）（3，3） 
思路：
1. 先定义一个函数访问1，1左边的数，看谁大，谁大就返回给主函数并且和1，1相加
2. 在定义函数访问7和9左右的数字，看谁大，求出来并且相加 
*/
# define M 3
# define N 3

// 求两个数较大者
int Max(int num1,int num2){
	if((num1-num2)>0){
		return num1;
	}else{
		return num2;	
	} 
} 

//入参：1，1的坐标，和值，返回和较大者
void Step1(int x,int y,int array[M][N]){
	array[x][y] = Max(array[x+1][y],array[x+1][y+1])+array[x][y];
} 

// 打印数组 
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
