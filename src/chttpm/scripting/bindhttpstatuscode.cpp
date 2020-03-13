#include"bindhttpstatuscode.h"

#include<cassert>

#include<angelscript.h>

#include"scriptingservice.h"
#include"../httpstatuscode.h"



namespace chttpm
{
	namespace BindHttpStatusCode
	{
		void RegisterTypeIntoScriptingService(ScriptingService& scriptingService)
		{
			int r;

			r = scriptingService.scriptEngine->SetDefaultNamespace("HttpStatusCode");

			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Continue", (void*)&HttpStatusCode::Continue); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int SwitchingProtocols", (void*)&HttpStatusCode::SwitchingProtocols); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Processing", (void*)&HttpStatusCode::Processing); assert(r >= 0);

			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Ok", (void*)&HttpStatusCode::Ok); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Created", (void*)&HttpStatusCode::Created); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Accepted", (void*)&HttpStatusCode::Accepted); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NonAuthoritativeInformation", (void*)&HttpStatusCode::NonAuthoritativeInformation); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NoContent", (void*)&HttpStatusCode::NoContent); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ResetContent", (void*)&HttpStatusCode::ResetContent); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PartialContent", (void*)&HttpStatusCode::PartialContent); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int MultiStatus", (void*)&HttpStatusCode::MultiStatus); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int AlreadyReported", (void*)&HttpStatusCode::AlreadyReported); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int IMUsed", (void*)&HttpStatusCode::IMUsed); assert(r >= 0);

			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int MultipleChoices", (void*)&HttpStatusCode::MultipleChoices); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int MovedPermanently", (void*)&HttpStatusCode::MovedPermanently); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Found", (void*)&HttpStatusCode::Found); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int SeeOther", (void*)&HttpStatusCode::SeeOther); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NotModified", (void*)&HttpStatusCode::NotModified); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int UseProxy", (void*)&HttpStatusCode::UseProxy); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int TemporaryRedirect", (void*)&HttpStatusCode::TemporaryRedirect); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PermanentRedirect", (void*)&HttpStatusCode::PermanentRedirect); assert(r >= 0);

			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int BadRequest", (void*)&HttpStatusCode::BadRequest); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Unauthorized", (void*)&HttpStatusCode::Unauthorized); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PaymentRequired", (void*)&HttpStatusCode::PaymentRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Forbidden", (void*)&HttpStatusCode::Forbidden); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NotFound", (void*)&HttpStatusCode::NotFound); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int MethodNotAllowed", (void*)&HttpStatusCode::MethodNotAllowed); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NotAcceptable", (void*)&HttpStatusCode::NotAcceptable); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ProxyAuthenticationRequired", (void*)&HttpStatusCode::ProxyAuthenticationRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int RequestTimeout", (void*)&HttpStatusCode::RequestTimeout); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Conflict", (void*)&HttpStatusCode::Conflict); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Gone", (void*)&HttpStatusCode::Gone); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int LengthRequired", (void*)&HttpStatusCode::LengthRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PreconditionFailed", (void*)&HttpStatusCode::PreconditionFailed); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PayloadTooLarge", (void*)&HttpStatusCode::PayloadTooLarge); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int RequestURITooLong", (void*)&HttpStatusCode::RequestURITooLong); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int UnsupportedMediaType", (void*)&HttpStatusCode::UnsupportedMediaType); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int RequestedRangeNotSatisfiable", (void*)&HttpStatusCode::RequestedRangeNotSatisfiable); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ExpectationFailed", (void*)&HttpStatusCode::ExpectationFailed); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ImATeapot", (void*)&HttpStatusCode::ImATeapot); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int MisdirectedRequest", (void*)&HttpStatusCode::MisdirectedRequest); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int UnprocessableEntity", (void*)&HttpStatusCode::UnprocessableEntity); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int Locked", (void*)&HttpStatusCode::Locked); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int FailedDependency", (void*)&HttpStatusCode::FailedDependency); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int UpgradeRequired", (void*)&HttpStatusCode::UpgradeRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int PreconditionRequired", (void*)&HttpStatusCode::PreconditionRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int TooManyRequests", (void*)&HttpStatusCode::TooManyRequests); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int RequestHeaderFieldsTooLarge", (void*)&HttpStatusCode::RequestHeaderFieldsTooLarge); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ConnectionClosedWithoutResponse", (void*)&HttpStatusCode::ConnectionClosedWithoutResponse); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int UnavailableForLegalReasons", (void*)&HttpStatusCode::UnavailableForLegalReasons); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ClientClosedRequest", (void*)&HttpStatusCode::ClientClosedRequest); assert(r >= 0);

			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int InternalServerError", (void*)&HttpStatusCode::InternalServerError); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NotImplemented", (void*)&HttpStatusCode::NotImplemented); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int BadGateway", (void*)&HttpStatusCode::BadGateway); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int ServiceUnavailable", (void*)&HttpStatusCode::ServiceUnavailable); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int GatewayTimeout", (void*)&HttpStatusCode::GatewayTimeout); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int HTTPVersionNotSupported", (void*)&HttpStatusCode::HTTPVersionNotSupported); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int VariantAlsoNegotiates", (void*)&HttpStatusCode::VariantAlsoNegotiates); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int InsufficientStorage", (void*)&HttpStatusCode::InsufficientStorage); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int LoopDetected", (void*)&HttpStatusCode::LoopDetected); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NotExtended", (void*)&HttpStatusCode::NotExtended); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NetworkAuthenticationRequired", (void*)&HttpStatusCode::NetworkAuthenticationRequired); assert(r >= 0);
			r = scriptingService.scriptEngine->RegisterGlobalProperty("const int NetworkConnectTimeoutError", (void*)&HttpStatusCode::NetworkConnectTimeoutError); assert(r >= 0);

			r = scriptingService.scriptEngine->SetDefaultNamespace("");
		}
	}
}
