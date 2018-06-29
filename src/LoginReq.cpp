#include "LoginReq.h"
#include <iostream>
using namespace std;

#ifdef __QT_GUI__
void LoginReq::QGetInfo(string user, string pswd){
    username = user;
    password = pswd;
}
#endif

void LoginReq::getInfo()
{
	cout << "username:";
	cin >> username;
	cout << "password:";
	cin >> password;
}

void LoginReq::makeForm() {
	postField = "userName=" + username + "&password=" + password + "&type=xs";
}

RETcode LoginReq::login(string URL) {
	RETcode ret;
	this->init();
	this->appendHeader("User-Agent: Chrome");
	this->appendHeader("Content-Type: application/x-www-form-urlencoded");
	this->setCookie("cookies.txt");
	ret = this->post(URL.c_str());
	this->deinit();
	return ret;
}
