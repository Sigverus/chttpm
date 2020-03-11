#pragma once

#include<string>
#include<vector>



namespace chttpm
{
	class QueryParameters
	{
	public:
		// Adds a parameter to the query parameters. Repeated won't be ignored.
		void Add(const std::string key, const std::string value);

		// Returns the first value for @key found. Empty if not found.
		std::string Get(const std::string key) const;

		// Returns the value for @index. Empty if out of bounds.
		std::string Get(int index) const;

		// Returns the number of registered parameters. Repeats included
		int size() const;



	private:
		std::vector<std::string> m_Keys;
		std::vector<std::string> m_Values;
	};
}