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

// ����ģʽƥ�䣬���������ַ�����ԭ����ģʽ����ƥ��ɹ�����λ�ã�ƥ�䲻�ɹ�����0�� 
int GetIndex(SString f,SString s){
	int i = 1;
	int j = 1;
	while(i <= f.length && j <= s.length){
		cout<<"i ="<<i<<" "<<"j ="<<j<<endl;
		if(f.chars[i-1] == s.chars[j-1]){
			i++;
			j++;		
		}else{
			i = i-j +2;
			j = 1;
		}
		
	}
	//ֻ��j����s.length��ʱ��ƥ��ɹ�
	if(j > s.length){
		cout<<"s.length = "<<s.length;
		return i-s.length; //ִ�е�����ʱ��i�����1������ֻ��Ҫ��ȥ�ִ��ĳ��ȼ��� 
	} else{
		return 0; 
	} 
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














