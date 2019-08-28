#include <iostream>

#include <map>
#include <string>
#include <set>

using namespace std;

// ʹ�� set  
int main(int argc,char** argv)
{
	// ͳ��ÿ�����ʳ��ֵĴ��������Գ�������:"the","and","or"
	map<string,size_t> word_count;
	set<string> exclude = {"The","But","And","Or","An","A",
							"the","but","and","or","an","a"};
	
	string word;
	while(cin >> word){
		// ֻͳ�Ʋ��� exclude �еĵ���
		if (exclude.find(word) == exclude.end())
		    // ��ȡ������word�ļ����� 
			++word_count[word]; 
	} 
	
		
	for(const auto& w:word_count)
		cout << w.first << " occurs "<< w.second
			 << ((w.second > 1) ? "times":"time") <<endl; 
			 
	return 0;
}
