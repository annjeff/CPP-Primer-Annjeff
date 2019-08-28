#include <iostream>

#include <string>
#include <map>
using namespace std;

// Tips:输入单词后，Enter输入下一个单词，结束Ctrl+Z 

int main(int argc,char** argv)
{
	// 统计每个单词在输入中出现的次数
	// string 到 size_t 的空map 
	map<string,size_t> word_count;
	string word;
	while (cin >> word)
		// 提取word的计数器，并+1 
		++word_count[word]; 
	
	for(const auto& w:word_count)
		cout << w.first << " occurs "<< w.second
			 << ((w.second > 1) ? "times":"time") <<endl; 
	
	return 0;	
} 
