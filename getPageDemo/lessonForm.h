/*************************************************************************
    > File Name: lessonForm.h
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/21 18:14:57
 ************************************************************************/
#define CURLcode RETcode;
#include <string>
#include <curl/curl.h>
using namespace std;
class lessonForm{
	private:
		CURL curl;
		CURLcode res;
		curl_slist* req;
		string username;
		string password;
		string joint(string user, string passwd);
	public:
		string form;
		lessonForm();
		void globalInit();
		void init();
		void getInfo();
		void appendHeader(string headLine);
		RETcode get(string URL);		
		RETcode post(string URL, string form);
}
