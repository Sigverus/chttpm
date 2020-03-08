#pragma once

#include<string>

#include"../../log/log.h"
#include"../helper/bindreference.h"



namespace chttpm
{
	class Logger;
	class LoggerKeys;
	class MessageLoggerKeys;
	class BuilderLoggerKeys;

	class ScriptingService;



	class BindMessageLoggerKeys final : public BindReference<BindMessageLoggerKeys>
	{
	public:
		explicit BindMessageLoggerKeys(MessageLoggerKeys messageLoggerKeys);
		BindMessageLoggerKeys(const BindMessageLoggerKeys&);

		BindMessageLoggerKeys& Str(std::string key, std::string value);

		void Msg(std::string message) const;

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		MessageLoggerKeys m_MessageLoggerKeys;
	};



	class BindLogger;

	class BindBuilderLoggerKeys final : public BindReference<BindBuilderLoggerKeys>
	{
	public:
		explicit BindBuilderLoggerKeys(BuilderLoggerKeys builderLoggerKeys);

		BindBuilderLoggerKeys& Str(std::string key, std::string value);

		BindLogger* Logger() const;

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		BuilderLoggerKeys m_BuilderLoggerKeys;
	};



	class BindLogger final : public BindReference<BindLogger>
	{
	public:
		explicit BindLogger(Logger logger);

		BindMessageLoggerKeys* Info() const;
		BindBuilderLoggerKeys* With() const;

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		Logger m_Logger;
	};
}


