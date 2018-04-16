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
	void getInfo();
	void makeForm();
	RETcode login(string URL);
};