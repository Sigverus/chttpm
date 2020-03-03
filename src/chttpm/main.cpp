#include<iostream>

#include<httplib.h>

#include"request.h"
#include"response.h"

#include"scripting/scriptingservice.h"
#include"scripting/bindrequest.h"
#include"scripting/bindresponse.h"



int main(int argc, char* argv[])
{
	chttpm::ScriptingService scriptingService{};
	chttpm::BindRequest::RegisterIntoScriptingService(scriptingService);
	chttpm::BindResponse::RegisterIntoScriptingService(scriptingService);

	scriptingService.LoadModule("MyModule", "test.as");

	httplib::Server server{};

	auto handlerFunc = [&](const httplib::Request& request, httplib::Response& response)
	{
		// TODO : better way to build the request
		chttpm::Request chttpmRequest{};
		chttpmRequest.method = request.method;
		chttpmRequest.target = request.target;

		chttpm::Response chttpmResponse{};

		scriptingService.ProcessRequest("MyModule", chttpmRequest, chttpmResponse);

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

	server.listen("0.0.0.0", 8080);
	return 0;
}