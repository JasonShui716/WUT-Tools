/*************************************************************************
    > File Name: TimeTableReq.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "TimeTableReq.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void TimeTableReq::makeForm()
{
	
}

void TimeTableReq::completeHTML(string fileName){
	ifstream in(fileName, ios::in|ios::binary);
	stringstream ss;
	ss << "<html><body>";
    ss << in.rdbuf();
	in.close();
	string page(ss.str());
	cout << page;
	ofstream out(fileName, ios::out|ios::app);
	// out << ss.str();
	out << "</body></html>";
	out.close();
}

RETcode TimeTableReq::enterPage(string URL, string fileName) {
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

RETcode TimeTableReq::getTable(string URL, string fileName)
{
	RETcode ret;
	this->init();
	this->appendHeader("User-Agent: Chrome");
	this->appendHeader("Content-Type: application/x-www-form-urlencoded");
	this->setCookie("cookies.txt");
	if(fileName != "")
		this->saveFile(fileName);
    ret = this->get(URL.c_str());
	this->deinit();
	return ret;
}


