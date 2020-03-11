#pragma once

#include<string>

#include"queryparameters.h"



namespace chttpm
{
	struct Request
	{
		// The HTTP Method used to access the server
		// Can be one of:
		// - DELETE
		// - GET
		// - OPTIONS
		// - PATCH
		// - POST
		// - PUT
		// TODO : convert to an enumerator
		std::string method;

		// The target used to access the server
		std::string target;

		// Stores the query parameters that can be found on @target.
		QueryParameters queryParameters;
	};
}