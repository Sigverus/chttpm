#pragma once

#include<memory>



class asIScriptEngine;

namespace chttpm
{
	struct Request;



	class ScriptingService final
	{
	public:
		ScriptingService();
		~ScriptingService();

		ScriptingService(const ScriptingService&) = delete;
		ScriptingService(ScriptingService&&) = default;

		ScriptingService& operator=(const ScriptingService&) = delete;
		ScriptingService& operator=(ScriptingService&&) = default;

		// TODO : overload with multiple files
		void LoadModule(const char* moduleName, const char *scriptFile);

		void ProcessRequest(const char *moduleName, const Request& request) const;



		// private:
	public: // TODO : temporarily public until which pattern to register objects without exposing this is decided
		asIScriptEngine* scriptEngine = nullptr;
	};
}