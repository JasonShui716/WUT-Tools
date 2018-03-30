/*************************************************************************
    > File Name: TimeTableReq.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "TimeTableReq.h"
#include <iostream>
using namespace std;

TimeTableReq::TimeTableReq(){

}

void TimeTableReq::getInfo(){
	cout << "username:";
	cin >> username;
	cout << "password:";
	cin >> password;
}

string TimeTableReq::makeForm(){
	return "systemId=&xmlmsg=&userName=" + username + "&password=" + password + "&type=xs";
}