/*************************************************************************
    > File Name: TimeTableReq.h
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/21 18:14:57
 ************************************************************************/
#include "HttpReq.h"
using namespace std;
class TimeTableReq : public HttpReq{
	private:
		string username;
		string password;
	public:
		TimeTableReq();
		void getInfo();
		string makeForm();
};