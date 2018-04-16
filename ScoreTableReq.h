#pragma once
#include "TableReq.h"
using namespace std;

class ScoreTableReq : public TableReq {
private:
	string snkey;
public:
	ScoreTableReq() = default;
	~ScoreTableReq() = default;
	void getInfo(string fileName);
	void makeForm();
	RETcode enterPage(string URL, string fileName);
	RETcode getTable(string URL, string fileName);
};