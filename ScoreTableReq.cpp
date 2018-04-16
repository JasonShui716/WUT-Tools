#include "ScoreTableReq.h"
#include <fstream>
#include <regex>
using namespace std;

void ScoreTableReq::getInfo(string fileName)
{
	regex r("(?=snkey=).+(?=t \")");
	smatch sm;
	string str;
	ifstream in(fileName);
	while (getline(in, str)) {
		
	}

}
