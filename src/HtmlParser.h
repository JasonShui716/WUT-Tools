#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Document.h"
#include "Node.h"

class HtmlParser{
    private:
        std::string content;
        std::ifstream in;
        CDocument cd;
    public:
        HtmlParser(std::string _fileName);
        ~HtmlParser();
        std::string parseByRule(std::string rule);
};