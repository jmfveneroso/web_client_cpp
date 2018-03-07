#ifndef _CkUtf16Base_H
#define _CkUtf16Base_H
#pragma once

#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif

#include "CkObject.h"
#include "CkString.h"

class CkUtf16Base : public  CkObject
{
    private:
		
	// Disallow assignment or copying this object.
	CkUtf16Base(const CkUtf16Base &);
	CkUtf16Base &operator=(const CkUtf16Base &);

    protected:
	void *m_impl;	
	void *m_base;
	
	unsigned int m_resultIdx;
	CkString *m_pResultString[10];

	unsigned int nextIdx(void);

	const uint16_t *rtnUtf16(CkString *pStrObj);	

    public:
		
	CkUtf16Base();
	virtual ~CkUtf16Base();
	
	// BEGIN PUBLIC INTERFACE
	bool get_LastMethodSuccess(void);
	void put_LastMethodSuccess(bool newVal);

	bool get_VerboseLogging(void);
	void put_VerboseLogging(bool b);

	bool SaveLastError(const uint16_t *path);

	void LastErrorXml(CkString &str);
	void LastErrorHtml(CkString &str);
	void LastErrorText(CkString &str);

	void get_LastErrorXml(CkString &str) { LastErrorXml(str); }
	void get_LastErrorHtml(CkString &str) { LastErrorHtml(str); }
	void get_LastErrorText(CkString &str) { LastErrorText(str); }

	const uint16_t *lastErrorText(void);
	const uint16_t *lastErrorXml(void);
	const uint16_t *lastErrorHtml(void);

	void get_DebugLogFilePath(CkString &str);
	void put_DebugLogFilePath(const uint16_t *newVal);

	const uint16_t *debugLogFilePath(void);

	void get_Version(CkString &str);
	const uint16_t *version(void);

	// END PUBLIC INTERFACE

	void *getImpl(void) const;

	// The following method(s) should not be called by an application.
	// They for internal use only.
	void setLastErrorProgrammingLanguage(int v);

    };

#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif

#endif
	
