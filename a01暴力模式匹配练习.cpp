# include<iostream>
using namespace std;

# define MAXLEN 255
 
typedef struct{
	char chars[MAXLEN];
	int length; 
}SString;

void InputString(SString* str){
	cout<<"输入长度："<<endl;
	int len = 0;
	cin>>len;
	(*str).length = len;
	cout<<"依次输入字符："<<endl;
	for(int i=0;i<len;i++){
		cin>>(*str).chars[i];
	} 
	for(int i=0;i<len;i++){
		cout<<(*str).chars[i]<<" ";
	} 
	cout<<endl;
}
void PrintStr(SString str){
	cout<<"字符串长度："<<str.length<<endl;
	for(int i=0;i<str.length;i++){
		cout<<str.chars[i]<<" ";
	}
	cout<<endl;
}

// todo:=========================================实现暴力模式匹配算法，传入父串和字串，输出字串在母串中的位置 =====================================
int GetIndex(SString f,SString s){
	 //思路：先定义两个变量i，j，表示第一个位置，然后对每个i进行匹配，匹配失败就回退到当前i的下一个位置继续进行匹配，条件为长度
	 
} 
int main(){
	SString father;
	InputString(&father);
	PrintStr(father); 
	SString son;
	InputString(&son);
	PrintStr(son);
	int index = GetIndex(father,son);
	cout<<"字串在父串的第"<<index<<"个位置"<<endl; 
}
