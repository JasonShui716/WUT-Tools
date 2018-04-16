#pragma once
#include "HttpReq.h"
using namespace std;

class TableReq : public HttpReq{
public:
	TableReq() = default;
	~TableReq() = default;
	virtual void getInfo() = 0;
	virtual void makeForm() = 0;
	virtual RETcode enterPage(string URL) = 0;
	virtual RETcode getTable(string URL, string fileName) = 0;
};