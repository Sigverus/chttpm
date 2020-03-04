#pragma once

#include<string>



namespace chttpm
{
	// Response to be returned to the HTTP client by the server
	struct Response
	{
		// HTTP Status Code of the response
		int statusCode;

		// Body of the response (contents), represented as a string
		std::string body;
	};
}