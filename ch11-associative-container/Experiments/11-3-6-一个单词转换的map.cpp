#include <iostream>

#include <map>
#include <string>

using namepsace std;

/**
  * һ������ת���� map
  * input:��һ���ļ��������һЩ��������ת���ڶ����ļ��е��ı�
  *    	  ÿ����������������ɣ�һ�����ܳ����������ļ��еĵ��� �� һ�������滻���Ķ��� 
  * function:����һ��string������ת��Ϊ��һ��string 
  */
  
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
	
	return 0;
}
