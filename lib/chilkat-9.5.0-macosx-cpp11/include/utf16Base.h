
#ifndef _UTF16BASE_H_CHILKAT_
#define _UTF16BASE_H_CHILKAT_

#define PREP_RESULT_STRING int idx = nextIdx(); \
	if (!m_pResultString[idx]) return 0; \
	m_pResultString[idx]->clear();
 	
#define RESULT_STRING_OBJ (*(m_pResultString[idx]))

#define RTN_RESULT_STRING return rtnUtf16(m_pResultString[idx]);

#define CREATE_CLS_BASE \
    CLS_BASE_CLASS *pImpl = CLS_BASE_CLASS::createNewCls(); \
    m_impl = (void *) pImpl; \
    ClsBase *pBase = pImpl; \
    m_base = pBase;

#define USE_CLS_BASE \
    CLS_BASE_CLASS *pImpl = (CLS_BASE_CLASS *)impl; \
    if (!pImpl) pImpl = CLS_BASE_CLASS::createNewCls(); \
    m_impl = pImpl; \
    ClsBase *pBase = pImpl; \
    m_base = pBase;


#endif

