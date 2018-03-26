/*************************************************************************
    > File Name: getLesson.cpp
    > Author: Jason Sui
    > Mail: jiashui@hotmail.com 
    > Created Time: 2018/3/22 21:27:54
 ************************************************************************/
#include "lessonSheetReq.h"
#include <iostream>
using namespace std;

int main(){
	lessonSheetReq r;
	string postForm;

	r.globalInit();
	r.getInfo();
	postForm = r.makeForm();
	r.appendHeader("User-Agent: Chrome");
	
}

