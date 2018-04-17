#include "ScoreTableReq.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
using namespace std;

static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

void ScoreTableReq::getSnkey(string fileName)
{
	regex r("(?=snkey=).+(?=\" t)");
	smatch sm;
	string str;
	ifstream in(fileName);
	while (getline(in, str)) {
		cout << str << endl;
		if (regex_search(str, sm, r)) {
			cout << sm.str() << endl;
			snkey = sm.str();
		}
	}
	vector<string> v;
	SplitString(snkey, v, "=");
	snkey =  v[1];
	cout << snkey << endl;
	cin.get();
}

void ScoreTableReq::makeForm()
{
	postField = "pageNum=1&numPerPage=100&snkey=" + snkey;
	cout << postField << endl;
	cin.get();
}

RETcode ScoreTableReq::enterPage(string URL, string fileName) {
	RETcode ret;
	this->init();
	this->appendHeader("User-Agent: Chrome");
	this->appendHeader("Content-Type: application/x-www-form-urlencoded");
	this->setCookie("cookies.txt");
	if (fileName != "")
		this->saveFile(fileName);
	ret = this->get(URL.c_str());
	this->deinit();
	return ret;
}

RETcode ScoreTableReq::getTable(string URL, string fileName)
{
	RETcode ret;
	this->init();
	this->appendHeader("User-Agent: Chrome");
	this->appendHeader("Content-Type: application/x-www-form-urlencoded");
	this->setCookie("cookies.txt");
	if (fileName != "")
		this->saveFile(fileName);
	ret = this->post(URL.c_str());
	return ret;
}
