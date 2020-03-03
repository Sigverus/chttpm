#include<iostream>

#include<httplib.h>
#include<args.hxx>

#include"request.h"
#include"response.h"

#include"scripting/scriptingservice.h"
#include"scripting/bindrequest.h"
#include"scripting/bindresponse.h"



int main(int argc, char* argv[])
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


	try
	{
		argumentParser.ParseCLI(argc, argv);
	}
	catch (const args::Completion& e)
	{
		std::cout << e.what();
		return 0;
	}
	catch (const args::Help&)
	{
		std::cout << argumentParser;
		return 0;
	}
	catch (const args::ParseError& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << argumentParser;
		return 1;
	}



	const auto scriptModule = "MainModule";
	chttpm::ScriptingService scriptingService{};
	chttpm::BindRequest::RegisterIntoScriptingService(scriptingService);
	chttpm::BindResponse::RegisterIntoScriptingService(scriptingService);

	scriptingService.LoadModule(scriptModule, scriptArgument.Get().c_str());

	httplib::Server server{};

	auto handlerFunc = [&](const httplib::Request& request, httplib::Response& response)
	{
		// TODO : better way to build the request
		chttpm::Request chttpmRequest{};
		chttpmRequest.method = request.method;
		chttpmRequest.target = request.target;

		chttpm::Response chttpmResponse{};

		scriptingService.ProcessRequest(scriptModule, chttpmRequest, chttpmResponse);

		// TODO : better way to set from the response
		response.body = chttpmResponse.body;
		response.set_header("Content-Type", "text/plain");
	};

	server.Delete(R"((.*))", handlerFunc);
	server.Get(R"((.*))", handlerFunc);
	server.Options(R"((.*))", handlerFunc);
	server.Patch(R"((.*))", handlerFunc);
	server.Post(R"((.*))", handlerFunc);
	server.Put(R"((.*))", handlerFunc);

	std::cout << "Starting Server" << std::endl;
	server.listen(
		listeningAddressArgument.Get().c_str(),
		listeningPortArgument.Get()
	);
	std::cout << "Exiting" << std::endl;

	return 0;
}