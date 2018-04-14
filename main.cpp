#include <iostream>
#include "TimeTableReq.h"
using namespace std;

int main(void) {
	TimeTableReq tr;
	string form;
	RETcode ret;
	tr.globalInit();

	//Login
	tr.init();
	tr.getInfo();
	form = tr.makeForm();
	tr.appendHeader("User-Agent: Chrome");
	tr.appendHeader("Content-Type: application/x-www-form-urlencoded");
	tr.setCookie("cookies.txt");
	ret = tr.post("http://sso.jwc.whut.edu.cn/Certification//login.do", form);
	if (ret != 0)
		std::cerr << "error: " << findError(ret);
	tr.deinit();

	//Enter the Timetable site of the System
	tr.init();
	tr.appendHeader("User-Agent: Chrome");
	tr.appendHeader("Content-Type: application/x-www-form-urlencoded");
	tr.setCookie("cookies.txt");
	tr.get("http://202.114.90.180/Course/");
	tr.deinit();

	//Get the Timetable
	tr.init();
	tr.appendHeader("User-Agent: Chrome");
	tr.appendHeader("Content-Type: application/x-www-form-urlencoded");
	tr.setCookie("cookies.txt");
	tr.saveFile("Timetable.html");
	tr.get("http://202.114.90.180/Course/grkbList.do");
	tr.deinit();

	tr.globalDeinit();
}