#pragma once
#include "HttpReq.h"
using namespace std;


class LoginReq : public HttpReq {

private:
	string username;
	string password;
public:
	LoginReq() = default;
	~LoginReq() = default;

#ifdef __QT_GUI__
    void QGetInfo(string user, string pswd);
#endif

	void getInfo();
	void makeForm();
	RETcode login(string URL);
};
