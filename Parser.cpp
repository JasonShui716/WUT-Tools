#include "Parser.h"

Parser::Parser(std::string fileName){
    in.open(fileName, std::ios::in);
    stringstream ss;
    ss << in.rdbuf();
    content = ss.str();
    cd.parse(content.c_str());
}

std::string Parser::parseByRule(std::string rule){
    std::string str;
    CSelection c = cd.find(rule);
    str = c.nodeAt(0).text();
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
	str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
	return str;
}

Parser::~Parser(){

}