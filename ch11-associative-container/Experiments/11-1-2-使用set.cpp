#include <iostream>

#include <map>
#include <string>
#include <set>

using namespace std;

// 使用 set  
int main(int argc,char** argv)
{
	// 统计每个单词出现的次数，忽略常见单词:"the","and","or"
	map<string,size_t> word_count;
	set<string> exclude = {"The","But","And","Or","An","A",
							"the","but","and","or","an","a"};
	
	string word;
	while(cin >> word){
		// 只统计不在 exclude 中的单词
		if (exclude.find(word) == exclude.end())
		    // 获取并递增word的计数器 
			++word_count[word]; 
	} 
	
		
	for(const auto& w:word_count)
		cout << w.first << " occurs "<< w.second
			 << ((w.second > 1) ? "times":"time") <<endl; 
			 
	return 0;
}
