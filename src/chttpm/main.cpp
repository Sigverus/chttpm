#include<iostream>

#include<httplib.h>

#include"request.h"

#include"scripting/scriptingservice.h"
#include"scripting/bindrequest.h"



int main(int argc, char* argv[])
{
	chttpm::ScriptingService scriptingService{};
	chttpm::BindRequest::RegisterIntoScriptingService(scriptingService);
	scriptingService.LoadModule("MyModule", "test.as");

	httplib::Server server{};

	auto handlerFunc = [&](const httplib::Request& request, httplib::Response& response)
	{
		auto url = request.matches[1];
		char buffer[512]; // Not really safe. Will be removed soon, when we removing the hello world.
		sprintf(buffer, "%s %s\nHello World!\n", request.method.c_str(), request.target.c_str());
		response.set_content(buffer, "text/plain");

		// TODO : better way to build the request
		chttpm::Request chttpmRequest{};
		chttpmRequest.method = request.method;
		chttpmRequest.target = request.target;


		scriptingService.ProcessRequest("MyModule", chttpmRequest);
	};

	server.Delete(R"((.*))", handlerFunc);
	server.Get(R"((.*))", handlerFunc);
	server.Options(R"((.*))", handlerFunc);
	server.Patch(R"((.*))", handlerFunc);
	server.Post(R"((.*))", handlerFunc);
	server.Put(R"((.*))", handlerFunc);

	server.listen("0.0.0.0", 8080);
	return 0;
}