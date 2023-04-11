# include <iostream>
using namespace std;
//思路：设有numCircle个圈，每个圈圈有k格，计算所有所有情况下锁的松散度，求出最小值，对应的情况即为解锁密码
# define CIR 4
# define K 4 

//某种情况下锁的状态，结构体
struct State{
	int count; //动态拨圈数 
	int degree;
	int *number = new int[CIR];//
}; 

//定义求数组最大值的函数
int Max(int array[CIR]){
	int max = -1;
	for(int i=0;i<CIR;i++){
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
} 

//定义求数组最大值的函数
int Min(int array[CIR]){
	int min = 10;
	for(int i=0;i<CIR;i++){
		if(array[i]<min){
			min = array[i];
		}
	}
	return min;
} 

//定义计算密码锁松散度的函数 
int GetDegree(int lock[K][CIR]){
	//分别求每一行的最大值最小值相减，留下最大者
	int degree = -1;
	for(int i=0;i<K;i++){
		int temp = Max(lock[i])-Min(lock[i]);
		cout<<"degree"<<i<<"="<<temp<<endl;
		if(temp>degree){
			degree = temp;
		}
	}
	cout<<"总的度C="<<degree<<endl;
	return degree;
}
//打印二维数组锁 
void PrintLock(int lock[K][CIR]){
	for(int i=0;i<K;i++){
		for(int j=0;j<CIR;j++){
			cout<<lock[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//定义转动拨圈操作，将二维数组的第i个拨圈转动一次，从0开始
void Turn(int lock[K][CIR],int index){
	//先将第i列拿出来，放在一个数组中，拨一下然后放回二维数组中
	cout<<"转动前："<<endl;
	PrintLock(lock); 
	int *array = new int[K];
	for(int i=0;i<K;i++){
		for(int j=0;j<CIR;j++){
			if(index == j){
				array[i] = lock[i][j];
			}
		}
	}
	
	int temp = 0 ;
	temp = array[0];
	for(int i=0;i<CIR-1;i++){
		array[i] = array[i+1];
	}
	array[CIR-1] = temp;
	
	for(int i=0;i<K;i++){
		for(int j=0;j<CIR;j++){
			if(index == j){
				lock[i][j] = array[i];
			}
		}
	}
	cout<<"转动后："<<endl;
	PrintLock(lock);
}
 

int main(){
	int lock[K][CIR] = {{5,1,8,3},{2,1,9,5},{6,3,0,1},{4,0,7,8}};
	cout<<"degree = "<<GetDegree(lock)<<endl;
	cout<<"**************************初始状态***********************************"<<endl; 
	PrintLock(lock);
	cout<<"初始状态锁的度为："<<GetDegree(lock)<<endl; 
	//对锁的每种情况计算松散度，最终得到松散度最小者即为开锁状态
	//递归? 
	int *degrees = NULL;	 
	for(int i=1;i<CIR;i++){
		cout<<"--------------start-------------------"<<i<<endl;
		//转一次，求一下松散度并记录转动次数，定义一个数组，下标即转动次数，值为对应松散度的值,因为每次转动的次数为4次，转完后锁的对应列恢复原装。
		degrees = new int[K];
		for(int j=0;j<K;j++){
			Turn(lock,i);
			degrees[j] = GetDegree(lock);
		} 
		cout<<"dgrees:"<<endl;
		for(int w=0;w<K;w++){
			cout<<degrees[w]<<" ";
		}
		cout<<endl;
		cout<<"--------------midium-------------------"<<i<<endl;
		//求出最小松散度的下标
	    int minIndex = 0; 
	    int min = degrees[0];
	    cout<<"K="<<K<<endl;
	    for(int j=0;j<K;j++){
            if(degrees[i]<=min){
            	minIndex = j;
	    	}
    	}
	//将此列拨动i+1次
		cout<<"minIndex = "<<minIndex<<endl; 
    	for(int w=0;w<=minIndex;w++){
    		cout<<"第二轮拨动："<<endl; 
    		Turn(lock,i);
    	} 
    	cout<<"--------------end-------------------"<<i<<endl;
	}
	
	delete [] degrees;
	cout<<"调整后锁的度为："<<GetDegree(lock)<<endl; 
	cout<<"**************************最终状态***********************************"<<endl;
	PrintLock(lock); 
	return 0;
}















