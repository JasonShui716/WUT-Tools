#include "HttpReq.h"

HttpReq::HttpReq()
{
	req = nullptr;
}

void HttpReq::globalInit()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

void HttpReq::globalDeinit()
{
	curl_global_cleanup();
}

void HttpReq::init()
{
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
}

void HttpReq::deinit()
{
	curl_easy_cleanup(curl);
}

void HttpReq::appendHeader(string headLine)
{
	req = curl_slist_append(req, headLine.c_str());
}

void HttpReq::setCookie(string fileName)
{
	curl_easy_setopt(curl, CURLOPT_COOKIEFILE, fileName.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIEJAR, fileName.c_str());
}

void HttpReq::saveFile(string fileName)
{
	FILE *fp;
	fp = fopen(fileName.c_str(), "w");
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
}

RETcode HttpReq::get(string URL)
{
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	return curl_easy_perform(curl);
}

RETcode HttpReq::post(string URL, string postField)
{
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postField.c_str());
	return curl_easy_perform(curl);
}



