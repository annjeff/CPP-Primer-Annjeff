#include <iostream>
#include <fstream>
#include <sstream>

#include <map>
#include <string>

using namespace std;

/**
  * 一个单词转换的 map
  * input:第一个文件保存的是一些规则，用来转换第二个文件中的文本
  *    	  每条规则由两部分组成：一个可能出现在输入文件中的单词 和 一个用来替换它的短语 
  * function:给定一个string，将它转换为另一个string 
  */

// 函数 buildMap 读入给定文件，建立起转换映射
map<string,string> buildMap(ifstream &map_file)
{
	// 保存转换规则 
	map<string, string> trans_map;
	// 要转换的单词
	string key;
	// 要替换的内容
	string value;
	// 读取第一个单词存入 key 中，行中剩余内容存入 value
	while (map_file >> key && getline(map_file, value))
		// 检查是否有转换规则 
		if (value.size() > 1)
			// 跳过前导空格 
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for "+ key);
	return trans_map;	 
}  

// 函数 transform 进行实际的转换工作
const string& transform(const string &s, const map<string,string> &m)
{
	// 实际的转换工作
	auto map_it = m.find(s);
	// 如果单词在转换规则 map 中
	if (map_it != m.cend() )
		// 使用替换短语
		return map_it->second;
	else
		// 返回原 string 
		return s; 
} 
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
	ifstream regulation("regulation.txt");
	ifstream text("text.txt");
	// Tips: 因为 word_transform 函数的参数为 ifstream 对象的引用， 不可以传入临时对象 
	
	word_transform(regulation,text);
	return 0;
}
