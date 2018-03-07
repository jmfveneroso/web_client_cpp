#ifndef _CkClassWithCallbacksU_H
#define _CkClassWithCallbacksU_H
#pragma once

#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif

#include "CkUtf16Base.h"

class CkString;

class CK_VISIBLE_PUBLIC CkClassWithCallbacksU : public CkUtf16Base
{
    protected:
	void *m_callback;
	int m_callbackObjType;

    public:
	    
	CkClassWithCallbacksU(void);
	virtual ~CkClassWithCallbacksU(void);
    
	// These methods are for internal use only.
	void _setEventCallbackObj(void *p, int objType);
	void *_getEventCallbackObj(void);


};

#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


#endif
	
