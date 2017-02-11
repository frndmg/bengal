#include <iostream>
#include <fstream>
#include <libltdl/lt_system.h>

#include <boost/program_options.hpp>

#include <parser.h>

#define TIGER_COMPILER_VERSION "0.1"
#define COPYRIGHT "Danilo Gómez Gómez & Fernando Martínez González"

using namespace std;
namespace po = boost::program_options;

int main(int argc, const char *argv[])
{
#ifdef NDEBUG
    cout << "Tiger Compiler Version " << TIGER_COMPILER_VERSION << endl;
    cout << "Copyright (C) 2016-2017 " << COPYRIGHT << endl << endl;
#endif

    string input;

    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help", "Produce help message")
                ("input-file,", po::value<string>(&input)->default_value(""), "Input file");

        po::positional_options_description p;
        p.add("input-file", 1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                  options(desc).positional(p).run(), vm);
        po::notify(vm);

        if (vm.count("help") or input == "")
        {
            cout << desc << endl;
            return EXIT_SUCCESS;
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        return EXIT_FAILURE;
    }

    auto fs = fstream(input);

    if (not fs)
    {
        cerr << "(0,0): File `" << input << "` can not be found" << endl;
        return EXIT_FAILURE;
    }

    Parser parser(fs);

//    parser.setDebug(true);

    if (parser.parse())
        return EXIT_FAILURE;

    auto ast = parser.ast();

    std::cout << ast << std::endl;

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
