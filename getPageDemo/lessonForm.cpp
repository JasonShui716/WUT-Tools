/*************************************************************************
    > File Name: lessonForm.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 18:35:01
 ************************************************************************/
#include "lessonForm.h"

lessonForm::lessonForm(){
	
}

lessonForm::joint(string user, string passwd){
	form = "systemId=&xmlmsg=&userName=" + "&password=" + password + "&type=xs";
}

lessonForm::globalInit(){
	curl_global_init(CURL_GLOBAL_ALL);
}
		
lessonForm::init(){
	curl = curl_easy_init();
}

lessonForm::getInfo(){
	cout << "username:";
	cin >> username;
	cout << "password:";
	cin >> password;
	form = joint(username, password);	
}

lessonForm::appendHeader(string headLine){

}


