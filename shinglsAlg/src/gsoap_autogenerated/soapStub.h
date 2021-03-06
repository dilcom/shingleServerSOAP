/* soapStub.h
   Generated by gSOAP 2.8.10 from ./shingle.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include <vector>
#include "stdsoap2.h"
#if GSOAP_VERSION != 20810
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_t__type
#define SOAP_TYPE_t__type (8)
/* t:type */
enum t__type {TEXT = 0, PROGRAMM_LANG_CPP = 1, PROGRAMM_LANG_PASCAL = 2, CLEAR_TEXT = 3};
#endif

#ifndef SOAP_TYPE_status
#define SOAP_TYPE_status (9)
/* status */
enum status {STATE_OK = 0, STATE_FAIL = 1, STATE_BASE_EMPTY = 2, STATE_NO_SIMILAR = 3};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_t__text
#define SOAP_TYPE_t__text (10)
/* t:text */
class SOAP_CMAC t__text
{
public:
	char *name;	/* optional element of type xsd:string */
	char *date;	/* optional element of type xsd:string */
	char *streamData;	/* optional element of type xsd:string */
	char *authorName;	/* optional element of type xsd:string */
	char *authorGroup;	/* optional element of type xsd:string */
	enum t__type type;	/* required element of type t:type */
	float similarity;	/* required element of type xsd:float */
	struct soap *creator;	/* transient */
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE_t__text */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         t__text() { t__text::soap_default(NULL); }

             t__text(const t__text & src) {
                 creator = src.creator;
                 name = (char*)(soap_malloc(creator, strlen(src.name) + 1));
                 strcpy(name, src.name);
                 authorName = (char*)(soap_malloc(creator, strlen(src.authorName) + 1));
                 strcpy(authorName, src.authorName);
                 authorGroup = (char*)(soap_malloc(creator, strlen(src.authorGroup) + 1));
                 strcpy(authorGroup, src.authorGroup);
                 streamData = (char*)(soap_malloc(creator, strlen(src.streamData) + 1));
                 strcpy(streamData, src.streamData);
                 date = (char*)(soap_malloc(creator, strlen(src.date) + 1));
                 strcpy(date, src.date);
                 similarity = src.similarity;
                 type = src.type;
             }
	virtual ~t__text() { }
};
#endif

#ifndef SOAP_TYPE_result
#define SOAP_TYPE_result (12)
/* result */
class SOAP_CMAC result
{
public:
	std::vector<t__text >arrayOfTexts;	/* optional element of type t:text */
	enum status errCode;	/* required element of type status */
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE_result */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         result() { result::soap_default(NULL); }
	virtual ~result() { }
};
#endif

#ifndef SOAP_TYPE_ns__CompareTextResponse
#define SOAP_TYPE_ns__CompareTextResponse (17)
/* ns:CompareTextResponse */
struct ns__CompareTextResponse
{
public:
	result *res;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type result */
};
#endif

#ifndef SOAP_TYPE_ns__CompareText
#define SOAP_TYPE_ns__CompareText (18)
/* ns:CompareText */
struct ns__CompareText
{
public:
	t__text *text;	/* optional element of type t:text */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (19)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (20)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (22)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (25)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (26)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
