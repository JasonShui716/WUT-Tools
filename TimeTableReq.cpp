/*************************************************************************
    > File Name: TimeTableReq.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "TimeTableReq.h"
#include <iostream>
using namespace std;

void TimeTableReq::getInfo()
{
	
}

void TimeTableReq::makeForm()
{
	
}

RETcode TimeTableReq::enterPage(string URL) {
	RETcode ret;
	this->init();
	this->appendHeader("User-Agent: Chrome");
	this->appendHeader("Content-Type: application/x-www-form-urlencoded");
	this->setCookie("cookies.txt");
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
	this->saveFile(fileName);
	ret = this->get("http://202.114.90.180/Course/grkbList.do");
	this->deinit();
	return ret;
}
