#pragma once
#include <string>
#include <curl/curl.h>
typedef CURLcode RETcode;
#define findError curl_easy_strerror
using namespace std;

class HttpReq {
private:
	CURL *curl;
	curl_slist* req;
protected:
	string postField;
public:
	HttpReq();
	void globalInit();
	void globalDeinit();
	void init();
	void deinit();
	void appendHeader(string headLine);
	void setCookie(string fileName);
	void saveFile(string fileName);
	RETcode get(string URL);
	RETcode post(string URL);
};