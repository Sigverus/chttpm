#include<iostream>

#include<httplib.h>

#include"scripting/scriptingservice.h"



int main(int argc, char* argv[])
{
	chttpm::ScriptingService scriptingService{};
	scriptingService.LoadModule("MyModule", "test.as");

	httplib::Server server{};

	server.Delete(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Delete] Hello World!", "text/plain");
		}
	);


	server.Get(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Get] Hello World! " + request.target, "text/plain");

			scriptingService.ExecuteModule("MyModule");
		}
	);

	server.Options(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Options] Hello World!", "text/plain");
		}
	);

	server.Patch(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Patch] Hello World!", "text/plain");
		}
	);

	server.Post(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Post] Hello World!\n" + request.body, "text/plain");
		}
	);

	server.Put(
		R"((.*))",
		[&](const httplib::Request& request, httplib::Response& response)
		{
			auto url = request.matches[1];
			response.set_content(url.str() + "\n[Put] Hello World!", "text/plain");
		}
	);

	server.listen("0.0.0.0", 8080);
	return 0;
}