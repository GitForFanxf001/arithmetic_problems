# include <iostream>
using namespace std;
//˼·������numCircle��Ȧ��ÿ��ȦȦ��k�񣬼����������������������ɢ�ȣ������Сֵ����Ӧ�������Ϊ��������
# define CIR 4
# define K 4 

//ĳ�����������״̬���ṹ��
struct State{
	int count; //��̬��Ȧ�� 
	int degree;
	int *number = new int[CIR];//
}; 

//�������������ֵ�ĺ���
int Max(int array[CIR]){
	int max = -1;
	for(int i=0;i<CIR;i++){
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
} 

//�������������ֵ�ĺ���
int Min(int array[CIR]){
	int min = 10;
	for(int i=0;i<CIR;i++){
		if(array[i]<min){
			min = array[i];
		}
	}
	return min;
} 

//���������������ɢ�ȵĺ��� 
int GetDegree(int lock[K][CIR]){
	//�ֱ���ÿһ�е����ֵ��Сֵ��������������
	int degree = -1;
	for(int i=0;i<K;i++){
		int temp = Max(lock[i])-Min(lock[i]);
		cout<<"degree"<<i<<"="<<temp<<endl;
		if(temp>degree){
			degree = temp;
		}
	}
	cout<<"�ܵĶ�C="<<degree<<endl;
	return degree;
}
//��ӡ��ά������ 
void PrintLock(int lock[K][CIR]){
	for(int i=0;i<K;i++){
		for(int j=0;j<CIR;j++){
			cout<<lock[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//����ת����Ȧ����������ά����ĵ�i����Ȧת��һ�Σ���0��ʼ
void Turn(int lock[K][CIR],int index){
	//�Ƚ���i���ó���������һ�������У���һ��Ȼ��Żض�ά������
	cout<<"ת��ǰ��"<<endl;
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
	cout<<"ת����"<<endl;
	PrintLock(lock);
}
 

int main(){
	int lock[K][CIR] = {{5,1,8,3},{2,1,9,5},{6,3,0,1},{4,0,7,8}};
	cout<<"degree = "<<GetDegree(lock)<<endl;
	cout<<"**************************��ʼ״̬***********************************"<<endl; 
	PrintLock(lock);
	cout<<"��ʼ״̬���Ķ�Ϊ��"<<GetDegree(lock)<<endl; 
	//������ÿ�����������ɢ�ȣ����յõ���ɢ����С�߼�Ϊ����״̬
	//�ݹ�? 
	int *degrees = NULL;	 
	for(int i=1;i<CIR;i++){
		cout<<"--------------start-------------------"<<i<<endl;
		//תһ�Σ���һ����ɢ�Ȳ���¼ת������������һ�����飬�±꼴ת��������ֵΪ��Ӧ��ɢ�ȵ�ֵ,��Ϊÿ��ת���Ĵ���Ϊ4�Σ�ת������Ķ�Ӧ�лָ�ԭװ��
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
		//�����С��ɢ�ȵ��±�
	    int minIndex = 0; 
	    int min = degrees[0];
	    cout<<"K="<<K<<endl;
	    for(int j=0;j<K;j++){
            if(degrees[i]<=min){
            	minIndex = j;
	    	}
    	}
	//�����в���i+1��
		cout<<"minIndex = "<<minIndex<<endl; 
    	for(int w=0;w<=minIndex;w++){
    		cout<<"�ڶ��ֲ�����"<<endl; 
    		Turn(lock,i);
    	} 
    	cout<<"--------------end-------------------"<<i<<endl;
	}
	
	delete [] degrees;
	cout<<"���������Ķ�Ϊ��"<<GetDegree(lock)<<endl; 
	cout<<"**************************����״̬***********************************"<<endl;
	PrintLock(lock); 
	return 0;
}















