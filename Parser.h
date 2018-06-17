#include <iostream>
#include <fstream>
#include <algorithm>
#include "Document.h"
#include "Node.h"

class Parser{
    private:
        std::string fileName;
        std::string content;
        std::ifstream in;
        CDocument cd;
    public:
        Parser(std::string _fileName);
        ~Parser();
        string parseByRule(std::string rule);
}