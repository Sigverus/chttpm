#include"queryparameters.h"

#include<algorithm>



namespace chttpm
{
	void QueryParameters::Add(const std::string key, const std::string value)
	{
		m_Keys.emplace_back(key);
		m_Values.emplace_back(value);
	}



	std::string QueryParameters::Get(const std::string key) const
	{
		auto findIt = std::find(std::begin(m_Keys), std::end(m_Keys), key);
		if (findIt == std::end(m_Keys))
			return "";

		auto index = std::distance(std::begin(m_Keys), findIt);
		return m_Values.at(index);
	}



	std::string QueryParameters::Get(int index) const
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
