#include"configuration.h"

#include<iostream>

#include<args.hxx>



namespace chttpm
{
	std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode> LoadConfigurationFromCommandLine(int argc, char* argv[])
	{
		args::ArgumentParser argumentParser{
			"C++ HTTP Mock utility",
			"If you need complex logic, seriously consider using a better solution than this"
		};

		args::HelpFlag argumentHelp{
			argumentParser,
			"help",
			"Displays the help information",
			{'h', "help"}
		};

		args::ValueFlag<std::string> scriptArgument{
			argumentParser,
			"file",
			"Script to be used to handle all incoming requests. Defaults to 'main.as'",
			{'s', "script"},
			"main.as"
		};

		args::ValueFlag<std::string> listeningAddressArgument{
			argumentParser,
			"address",
			"Address to listen. Defaults to '0.0.0.0' (any)",
			{'a', "address"},
			"0.0.0.0"
		};

		args::ValueFlag<std::int16_t> listeningPortArgument{
			argumentParser,
			"port number",
			"Port to listen. Default to '8080'.",
			{'p', "port"},
			8080
		};

		args::CompletionFlag argumentCompletion{ argumentParser, {"complete"} };


		Configuration config{};

		try
		{
			argumentParser.ParseCLI(argc, argv);
		}
		catch (const args::Completion& e)
		{
			std::cout << e.what();
			return std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode>(config, false, 0);
		}
		catch (const args::Help&)
		{
			std::cout << argumentParser;
			return std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode>(config, false, 0);
		}
		catch (const args::ParseError& e)
		{
			std::cerr << e.what() << std::endl;
			std::cerr << argumentParser;
			return std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode>(config, false, 1);
		}

		config.ipAddress = listeningAddressArgument.Get();
		config.port = listeningPortArgument.Get();
		config.scriptFile = scriptArgument.Get();

		return std::tuple<Configuration, ConfigLoadSuccess, ConfigLoadCode>(config, true, 0);
	}
}