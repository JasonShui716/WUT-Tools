#pragma once
#include "TableReq.h"
using namespace std;

class ScoreTableReq : public TableReq {
private:
	string snkey;
public:
	ScoreTableReq() = default;
	~ScoreTableReq() = default;
	void getSnkey(string fileName);
	void makeForm();
	void completeHTML(string fileName);
	RETcode enterPage(string URL, string fileName = "");
	RETcode getTable(string URL, string fileName = "");
};