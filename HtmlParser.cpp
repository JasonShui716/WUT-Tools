#include "HtmlParser.h"

HtmlParser::HtmlParser(std::string fileName){
    in.open(fileName, std::ios::in);
    std::stringstream ss;
    ss << in.rdbuf();
    content = ss.str();
    cd.parse(content.c_str());
}

std::string HtmlParser::parseByRule(std::string rule){
    std::string str;
    CSelection c = cd.find(rule);
    str = c.nodeAt(0).text();
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

HtmlParser::~HtmlParser(){

}