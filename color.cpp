# include <iostream>
using namespace std;
# define M 6
# define N 5

//���������� 
void PrintPanal(int array[M][N]){
	cout<<"��Ϸ��壺" <<endl; 
	for (int i = 0; i<M ;i++){
		for(int j=0;j<N;j++){
			cout<<array[i][j]<<" "; 
		}
		cout<<endl;
	}
} 

//����һ�����ı���ɫ�ĺ��� ����������opt(��ʾ����)��x����ʾ��ţ���Ci����ʾ��ɫ����������ɫ���ά���� 
void Play(int array[M][N],int opt,int index,int colori){
	//���opt = 0 �� �ͽ���index�е���ɫ��Ϊcolori���������1���͸ı��Ӧ�е���ɫ��
	if (opt==0){
		// �޸ĵ�index�� 
		for(int i=0;i<N;i++){
			array[index][i] = colori;
		}
	} else if(opt==1){
		//�޸ĵ�index�� 
		for(int i=0;i<M;i++){
			array[i][index] = colori;
		}
	} else{
		cout<<" args error please input 0 or 1 " ; 
	} 
}

//Ϳɫ��Ϸ��M��N�еĶ�ά����һ��ʼȫ����ʼ��Ϊ0��Ȼ���� M+N��ˢ�ӣ� 
int main(){
	int panal[M][N] = {{0,0,0},{0,0,0},{0,0,0}};
	PrintPanal(panal);
	//�ȶ��������߼�������1��������������0��������
	char flag = 'y';
	while(1){
		cout<<" ����y������Ϸ������n������Ϸ�� " ;
		cin>>flag;
		if (flag == 'n'){
			break;
		}else if(flag=='y'){
			//��������߼�
			cout<<"�����߼���"<<endl; 
			//����һά���飬1-9��ʾ9����ɫ 
			int color[10] = {1,2,3,4,5,6,7,8,9} ;
			cout<<"��ֱ���������ѡ��0ѡ���У�1ѡ���У���������Ŵ�0��ʼ����С��M,��С��N�������޸���ɫ1-9��Ӧ������ɫ"<<endl;
			int opt,index,colors;
			cout<<"���У�"<<endl; 
			cin>>opt;
			cout<<"��ţ�"<<endl;
			cin>>index;
			cout<<"��ɫ��"<<endl; 
			cin>>colors;
			Play(panal,opt,index,colors);
			PrintPanal(panal);
		}else{
			cout<<"������y����n"<<endl;
		}
	} 
	return 0;
}









