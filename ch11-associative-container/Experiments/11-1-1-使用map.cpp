#include <iostream>

#include <string>
#include <map>
using namespace std;

// Tips:���뵥�ʺ�Enter������һ�����ʣ�����Ctrl+Z 

int main(int argc,char** argv)
{
	// ͳ��ÿ�������������г��ֵĴ���
	// string �� size_t �Ŀ�map 
	map<string,size_t> word_count;
	string word;
	while (cin >> word)
		// ��ȡword�ļ���������+1 
		++word_count[word]; 
	
	for(const auto& w:word_count)
		cout << w.first << " occurs "<< w.second
			 << ((w.second > 1) ? "times":"time") <<endl; 
	
	return 0;	
} 
