/*************************************************************************
    > File Name: lessonSheetReq.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "LessonSheetReq.h"
#include <iostream>
using namespace std;

lessonSheetReq::lessonSheetReq(){

}

void lessonSheetReq::getInfo(){
	cout << "username:";
	cin >> username;
	cout << "password:";
	cin >> password;
}

string lessonSheetReq::makeForm(){
	return "systemId=&xmlmsg=&userName=" + username + "&password=" + password + "&type=xs";
}