#include <iostream>
#include "TimeTableReq.h"
using namespace std;

int main(void) {
	TimeTableReq tr;
	RETcode ret;
	tr.globalInit();

	tr.init();
	tr.getInfo();
	tr.makeForm();
	tr.appendHeader("User-Agent: Chrome");
	tr.appendHeader("Content-Type: application/x-www-form-urlencoded");
	ret = tr.get("http://sso.jwc.whut.edu.cn/Certification//login.do");
	if (ret != 0)
		std::cerr << "error: " << findError(ret);
	tr.deinit();

	tr.globalDeinit();
}