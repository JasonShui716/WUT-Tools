#pragma once
#include "HttpReq.h"
using namespace std;

class TableReq : public HttpReq{
public:
	TableReq() = default;
	virtual void getInfo() = 0;
	virtual void makeForm() = 0;
	virtual void getTable() = 0;
};