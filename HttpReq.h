#pragma once
#include <string>
#include <curl/curl.h>
typedef CURLcode RETcode;
using namespace std;

class HttpReq {
private:
	CURL *curl;
	curl_slist* req;
public:
	HttpReq();
	void globalInit();
	void globalDeinit();
	void init();
	void deinit();
	void appendHeader(string headLine);
	void setCookie(string fileName);
	void saveFile(FILE *fp);
	RETcode get(string URL);
	RETcode post(string URL, string postField);
};