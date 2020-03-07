#pragma once

#include<string>
#include<iostream>
#include<functional>
#include<unordered_map>



namespace chttpm
{
	class Logger;
	class MessageLoggerKeys;
	class BuilderLoggerKeys;

	extern std::function<void(const std::string)> OutputLogFunction;



	class LoggerKeys final
	{
		friend class MessageLoggerKeys;
		friend class BuilderLoggerKeys;

	public:
		LoggerKeys() = default;
		LoggerKeys(const LoggerKeys&) = default;

		LoggerKeys& Str(std::string key, std::string value);



	private:
		std::unordered_map<std::string, std::string> m_Keys;
	};



	class MessageLoggerKeys final
	{
	public:
		explicit MessageLoggerKeys(const LoggerKeys& keys);

		MessageLoggerKeys& Str(std::string key, std::string value);

		void Msg(std::string message) const;



	private:
		LoggerKeys m_LoggerKeys;
	};



	class BuilderLoggerKeys final
	{
	public:
		explicit BuilderLoggerKeys(const LoggerKeys& keys);

		BuilderLoggerKeys& Str(std::string key, std::string value);

		Logger Logger() const;



	private:
		LoggerKeys m_LoggerKeys;
	};



	class Logger
	{
	public:
		Logger() = default;
		explicit Logger(const LoggerKeys& keys);

		MessageLoggerKeys Info() const;
		BuilderLoggerKeys With() const;
	private:
		LoggerKeys m_LoggerKeys;
	};
}
