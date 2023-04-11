# include <iostream>
# include <math.h>
using namespace std;


//定义函数，计算a的b次幂
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
	for(int i=1;i<=n;i++){//最外层循环遍历1-n，判断是否能写成指数形式    i=1
		if(i==16)cout<<"-------------------------------------"<<endl;
		flag == false;
		//cout<<"第一层循环第"<<i<<"次执行"<<endl; 
		for(int j=1;j<=i;j++){//第二层循环代表底数 
		 	//cout<<"第二层循环第"<<j<<"次执行"<<endl;
		 	for(int p=k;p<=n;p++){//第三层循环代表指数 
		 		//cout<<"第三层循环第"<<p<<"次执行"<<endl; 
		 		//cout<<j<<"的"<<p<<"次幂="<<Power(j,p)<<endl;	
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
	//思路：定义一个函数，入参是正整数n，指数下界K，输出合法的组合以及组合的个数
	int n,k,count;
	char start = 'n';
	while(1){
		cout<<"输入'y'开始，任意健结束  :" ;
		cin>>start;
		cout<<endl;
		if(start == 'y') {
			cout<<"请输入n:";
			cin>>n;
			cout<<endl;
			cout<<"请输入k:";
			cin>>k;
			cout<<endl;
			count = GetNumbers(n,k);
			cout<<"count = "<<count<<endl;
		}else break;
		
	}
	
	
} 














