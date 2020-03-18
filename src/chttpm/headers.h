#pragma once

#include<vector>
#include<string>



namespace chttpm
{
	struct Header
	{
		std::string key;
		std::string value;

		Header(const char* key, const char* value);
		Header(const Header&) = default;
		Header(Header&&) = default;
		~Header() = default;

		Header& operator=(const Header&) = default;
		Header& operator=(Header&&) = default;
	};

	class Headers
	{
	public:
		// Sets the header @key with @value. If @key is already set, it will
		// be substituted.
		void Set(const char* key, const char* value);

		// Returns the header key and value at @index. If @index is out of bounds,
		// returns empty key and value.
		const Header GetHeader(int index) const;

		// Returns the header value of @key. If @key is not found, returns empty.
		std::string GetValue(const char* key) const;

		// Returns the header value at @index. If @index is out of bounds, returns empty.
		std::string GetValue(int index) const;

		// Returns the current quantity of key-value pairs.
		int size() const;



	private:
		std::vector<std::string> m_Keys;
		std::vector<std::string> m_Values;
	};
}