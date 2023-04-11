# include <iostream>
# include <math.h>
using namespace std;
//ʥ������������̣�ʵ����һ������ͼ�����·�����⣬˼·:����Ŀ����Ϊһ����ȫͼ�������ÿ������֮��ľ��룬Ȼ�������·����
//�Ͻ�˹������ͼ�����·������˼�룺 �ӵ�һ���㿪ʼ�����ϵ����ţ����ŵĹ�����ÿ�ζ�����̵�·���������������ඥ������·��һ���Ǵӵ�ǰ�Ѿ�ȷ�������·����ĩ�˳�����ֱ�����ŵ�ȫ�����㡣 

# define N 9 //���嶥��ĸ��� 

//����������֮���ŷ����þ���
double GetDistance(double x1,double y1, double x2,double y2){
	double xx = x1-x2;
	double yy = y1-y2;
	double plus = xx*xx + yy*yy;
	cout<<"get distance :"<<"""("<<x1<<","<<y1<<")"<<"("<<x2<<","<<y2<<")"<<"="<<sqrt(plus);
	return sqrt(plus);
} 

//�����ǰͼ
void PrintTree(double a[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
} 

//����point�ṹ�壺 
struct Point{
	double x,y;
}; 

//������еĵ㣺 
void PrintPoints(Point array[N],int n){
	for(int i=0;i<n;i++){
		cout<<"��"<<i<<"�����㣺"<<"("<<array[i].x<<","<<array[i].y<<")"<<"  " ;
	}
	cout<<endl;
}

//����һ������������㵽����Ϊ���ʶ���֮��ľ��룬���붥������ͳ�ʼ��㣬������飬·�����飬ͼ���󣬷����������±�
int Update(int index,Point points[N],bool mark[N],double tree[N][N]){
	//��ǰ��㵽δ���ʵ����е�ľ��룬��ס·������ߵ��±�
	double minDis = 100;
	int minIndex = -1;
	for(int i=0;i<N;i++){
		if(mark[i] == false){//ֻҪû�б����ʾ�����룬���Ҽ�¼��Сֵ����Сֵ��Ӧ���±� 
			double dis = GetDistance(points[i].x,points[i].y,points[index].x,points[index].y); 
			cout<<"��"<<i<<"��"<<"��"<<index<<"֮��ľ��� dis = "<<dis<<endl;
			if(dis<minDis){
				minDis = dis;
				minIndex = i;
			}
		}
	} 
	cout<<"mindis = "<<minDis<<endl;
	cout<<"minindex = "<<minIndex<<endl;
	//�޸Ķ�ά����
	tree[index][minIndex] = minDis; 
	mark[minIndex] = true; 
	return minIndex;
} 

//���������߳��ȵĺ���
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
	cout<<"______��ʼ״̬______"<<endl;
	double tree[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tree[i][j] = 100;
		}
	}
	PrintTree(tree);
	//����Point�����ʾ��ͬ�ĵ�
	Point points[N] ;
	for(int i=0;i<N;i++){//��ʼ�������� 
		cout<<"�������______"<<i<<"_______�Ŷ�������ֵ��"<<endl;
		cout<<"X"<<i<<"=";
		cin>>points[i].x;
		cout<<"Y"<<i<<"=";
		cin>>points[i].y;
		cout<<endl;
	}
	PrintPoints(points,N);
	//����������ȷ��һ�����Ƿ��Ѿ������� 
	bool mark[N];
	for(int i=0;i<N;i++){//�Ƚ��������ȫ�����Ϊû�з��� 
		mark[i] = false;
	}
	//����·�����飬��¼�������ţ��Ƚ��������ȫ����ʼ��Ϊ-1
	int path[N];
	for(int i=0;i<N;i++){
		path[i] = -1;
	} 
	//�ҳ�Y��������Ҷ��������С�ĵ㣬��������Ϊ��㣬 
	//ֻ��Ҫ��N-1�μ����ҵ����еĶ��㣬�����������ֵ��С�Ķ������Ÿ�ֵ��min
	int minIndex = -1;
	double minValue = -1;
	for(int i=0;i<N;i++){
		if(points[i].y > minValue){
			minIndex = i;
			minValue = points[i].y;
		}
	} 
	if(minIndex == -1){
		minIndex = 0;//���û�иı�˵����0�Ŷ��������������Ķ��� 
	}
	//�޸���Ӧ����
	mark[minIndex] = true;
	path[0] = minIndex+1;
	int startPoint = path[0];//�Ƚ������Ϊ 
	//�����·���Ĳ���Ҫִ��N-1��,ÿ�μ��㵱ǰ��㵽���������̾��룬���޸���Ӧ������ 
	for(int i=0;i<N-1;i++){//˼·ȷ����ǰ��㣬��������δ���ʵĶ���ľ��벢�����Сֵ�������ά�����У�������Ӧ���飬��������Ϊ�µ���㡣 
		//ÿ�β���ǰ�������������
		cout<<"��"<<i+1<<"��Ѱ��ǰ��"<<endl; 
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
		
		cout<<"��"<<i+1<<"��Ѱ�Һ�"<<endl;
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
	cout<<"�����ܳ��ȣ�"<<LengthOfWire(tree)<<endl;
	 
	return 0; 
} 






















