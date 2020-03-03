#pragma once

#include<string>
#include<tuple>



namespace chttpm
{
	// Configuration that should be used by chttm. Will be created by the
	// LoadConfiguration function.
	struct Configuration
	{
		std::string ipAddress;
		int port;

		std::string scriptFile;
	};

	// Loads the configuration from the command line arguments
	using ConfigLoadSuccess = bool;
	using ConfigLoadCode = int;
	std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode> LoadConfigurationFromCommandLine(int argc, char* argv[]);
}