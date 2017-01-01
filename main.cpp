#include <iostream>
#include <fstream>

#include <boost/program_options.hpp>

#include <parser.h>
#include <libltdl/lt_system.h>

using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[])
{
    string input;

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help", "produce help message")
                ("input-file,", po::value<string>(&input)->default_value(""), "Input file");

        po::positional_options_description p;
        p.add("input-file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                  options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            cout << desc << endl;
            return 0;
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    auto fs = fstream(input);
    Parser parser(fs ? fs : cin);

//    parser.setDebug(true);

    if (parser.parse())
    {
        cerr << "Syntax error" << endl;
        // TODO: Show the syntax errors
        return EXIT_FAILURE;
    }

    auto ast = parser.ast();
    if (not ast.checkSemantic())
    {
        cerr << "Semantic error" << endl;
        // TODO: Show semantic errors
        return EXIT_FAILURE;
    }

    // GENERATE CODE
    ast.generateCode();

    return EXIT_SUCCESS;
}
