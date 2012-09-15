/* soapshingleService.cpp
   Generated by gSOAP 2.8.9 from shingleServer.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapshingleService.h"

ShingleService::ShingleService()
{	
	shingleService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ShingleService::ShingleService(const struct soap &_soap) : soap(_soap)
{ }

ShingleService::ShingleService(soap_mode iomode)
{	shingleService_init(iomode, iomode);
}

ShingleService::ShingleService(soap_mode imode, soap_mode omode)
{	shingleService_init(imode, omode);
}

ShingleService::~ShingleService()
{ }

void ShingleService::shingleService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL},
	{"SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"t", "http://tempuri.org/t.xsd", NULL, NULL},
	{"ns", "urn:shingle", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
};

void ShingleService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void ShingleService::reset()
{	destroy();
	soap_done(this);
	soap_init(this);
	shingleService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
ShingleService *ShingleService::copy()
{	ShingleService *dup = SOAP_NEW_COPY(ShingleService(*(struct soap*)this));
	return dup;
}
#endif

int ShingleService::soap_close_socket()
{	return soap_closesock(this);
}

int ShingleService::soap_force_close_socket()
{	return soap_force_closesock(this);
}

int ShingleService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int ShingleService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int ShingleService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int ShingleService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void ShingleService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void ShingleService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *ShingleService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void ShingleService::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *ShingleService::soap_header()
{	return this->header;
}

int ShingleService::run(int port)
{	if (soap_valid_socket(this->master) || soap_valid_socket(bind(NULL, port, 100)))
	{	for (;;)
		{	if (!soap_valid_socket(accept()) || serve())
				return this->error;
			soap_destroy(this);
			soap_end(this);
		}
	}
	else
		return this->error;
	return SOAP_OK;
}

SOAP_SOCKET ShingleService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET ShingleService::accept()
{	return soap_accept(this);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int ShingleService::ssl_accept()
{	return soap_ssl_accept(this);
}
#endif

int ShingleService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{

#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif

		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if (dispatch() || (this->fserveloop && this->fserveloop(this)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_ns__CompareText(ShingleService*);

int ShingleService::dispatch()
{	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "ns:CompareText"))
		return serve_ns__CompareText(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve_ns__CompareText(ShingleService *soap)
{	struct ns__CompareText soap_tmp_ns__CompareText;
	t__result res;
	res.soap_default(soap);
	soap_default_ns__CompareText(soap, &soap_tmp_ns__CompareText);
	soap->encodingStyle = "";
	if (!soap_get_ns__CompareText(soap, &soap_tmp_ns__CompareText, "ns:CompareText", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->CompareText(soap_tmp_ns__CompareText.text, &res);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	res.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || res.soap_put(soap, "t:result", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || res.soap_put(soap, "t:result", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
