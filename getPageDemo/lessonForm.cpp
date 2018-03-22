/*************************************************************************
    > File Name: lessonForm.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "lessonForm.h"

lessonForm::lessonForm(){
	req = NULL;
}

string lessonForm::joint(string user, string passwd){
	return "systemId=&xmlmsg=&userName=" + "&password=" + password + "&type=xs";
}

void lessonForm::globalInit(){
	curl_global_init(CURL_GLOBAL_ALL);
}
		
void lessonForm::globalDeinit(){
	curl_global_cleanup();
}

void lessonForm::init(){
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
}

void lessonForm::deinit(){
	curl_easy_cleanup(curl);
}

void lessonForm::getInfo(){
	cout << "username:";
	cin >> username;
	cout << "password:";
	cin >> password;
}

string lessonForm::makeForm(){
	return joint(username, password);
}

void setCookie(string fileName){
	curl_easy_setopt(curl, CURLOPT_COOKIEFILE, fileName.c_str());
	curl_easy_setopt(curl, CURLOPT_COOKIEJAR, fileName.c_str());
}

void lessonForm::appendHeader(string headLine){
	req = curl_slist_append(req, headLine.c_str());
}

void lessonForm::saveFile(File *fp){
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);	
}

RETcode lessonForm::get(string URL){
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	res = curl_easy_perform(curl);
	return res;
}

RETcode lessonForm::post(string URL, string postField){
	curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, req);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postField.c_str);
	res = curl_easy_perform(curl);
	return res;
}
