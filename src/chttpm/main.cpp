#include<iostream>

#include<httplib.h>
#include<args.hxx>

#include"configuration.h"

#include"request.h"
#include"response.h"

#include"scripting/scriptingservice.h"
#include"scripting/startupbinder.h"



int main(int argc, char* argv[])
{
	auto[config, success, code] = chttpm::LoadConfigurationFromCommandLine(argc, argv);
	if (!success)
		return code;


	const auto scriptModule = "MainModule";
	chttpm::ScriptingService scriptingService{};
	chttpm::StartupBinder::BindAll(scriptingService);

	scriptingService.LoadModule(scriptModule, config.scriptFile.c_str());

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
		response.status = chttpmResponse.statusCode;
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
	server.listen(config.ipAddress.c_str(), config.port);
	std::cout << "Exiting" << std::endl;

	return 0;
}