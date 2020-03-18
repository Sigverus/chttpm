#include"headers.h"

#include<algorithm>



namespace chttpm
{
	Header::Header(const char* key, const char* value) :
		key(key), value(value)
	{
	}



	void Headers::Set(const char* key, const char* value)
	{
		const auto findIt = std::find(std::cbegin(m_Keys), std::cend(m_Keys), key);
		if (findIt == std::cend(m_Keys))
		{
			m_Keys.emplace_back(key);
			m_Values.emplace_back(value);
		}
		else
		{
			auto index = std::distance(std::cbegin(m_Keys), findIt);
			m_Values[index] = value;
		}
	}



	const Header Headers::GetHeader(int index) const
	{
		if (index < 0 || index >= int(m_Keys.size()))
			return Header{ "","" };

		return Header{ m_Keys[index].c_str(), m_Values[index].c_str() };
	}



	std::string Headers::GetValue(const char* key) const
	{
		const auto findIt = std::find(std::cbegin(m_Keys), std::cend(m_Keys), key);
		if (findIt == std::cend(m_Keys))
			return "";

		auto index = std::distance(std::cbegin(m_Keys), findIt);
		return m_Values[index];
	}



	std::string Headers::GetValue(int index) const
	{
		if (index < 0 || index >= int(m_Keys.size()))
			return "";

		return m_Values[index];
	}



	int Headers::size() const
	{
		return int(m_Keys.size());
	}
}
