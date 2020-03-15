# C++ HTTP Mock

C++ HTTP Mock (chttpm) was born out of the need of making quick-and-dirty mocks of REST Web Services to aid with software testing. This is a small utility project with the aim of making HTTP servers with hard coded behavior easier.

## When to use

- A mock to a web service is needed over HTTP (as in not hard-wired stub in a project code);
- Dumb answers over simple logic is enough to be useful;
- You don't know, or cannot use, or do not want to use other fast solutions involving as-fast means such as Python or Go;
- You like Angelscript.

## When to NOT use

- You need more than dumb or stub answers. In this case, you're more likely better out making your own mock from scratch. Many languages and libraries can make this reasonably painless;
- Mock performance is a must;
- You intend of making a real application.

# Dependencies

This project has the following dependencies:

- `Cpp HTTPLib`: simple header only HTTP Library to act as the HTTP Server.
- `Angel Script`: scripting language to allow to change the HTTP Server behavior without recompiling the source.
- `Args`: header only library to handle the command lines arguments.

The dependencies are included in the source code and compiled together with CHTTPM. See their respective folders for information about their licenses.

# How to use

You don't. The project is still in a too early of an state to be useful. Anyway...

Run `chttpm`. It will attempt to load a `main.as` Angel Script file for execution. As of now, there is no hot-reloading of the script file. Use `--help` to see all configuration.

## Dumb Script example

```c++
void ProcessRequest(const Request& request, Response& response)
{
	print("LOG: received [" + request.method + "] request on target [" + request.target + "]");

	response.statusCode = HttpStatusCode::Ok;
	
	response.body = "{\n";
	response.body += "    \"method\": \"" + request.method + "\",\n";
	response.body += "    \"target\": \"" + request.target + "\"\n";
	response.body += "}\n";
}
```

## A more complex example

This is a more complex example to show more of the Angel Script and chttpm capabilities. If you're getting into something like this, I'd suggest you to go straight into C++, Go or Python though.

```c++
// Simple Context pattern.
// AngelScript allows custom classes to be defined in
// the script.
class RequestContext {
	// To store references, AngelScript has it's own Handle identifier.
	Logger@ logger;

	// AngelScript classes allows constructors. Others, such as copy constructor,
	// are alse possible. The ':' initializer for members is not available.
	// Reference parameters can be of style 'in', 'out' and 'inout'. When not specified,
	// 'inout' is assumed.
	RequestContext(Logger& logger) {
		// Operations on handles are prepended by @. Note that this is accesed
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
```


## Exposed Types

The exposed types are very limited as I am learning how to bind data with the Angel Script engine.

The currently exposed types are as defined by their source files:

- [HttpStatusCode](./src/chttpm/httpstatuscode.h)
- [Request](./src/chttpm/request.h)
- [Response](./src/chttpm/response.h)
- [Log](./src/chttpm/log/log.h) (will be broken down into multiple files in the future)

There is a `void print(std::string)` function exported, but it will eventually be substituted by a logging entity.

# Features Checklist

These are the available or intended features of chttpm:

- [x] Read request target
- [x] Read request method
- [x] Read request query parameters
- [ ] Read request headers
- [ ] Read request body
- [ ] Write response headers
- [ ] Write response body
- [x] Simple pseudo-json logger
- [ ] Scripts hot reloading

# Compiling

TODO : write this

# License

CHTTPM is licensed under the `BSD 3-Clause License` license. See `src/chttpm/LICENSE` file for more information.