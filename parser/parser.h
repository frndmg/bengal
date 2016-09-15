// Generated by Bisonc++ V5.02.00 on Wed, 14 Sep 2016 20:01:58 -0400

#ifndef Parser_h_included
#define Parser_h_included

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "../scanner/scanner.h"


#undef Parser
class Parser: public ParserBase
{
    // $insert scannerobject
    Scanner d_scanner;
        
    public:
        int parse();

    private:
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();                   // use, e.g., d_token, d_loc

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
        void exceptionHandler__(std::exception const &exc);
};


#endif
