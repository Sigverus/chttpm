// Simple Context pattern.
// AngelScript allows custom classes to be defined in
// the script.
class RequestContext {
	// To store references, AngelScript has it's own Handle identifier.
	Logger@ logger;

	// AngelScript classes allows constructors. Others, such as copy constructor,
	// are also possible. The ':' initializer for members is not available.
	// Reference parameters can be of style 'in', 'out' and 'inout'. When not specified,
	// 'inout' is assumed.
	RequestContext(Logger& logger) {
		// Operations on handles are prepended by @. Note that this is accessed
		// by '.' operator. Without @, the operation are on the type.
		@this.logger = logger;
	}
};



// Receiving a context by const reference. The alternative could be a 'in' reference type,
// but a copy constructor of RequestContext would be called.
void doRequest(const RequestContext& context, const Request& request, Response& response) {
	// Enriching the context logger with more information is possible.
	context.logger.Info().Str("target", request.target).Msg("Processing request");

	response.statusCode = HttpStatusCode::Ok;
	
	response.body = "{\n";
	response.body += "    \"method\": \"" + request.method + "\",\n";
	response.body += "    \"target\": \"" + request.target + "\"\n";
	response.body += "}\n";
}



/* ProcessRequest is the entry point of the script from chttpm. The
request and responses are created by the chttpm engine, and cannot be
created by AngelScript scripts. */
void ProcessRequest(const Request& request, Response& response)
{
	// Logger is defined in the chttpm engine.
	Logger logger;

	// Add some initial information to the logger before adding it to
	// the context structure.
	logger = logger.With().Str("method", request.method).Logger();

	RequestContext context(logger);
	doRequest(context, request, response);
}
