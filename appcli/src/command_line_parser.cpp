/* 2017-2020 WEBGEARS SERVICES LIMITED (c) All Rights Reserved. 
 * Proprietary and confidential.
 * The Software and any accompanying documentation are copyrighted and protected 
 * by copyright laws and international copyright treaties, as well as other 
 * intellectual property laws and treaties.
 * Unauthorized copying of this file, via any medium is strictly prohibited.
 */

#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include <boost/filesystem.hpp>

#include <panic_service/command_line_parser.h>

using namespace panic;

namespace po = boost::program_options;
namespace bf = boost::filesystem;

using std::string;

CommandLineParams::CommandLineParams() : cmd_options_description("Command-line interface has the following options")
{}

void CommandLineParams::read_params(int argc, char* argv[])
{
    cmd_options_description.add_options()
        ("help,h", "Print usage")
        ("version,V", "Print version")
        ("erase,e", po::value<string>(&_erase_filename), "Erase file")
        ;

    // command line params processing
    po::variables_map cmd_variables_map;
    po::store(parse_command_line(argc, argv, cmd_options_description), cmd_variables_map);
    po::notify(cmd_variables_map);

    set_flag(cmd_variables_map, _help, "help");
    set_flag(cmd_variables_map, _version, "version");
}

/**@brief Set some logical param */
void CommandLineParams::set_flag(const po::variables_map& vm, bool& flag, const char* str)
{
    if (vm.count(str)) {
        flag = true;
    }
}
