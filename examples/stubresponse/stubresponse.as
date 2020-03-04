void ProcessRequest(const Request& request, Response& response)
{
	print("LOG: received [" + request.method + "] request on target [" + request.target + "]");

	response.body = "{\n";
	response.body += "    \"method\": \"" + request.method + "\",\n";
	response.body += "    \"target\": \"" + request.target + "\"\n";
	response.body += "}\n";
}