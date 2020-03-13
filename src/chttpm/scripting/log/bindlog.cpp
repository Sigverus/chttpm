#include"bindlog.h"

#include<cassert>

#include<angelscript.h>

#include"../scriptingservice.h"
#include"../../log/log.h"



namespace chttpm
{
	BindMessageLoggerKeys::BindMessageLoggerKeys(MessageLoggerKeys messageLoggerKeys) :
		m_MessageLoggerKeys(messageLoggerKeys)
	{
	}



	BindMessageLoggerKeys& BindMessageLoggerKeys::Str(std::string key, std::string value)
	{
		m_MessageLoggerKeys.Str(key, value);
		return *this;
	}



	void BindMessageLoggerKeys::Msg(std::string message) const
	{
		m_MessageLoggerKeys.Msg(message);
	}



	void BindMessageLoggerKeys::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("MessageLoggerKeys", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("MessageLoggerKeys", scriptingService);
	}



	void BindMessageLoggerKeys::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("MessageLoggerKeys", "MessageLoggerKeys& Str(string, string)", asMETHOD(BindMessageLoggerKeys, Str), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("MessageLoggerKeys", "void Msg(string) const", asMETHOD(BindMessageLoggerKeys, Msg), asCALL_THISCALL); assert(r >= 0);
	}



	BindBuilderLoggerKeys::BindBuilderLoggerKeys(BuilderLoggerKeys builderLoggerKeys) :
		m_BuilderLoggerKeys(builderLoggerKeys)
	{
	}



	BindBuilderLoggerKeys& BindBuilderLoggerKeys::Str(std::string key, std::string value)
	{
		m_BuilderLoggerKeys.Str(key, value);
		return *this;
	}



	BindLogger* BindBuilderLoggerKeys::Logger() const
	{
		return new BindLogger{ m_BuilderLoggerKeys.Logger() };
	}



	void BindBuilderLoggerKeys::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("BuilderLoggerKeys", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("BuilderLoggerKeys", scriptingService);
	}



	void BindBuilderLoggerKeys::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("BuilderLoggerKeys", "BuilderLoggerKeys& Str(string, string)", asMETHOD(BindBuilderLoggerKeys, Str), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("BuilderLoggerKeys", "Logger@ Logger() const", asMETHOD(BindBuilderLoggerKeys, Logger), asCALL_THISCALL); assert(r >= 0);
	}



	BindLogger::BindLogger(Logger logger) :
		m_Logger(logger)
	{
	}



	BindMessageLoggerKeys* BindLogger::Info() const
	{
		return new BindMessageLoggerKeys{ m_Logger.Info() };
	}



	BindBuilderLoggerKeys* BindLogger::With() const
	{
		return new BindBuilderLoggerKeys{ m_Logger.With() };
	}



	BindLogger& BindLogger::OpAssign(const BindLogger& other)
	{
		this->m_Logger = other.m_Logger;
		return *this;
	}



	BindLogger *BindLoggerFactory()
	{
		return new BindLogger{ Logger{} };
	}



	void BindLogger::RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
	{
		int r = scriptingService.scriptEngine->RegisterObjectType("Logger", 0, asOBJ_REF); assert(r >= 0);
		BindReference::RegisterIntoScriptingService("Logger", scriptingService);
	}



	void BindLogger::RegisterOperationsIntoScriptingService(ScriptingService& scriptingService)
	{
		int r;

		// Factory
		r = scriptingService.scriptEngine->RegisterObjectBehaviour("Logger", asBEHAVE_FACTORY, "Logger@ f()", asFUNCTION(BindLoggerFactory), asCALL_CDECL); assert(r >= 0);

		// Methods
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "MessageLoggerKeys@ Info() const", asMETHOD(BindLogger, Info), asCALL_THISCALL); assert(r >= 0);
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "BuilderLoggerKeys@ With() const", asMETHOD(BindLogger, With), asCALL_THISCALL); assert(r >= 0);

		// Operators
		r = scriptingService.scriptEngine->RegisterObjectMethod("Logger", "Logger& opAssign(const Logger&)", asMETHOD(BindLogger, OpAssign), asCALL_THISCALL);
	}
}
