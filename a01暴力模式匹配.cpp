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

// 暴力模式匹配，传入两个字符串，原串和模式串，匹配成功返回位置，匹配不成功返回0； 
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
	//只有j超过s.length的时候，匹配成功
	if(j > s.length){
		cout<<"s.length = "<<s.length;
		return i-s.length; //执行到最后的时候，i多加了1，所以只需要减去字串的长度即可 
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
	cout<<"字串在父串的第"<<index<<"个位置"<<endl; 
}














