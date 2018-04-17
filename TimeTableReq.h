/*************************************************************************
    > File Name: TimeTableReq.h
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/21 18:14:57
 ************************************************************************/
#include "TableReq.h"
using namespace std;
class TimeTableReq : public TableReq{
private:

public:
	TimeTableReq() = default;
	~TimeTableReq() = default;
	void makeForm();
	RETcode enterPage(string URL, string fileName = "");
	RETcode getTable(string URL, string fileName = "");
};