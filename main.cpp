#include <iostream>
#include "HttpReq.h"
#include "LoginReq.h"
#include "TimeTableReq.h"
#include "ScoreTableReq.h"
using namespace std;

int main(void) {
	HttpReq hr;
	LoginReq lr;
	TimeTableReq tr;
	ScoreTableReq sr;
	RETcode ret;

	hr.globalInit();

	lr.getInfo();
	lr.makeForm();
	ret = lr.login("http://sso.jwc.whut.edu.cn/Certification//login.do");
	if (ret != 0)
		cerr << "Error in HttpReq::login(), info: " << findError(ret) << endl;
	
	ret = tr.enterPage("http://202.114.90.180/Course/");
	if (ret != 0)
		cerr << "Error in TimeTableReq::enterPage(), info: " << findError(ret) << endl;

	ret = tr.getTable("http://202.114.90.180/Course/grkbList.do", "TimeTable.html");
	if (ret != 0)
		cerr << "Error in TimeTableReq::getTable(), info: " << findError(ret) << endl;

	ret = sr.enterPage("http://202.114.90.180/Score/", "mid.html");
	if (ret != 0)
		cerr << "Error in ScoreTableReq::enterPage(), info: " << findError(ret) << endl;
	
	sr.getSnkey("mid.html");
	sr.makeForm();

	ret = sr.getTable("http://202.114.90.180/Score/lscjList.do", "ScoreTable.html");
	if (ret != 0)
		cerr << "Error in ScoreTableReq::getTable(), info: " << findError(ret) << endl;
}