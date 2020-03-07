#include"log.h"



namespace chttpm
{
	void DefaultLogOutput(const std::string output)
	{
		std::cout << output << std::endl;
	}

	std::function<void(const std::string)> OutputLogFunction{ DefaultLogOutput };



	LoggerKeys& LoggerKeys::Str(std::string key, std::string value)
	{
		m_Keys[key] = value;
		return *this;
	}



	MessageLoggerKeys::MessageLoggerKeys(const LoggerKeys& keys) :
		m_LoggerKeys(keys)
	{
	}



	MessageLoggerKeys& MessageLoggerKeys::Str(std::string key, std::string value)
	{
		m_LoggerKeys.Str(key, value);
		return *this;
	}



	void MessageLoggerKeys::Msg(std::string message) const
	{
		std::string output = "{";

		for (const auto& kv : m_LoggerKeys.m_Keys)
		{
			output += "\"" + kv.first + "\":\"" + kv.second + "\",";
		}

		output += "\"Msg\":\"" + message + "\"}";
		OutputLogFunction(output);
	}



	BuilderLoggerKeys::BuilderLoggerKeys(const LoggerKeys& keys) :
		m_LoggerKeys(keys)
	{
	}



	BuilderLoggerKeys& BuilderLoggerKeys::Str(std::string key, std::string value)
	{
		m_LoggerKeys.Str(key, value);
		return *this;
	}



	Logger BuilderLoggerKeys::Logger() const
	{
		return chttpm::Logger{ m_LoggerKeys };
	}



	Logger::Logger(const LoggerKeys& keys) :
		m_LoggerKeys(keys)
	{
	}



	MessageLoggerKeys Logger::Info() const
	{
		return MessageLoggerKeys{ m_LoggerKeys };
	}



	BuilderLoggerKeys Logger::With() const
	{
		return BuilderLoggerKeys{ m_LoggerKeys };
	}
}
