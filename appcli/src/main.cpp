#include <iostream>

#include <appcli/command_line_parser.h>
#include <eraser/file_shredder.h>
#include <winapi-helpers/utilities.h>

using namespace appcli;
using std::cout;
using shredder::FileShredder;
using helpers::string_to_wstring;

constexpr std::string_view VER_PRODUCTVERSION_STR = "1.0.0";

static CommandLineParams& get_params()
{
    static CommandLineParams p;
    return p;
}

void usage()
{
    cout << get_params().options_descript() << '\n';
    exit(EXIT_SUCCESS);
}


void print_version()
{
    cout << "SecureEraser (c) version: " <<
        VER_PRODUCTVERSION_STR << '\n';
    exit(EXIT_SUCCESS);
}

void actions(const CommandLineParams& cmd_line_params)
{
    if (cmd_line_params.is_help()){
        usage();
    }

    if (cmd_line_params.is_version()) {
        print_version();
    }
    if (!cmd_line_params.erase_filename().empty()){
        FileShredder::instance().submit(string_to_wstring(cmd_line_params.erase_filename()), false);
    }
}

auto main(int argc, char* argv[]) -> int
{
    setlocale(0, "");
    get_params().read_params(argc, argv);
    actions(get_params());
    return 0;
}
