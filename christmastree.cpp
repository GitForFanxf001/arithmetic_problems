# include <iostream>
# include <math.h>
using namespace std;
//圣诞树：电线最短，实际是一个无向图求最短路径问题，思路:将题目抽象为一张完全图，计算出每两个点之间的距离，然后求最短路径。
//迪杰斯特拉求图的最短路径核心思想： 从第一个点开始，不断的扩张，扩张的过程中每次都走最短的路径，这样，到其余顶点的最短路径一定是从当前已经确定的最短路径的末端出发，直到扩张到全部顶点。 

# define N 9 //定义顶点的个数 

//求两个顶点之间的欧几里得距离
double GetDistance(double x1,double y1, double x2,double y2){
	double xx = x1-x2;
	double yy = y1-y2;
	double plus = xx*xx + yy*yy;
	cout<<"get distance :"<<"""("<<x1<<","<<y1<<")"<<"("<<x2<<","<<y2<<")"<<"="<<sqrt(plus);
	return sqrt(plus);
} 

//输出当前图
void PrintTree(double a[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
} 

//定义point结构体： 
struct Point{
	double x,y;
}; 

//输出所有的点： 
void PrintPoints(Point array[N],int n){
	for(int i=0;i<n;i++){
		cout<<"第"<<i<<"个顶点："<<"("<<array[i].x<<","<<array[i].y<<")"<<"  " ;
	}
	cout<<endl;
}

//定义一个函数，求起点到其余为访问顶点之间的距离，输入顶点数组和初始起点，标记数组，路径数组，图矩阵，返回新起点的下标
int Update(int index,Point points[N],bool mark[N],double tree[N][N]){
	//求当前起点到未访问的所有点的距离，记住路径最短者的下标
	double minDis = 100;
	int minIndex = -1;
	for(int i=0;i<N;i++){
		if(mark[i] == false){//只要没有被访问就求距离，并且记录最小值和最小值对应的下标 
			double dis = GetDistance(points[i].x,points[i].y,points[index].x,points[index].y); 
			cout<<"点"<<i<<"到"<<"点"<<index<<"之间的距离 dis = "<<dis<<endl;
			if(dis<minDis){
				minDis = dis;
				minIndex = i;
			}
		}
	} 
	cout<<"mindis = "<<minDis<<endl;
	cout<<"minindex = "<<minIndex<<endl;
	//修改二维数组
	tree[index][minIndex] = minDis; 
	mark[minIndex] = true; 
	return minIndex;
} 

//定义计算电线长度的函数
double LengthOfWire(double tree[N][N]){
	double length = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tree[i][j] < 100.0){
				length += tree[i][j];
			}
		}
	}
	return length;
} 
int main(){
	cout<<"______初始状态______"<<endl;
	double tree[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tree[i][j] = 100;
		}
	}
	PrintTree(tree);
	//定义Point数组表示不同的点
	Point points[N] ;
	for(int i=0;i<N;i++){//初始化各个点 
		cout<<"请输入第______"<<i<<"_______号顶点坐标值："<<endl;
		cout<<"X"<<i<<"=";
		cin>>points[i].x;
		cout<<"Y"<<i<<"=";
		cin>>points[i].y;
		cout<<endl;
	}
	PrintPoints(points,N);
	//定义标记数组确定一个点是否已经被访问 
	bool mark[N];
	for(int i=0;i<N;i++){//先将标记数组全部标记为没有访问 
		mark[i] = false;
	}
	//定义路径数组，记录顶点的序号，先将顶点序号全部初始话为-1
	int path[N];
	for(int i=0;i<N;i++){
		path[i] = -1;
	} 
	//找出Y坐标最大且顶点序号最小的点，将其设置为起点， 
	//只需要找N-1次即可找到所有的顶点，遍历顶点表，将值最小的顶点的序号赋值给min
	int minIndex = -1;
	double minValue = -1;
	for(int i=0;i<N;i++){
		if(points[i].y > minValue){
			minIndex = i;
			minValue = points[i].y;
		}
	} 
	if(minIndex == -1){
		minIndex = 0;//如果没有改变说明第0号顶点是满足条件的顶点 
	}
	//修改相应数组
	mark[minIndex] = true;
	path[0] = minIndex+1;
	int startPoint = path[0];//先将起点设为 
	//找最短路径的操作要执行N-1次,每次计算当前起点到其他点的最短距离，并修改相应的数组 
	for(int i=0;i<N-1;i++){//思路确定当前起点，计算其他未访问的顶点的距离并求出最小值，放入二维数组中，更新相应数组，并将其设为新的起点。 
		//每次操作前先输出各个数组
		cout<<"第"<<i+1<<"次寻找前："<<endl; 
		//PrintTree(tree) ;
		cout<<"mark:"<<endl;
		for(int i=0;i<N;i++){//
			cout<<mark[i]<<" ";
		}
		cout<<endl;
		cout<<"path:"<<endl;
		for(int i=0;i<N;i++){
			cout<<path[i]<<" ";
		}
		cout<<endl;
		int initIndex = Update(minIndex,points,mark,tree);
		path[i+1] = initIndex+1;
		minIndex = initIndex;
		
		cout<<"第"<<i+1<<"次寻找后："<<endl;
		//PrintTree(tree) ;
		cout<<"mark:"<<endl;
		for(int i=0;i<N;i++){//
			cout<<mark[i]<<" ";
		}
		cout<<endl;
		cout<<"path:"<<endl;
		for(int i=0;i<N;i++){
			cout<<path[i]<<" ";
		}
		cout<<endl; 
	}
	cout<<"电线总长度："<<LengthOfWire(tree)<<endl;
	 
	return 0; 
} 






















