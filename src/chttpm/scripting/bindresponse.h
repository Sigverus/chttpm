#pragma once

#include<string>

#include"helper/bindreference.h"



namespace chttpm
{
	struct Response;
	class ScriptingService;


	// Binds a chttpm::Response to the Angel Script engine, with needed extra
	// behaviors.
	class BindResponse final : public BindReference<BindResponse>
	{
	public:
		explicit BindResponse(Response& response);
		~BindResponse();

		int GetStatusCode() const;
		void SetStatusCode(int statusCode);

		std::string GetBody() const;
		void SetBody(std::string& body);

		static void RegisterIntoScriptingService(ScriptingService& scriptingService);



	private:
		Response& m_Response;
	};
}