/*************************************************************************
    > File Name: lessonSheetReq.h
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/21 18:14:57
 ************************************************************************/
#include <string>
#include <curl/curl.h>
typedef CURLcode RETcode;
using namespace std;
class lessonSheetReq{
	private:
		string username;
		string password;
	public:
		lessonSheetReq();
		void getInfo();
		string makeForm();
}