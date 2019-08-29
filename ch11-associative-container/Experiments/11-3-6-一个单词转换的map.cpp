#include <iostream>
#include <fstream>
#include <sstream>

#include <map>
#include <string>

using namespace std;

/**
  * һ������ת���� map
  * input:��һ���ļ��������һЩ��������ת���ڶ����ļ��е��ı�
  *    	  ÿ����������������ɣ�һ�����ܳ����������ļ��еĵ��� �� һ�������滻���Ķ��� 
  * function:����һ��string������ת��Ϊ��һ��string 
  */

// ���� buildMap ��������ļ���������ת��ӳ��
map<string,string> buildMap(ifstream &map_file)
{
	// ����ת������ 
	map<string, string> trans_map;
	// Ҫת���ĵ���
	string key;
	// Ҫ�滻������
	string value;
	// ��ȡ��һ�����ʴ��� key �У�����ʣ�����ݴ��� value
	while (map_file >> key && getline(map_file, value))
		// ����Ƿ���ת������ 
		if (value.size() > 1)
			// ����ǰ���ո� 
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for "+ key);
	return trans_map;	 
}  

// ���� transform ����ʵ�ʵ�ת������
const string& transform(const string &s, const map<string,string> &m)
{
	// ʵ�ʵ�ת������
	auto map_it = m.find(s);
	// ���������ת������ map ��
	if (map_it != m.cend() )
		// ʹ���滻����
		return map_it->second;
	else
		// ����ԭ string 
		return s; 
} 
// ���� word_transform ������������
void word_transform(ifstream &map_file, ifstream &input)
{
	// ����ת������ 
	auto trans_map = buildMap(map_file);
	// ���������е�ÿһ�� 
	string text;	
	// ��ȡһ������ 
	while (getline(input,text)) {
		// ��ȡÿ������
		istringstream stream(text);
		string word;
		// �����Ƿ��ӡ�ո�
		bool firstword = true;
		while (stream >> word){
			if (firstword)
				firstword = false;
			else
				// �ڵ��ʼ��ӡһ���ո� 
				cout << " ";
			// transform �������ĵ�һ����������ת��֮�����ʽ
			cout << transform(word,trans_map); 
		}	
		// ���һ�е�ת��
		cout << endl; 
	}
} 
int main(int argc,char** argv)
{
	ifstream regulation("regulation.txt");
	ifstream text("text.txt");
	// Tips: ��Ϊ word_transform �����Ĳ���Ϊ ifstream ��������ã� �����Դ�����ʱ���� 
	
	word_transform(regulation,text);
	return 0;
}
