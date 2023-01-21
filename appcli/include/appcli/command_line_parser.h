#pragma once
#include <memory>
#include <string>
#include <boost/program_options.hpp>

// The header contains command-line parser for the PanicButton service application
// It uses Boost.ProgramOptions

namespace panic {

/**@brief Storage for all passed and default command-line params */
class CommandLineParams {
public:

    /// @brief Should have a constructor by default
    CommandLineParams();

    /// @brief Parse raw command-line parameters
    void read_params(int argc, char* argv[]);

    /// @brief Set some logical param
    void set_flag(const boost::program_options::variables_map& vm, bool& flag, const char* str);

    /// @brief Get available options list
    boost::program_options::options_description& options_descript(){ return cmd_options_description; }

    //////////////////////////////////////////////////////////////////////////
    /// Accessors

    /// @brief Print command line help
    bool is_help() const 
    {
        return _help;
    }

    /// @brief Print service version (from CMake-generated version.h file)
    bool is_version() const 
    {
        return _version;
    }

    const std::string erase_filename() const
    {
        return _erase_filename;
    }

private:

    /// Show help
    bool _help = false;

    /// Show version
    bool _version = false;

    /// Log filename if erase
    std::string _erase_filename;

    /// All options
    boost::program_options::options_description cmd_options_description;
};

} // namespace panic
