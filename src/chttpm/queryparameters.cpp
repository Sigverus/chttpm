#include"queryparameters.h"

#include<algorithm>



namespace chttpm
{
	void QueryParameters::Add(const std::string key, const std::string value)
	{
		m_Keys.emplace_back(key);
		m_Values.emplace_back(value);
	}



	std::string QueryParameters::GetValue(const std::string key) const
	{
		auto findIt = std::find(std::cbegin(m_Keys), std::cend(m_Keys), key);
		if (findIt == std::cend(m_Keys))
			return "";

		auto index = std::distance(std::cbegin(m_Keys), findIt);
		return m_Values.at(index);
	}



	std::string QueryParameters::GetValue(int index) const
	{
		if (index < 0 || index >= int(m_Values.size()))
			return "";

		return m_Values.at(index);
	}



	int QueryParameters::size() const
	{
		return int(m_Keys.size());
	}
}
