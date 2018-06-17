#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Document.h"
#include "Node.h"

class Parser{
    private:
        std::string content;
        std::ifstream in;
        CDocument cd;
    public:
        Parser(std::string _fileName);
        ~Parser();
        string parseByRule(std::string rule);
}