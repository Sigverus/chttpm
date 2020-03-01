#pragma once

#include<memory>



class asIScriptEngine;

namespace chttpm
{
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

		void ExecuteModule(const char *moduleName);



	private:
		asIScriptEngine* scriptEngine = nullptr;
	};
}