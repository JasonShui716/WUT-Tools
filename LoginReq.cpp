#include "LoginReq.h"
#include <iostream>
using namespace std;

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
	ret = this->post("http://sso.jwc.whut.edu.cn/Certification//login.do");
	this->deinit();
	return ret;
}
