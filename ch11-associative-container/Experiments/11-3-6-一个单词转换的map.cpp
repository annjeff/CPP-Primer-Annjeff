#include <iostream>

#include <map>
#include <string>

using namepsace std;

/**
  * 一个单词转换的 map
  * input:第一个文件保存的是一些规则，用来转换第二个文件中的文本
  *    	  每条规则由两部分组成：一个可能出现在输入文件中的单词 和 一个用来替换它的短语 
  * function:给定一个string，将它转换为另一个string 
  */
  
// 函数 word_transform 管理整个过程
void word_transform(ifstream &map_file, ifstream &input)
{
	// 保存转换规则 
	auto trans_map = buildMap(map_file);
	// 保存输入中的每一行 
	string text;	
	// 读取一行输入 
	while (getline(input,text)) {
		// 读取每个单词
		istringstream stream(text);
		string word;
		// 控制是否打印空格
		bool firstword = true;
		while (stream >> word){
			if (firstword)
				firstword = false;
			else
				// 在单词间打印一个空格 
				cout << " ";
			// transform 返回它的第一个参数或其转换之后的形式
			cout << transform(word,trans_map); 
		}	
		// 完成一行的转换
		cout << endl; 
	}
} 
int main(int argc,char** argv)
{
	
	return 0;
}
