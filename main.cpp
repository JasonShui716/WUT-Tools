#include <iostream>
#include "HttpReq.h"
#include "LoginReq.h"
#include "TimeTableReq.h"
using namespace std;

int main(void) {
	HttpReq hr;
	LoginReq lr;
	TimeTableReq tr;
	RETcode ret;

	hr.globalInit();

	lr.getInfo();
	lr.makeForm();
	ret = lr.login("http://sso.jwc.whut.edu.cn/Certification//login.do");
	if (ret != 0)
		cerr << "Error in login(), info: " << findError(ret) << endl;
	
	ret = tr.enterPage("http://202.114.90.180/Course/");
	if (ret != 0)
		cerr << "Error in enterPage(), info: " << findError(ret) << endl;

	ret = tr.getTable("http://202.114.90.180/Course/grkbList.do", "TimeTable.html");
	if (ret != 0)
		cerr << "Error in getTable(), info: " << findError(ret) << endl;

}