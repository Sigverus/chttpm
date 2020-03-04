#pragma once



namespace chttpm
{
	// A collection of (somewhat) human readable constants for HTTP Status Codes
	namespace HttpStatusCode
	{
		const int Continue = 100;
		const int SwitchingProtocols = 101;
		const int Processing = 102;

		const int Ok = 200;
		const int Created = 201;
		const int Accepted = 202;
		const int NonAuthoritativeInformation = 203;
		const int NoContent = 204;
		const int ResetContent = 205;
		const int PartialContent = 206;
		const int MultiStatus = 207;
		const int AlreadyReported = 208;
		const int IMUsed = 226;

		const int MultipleChoices = 300;
		const int MovedPermanently = 301;
		const int Found = 302;
		const int SeeOther = 303;
		const int NotModified = 304;
		const int UseProxy = 305;
		const int TemporaryRedirect = 307;
		const int PermanentRedirect = 308;

		const int BadRequest = 400;
		const int Unauthorized = 401;
		const int PaymentRequired = 402;
		const int Forbidden = 403;
		const int NotFound = 404;
		const int MethodNotAllowed = 405;
		const int NotAcceptable = 406;
		const int ProxyAuthenticationRequired = 407;
		const int RequestTimeout = 408;
		const int Conflict = 409;
		const int Gone = 410;
		const int LengthRequired = 411;
		const int PreconditionFailed = 412;
		const int PayloadTooLarge = 413;
		const int RequestURITooLong = 414;
		const int UnsupportedMediaType = 415;
		const int RequestedRangeNotSatisfiable = 416;
		const int ExpectationFailed = 417;
		const int ImATeapot = 418;
		const int MisdirectedRequest = 421;
		const int UnprocessableEntity = 422;
		const int Locked = 423;
		const int FailedDependency = 424;
		const int UpgradeRequired = 426;
		const int PreconditionRequired = 428;
		const int TooManyRequests = 429;
		const int RequestHeaderFieldsTooLarge = 431;
		const int ConnectionClosedWithoutResponse = 444;
		const int UnavailableForLegalReasons = 451;
		const int ClientClosedRequest = 499;

		const int InternalServerError = 500;
		const int NotImplemented = 501;
		const int BadGateway = 502;
		const int ServiceUnavailable = 503;
		const int GatewayTimeout = 504;
		const int HTTPVersionNotSupported = 505;
		const int VariantAlsoNegotiates = 506;
		const int InsufficientStorage = 507;
		const int LoopDetected = 508;
		const int NotExtended = 510;
		const int NetworkAuthenticationRequired = 511;
		const int NetworkConnectTimeoutError = 599;
	}
}