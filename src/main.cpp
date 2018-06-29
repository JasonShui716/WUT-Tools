#include <iostream>
#include <cstdlib>
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

#ifdef _WIN32
    system("md html");
#endif

#ifdef __linux__
    system("mkdir html");
#endif

    hr.globalInit();

    lr.getInfo();
    lr.makeForm();
    ret = lr.login("http://sso.jwc.whut.edu.cn/Certification//login.do");
    if (ret != 0)
        cerr << "Error in HttpReq::login(), info: " << findError(ret) << endl;

    ret = tr.enterPage("http://59.69.102.13/Course/");
    if (ret != 0)
        cerr << "Error in TimeTableReq::enterPage(), info: " << findError(ret) << endl;
    
    ret = tr.getTable("http://59.69.102.13/Course/grkbList.do", "./html/TimeTable.html");
    if (ret != 0)
        cerr << "Error in TimeTableReq::getTable(), info: " << findError(ret) << endl;
    tr.completeHTML("./html/TimeTable.html");
    
    ret = sr.enterPage("http://202.114.90.180/Score/", "./html/mid.html");
    if (ret != 0)
        cerr << "Error in ScoreTableReq::enterPage(), info: " << findError(ret) << endl;

    sr.getSnkey("./html/ScoreTable.html");
    sr.makeForm();

    ret = sr.getTable("http://202.114.90.180/Score/lscjList.do", "./html/ScoreTable.html");
    if (ret != 0)
        cerr << "Error in ScoreTableReq::getTable(), info: " << findError(ret) << endl;
    sr.completeHTML("./html/ScoreTable.html");

    hr.globalDeinit();
}
