//#pragma once
#ifndef KMP_SUBSTRINGFIND
#define KMP_SUBSTRINGFIND

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class KMPSubStringFind
{
private:
	string input;
	string substring;
	int *next;
	vector<int> substring_location;
	int first_location;
public:
	KMPSubStringFind(string input = "", string substring = "") :
		input(input), substring(substring), next(nullptr), first_location(0) {}
	void init_input(string input_data);
	void init_substring(string substring_data);
	void init_all(string input_data, string substring_data);
	void init_next();
	void show_all_substring_location() const;
};

void KMPSubStringFind::init_input(string input_data)
{
	input = input_data;
	return;
}

void KMPSubStringFind::init_substring(string substring_data)
{
	substring = substring_data;
	return;
}

void KMPSubStringFind::init_all(string input_data, string substring_data)
{
	this->init_input(input_data);
	this->init_substring(substring_data);
	return;
}


void KMPSubStringFind::init_next()
{
	next = new int[substring.length() + 1];
	int i(0), k(-1);
	next[0] = -1;
	while (i < substring.length() + 1)
	{
		if (k == -1 || substring[i] == substring[k])
		{
			++i; ++k;
			next[i] = k;//next[i] = next[i-1]+1,这其实是一个递归过程
		}
		else
			k = next[k];
	}
	return;
}

void KMPSubStringFind::show_all_substring_location() const
{
	bool flag(false);
	for (int i(0), j(0); i <= input.length()/* && j < substring.length()*/;)
	{
		if (j == substring.length())//此时应该是已经匹配成功了
		{
			flag = true;
			cout << i - j << " ";
			j = next[j];
			//j = 
		}
		else if (j == -1 || substring[j] == input[i])
		{
			++i;
			++j;
		}
		else
		{
			if (i == input.length())
				break;
			else
			{
				j = next[j];
			}
		}
	}
	if (!flag)
		cout << "-1";
	cout << endl;
	return;
}



#endif