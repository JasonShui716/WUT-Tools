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
		lessonForm();
		void globalInit();
		void globalDeinit();
		void init();
		void deinit();
		void getInfo();
		void appendHeader(string headLine);
		void saveFile(FILE *fp);
		RETcode get(string URL);		
		RETcode post(string URL, string form);
}
