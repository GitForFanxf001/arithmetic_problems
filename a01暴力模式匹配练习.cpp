# include<iostream>
using namespace std;

# define MAXLEN 255
 
typedef struct{
	char chars[MAXLEN];
	int length; 
}SString;

void InputString(SString* str){
	cout<<"���볤�ȣ�"<<endl;
	int len = 0;
	cin>>len;
	(*str).length = len;
	cout<<"���������ַ���"<<endl;
	for(int i=0;i<len;i++){
		cin>>(*str).chars[i];
	} 
	for(int i=0;i<len;i++){
		cout<<(*str).chars[i]<<" ";
	} 
	cout<<endl;
}
void PrintStr(SString str){
	cout<<"�ַ������ȣ�"<<str.length<<endl;
	for(int i=0;i<str.length;i++){
		cout<<str.chars[i]<<" ";
	}
	cout<<endl;
}

// todo:=========================================ʵ�ֱ���ģʽƥ���㷨�����븸�����ִ�������ִ���ĸ���е�λ�� =====================================
int GetIndex(SString f,SString s){
	 //˼·���ȶ�����������i��j����ʾ��һ��λ�ã�Ȼ���ÿ��i����ƥ�䣬ƥ��ʧ�ܾͻ��˵���ǰi����һ��λ�ü�������ƥ�䣬����Ϊ����
	 
} 
int main(){
	SString father;
	InputString(&father);
	PrintStr(father); 
	SString son;
	InputString(&son);
	PrintStr(son);
	int index = GetIndex(father,son);
	cout<<"�ִ��ڸ����ĵ�"<<index<<"��λ��"<<endl; 
}
