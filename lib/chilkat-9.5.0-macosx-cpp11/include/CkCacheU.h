// CkCacheU.h: interface for the CkCacheU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkCacheU_H
#define _CkCacheU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkUtf16Base.h"

class CkDateTimeU;
class CkByteData;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkCacheU
class CK_VISIBLE_PUBLIC CkCacheU  : public CkUtf16Base
{
    private:
	

	// Don't allow assignment or copying these objects.
	CkCacheU(const CkCacheU &);
	CkCacheU &operator=(const CkCacheU &);

    public:
	CkCacheU(void);
	virtual ~CkCacheU(void);

	static CkCacheU *createNew(void);
	

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	

	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// The ETag of the last item fetched from cache.
	void get_LastEtagFetched(CkString &str);
	// The ETag of the last item fetched from cache.
	const uint16_t *lastEtagFetched(void);

	// Expiration date/time of the last item fetched from cache.
	void get_LastExpirationFetched(SYSTEMTIME &outSysTime);

	// Expiration date/time of the last item fetched from cache in RFC822 string
	// format.
	void get_LastExpirationFetchedStr(CkString &str);
	// Expiration date/time of the last item fetched from cache in RFC822 string
	// format.
	const uint16_t *lastExpirationFetchedStr(void);

	// true if the LastExpirationFetched is before the current date/time. Otherwise
	// false.
	bool get_LastHitExpired(void);

	// The key of the last item fetched from cache. (For web pages, the key is
	// typically the canonicalized URL. Otherwise, the key is a unique identifer used
	// to access the cached item.)
	void get_LastKeyFetched(CkString &str);
	// The key of the last item fetched from cache. (For web pages, the key is
	// typically the canonicalized URL. Otherwise, the key is a unique identifer used
	// to access the cached item.)
	const uint16_t *lastKeyFetched(void);

	// The number of directory levels in the cache. Possible values are:
	// 
	//     0: All cache files are in a single directory (the cache root).
	// 
	//     1: Cache files are located in 256 sub-directories numbered 0 .. 255 directly
	//     under the cache root.
	// 
	//     2: There are two levels of sub-directories under the cache root. The 1st
	//     level has 256 sub-directories numbered 0 .. 255 directly under the cache root.
	//     The 2nd level allows for up to 256 sub-directories (0..255) under each level-1
	//     directory. Cache files are stored in the leaf directories.
	// 
	int get_Level(void);
	// The number of directory levels in the cache. Possible values are:
	// 
	//     0: All cache files are in a single directory (the cache root).
	// 
	//     1: Cache files are located in 256 sub-directories numbered 0 .. 255 directly
	//     under the cache root.
	// 
	//     2: There are two levels of sub-directories under the cache root. The 1st
	//     level has 256 sub-directories numbered 0 .. 255 directly under the cache root.
	//     The 2nd level allows for up to 256 sub-directories (0..255) under each level-1
	//     directory. Cache files are stored in the leaf directories.
	// 
	void put_Level(int newVal);

	// The number of root directories composing the cache. A typical multi-root cache
	// would place each root on a separate hard drive.
	int get_NumRoots(void);



	// ----------------------
	// Methods
	// ----------------------
	// Must be called once for each cache root. For example, if the cache is spread
	// across D:\cacheRoot, E:\cacheRoot, and F:\cacheRoot, an application would setup
	// the cache object by calling AddRoot three times -- once with "D:\cacheRoot",
	// once with "E:\cacheRoot", and once with "F:\cacheRoot".
	void AddRoot(const uint16_t *path);

	// Deletes all items in the cache. This method completely clears the cache. All
	// files in the cache are deleted. (If the cache is multi-level, existing
	// sub-directories are not deleted.)
	// 
	// Returns the number of items (i.e. cache files) deleted.
	// 
	int DeleteAll(void);

	// Deletes all expired items from the cache.
	// 
	// Returns the number of items (i.e. cache files) deleted.
	// 
	int DeleteAllExpired(void);

	// Deletes a single item from the disk cache. Returns false if the item exists in
	// cache but could not be deleted. Otherwise returns true.
	bool DeleteFromCache(const uint16_t *key);

	// Deletes all items older than a specified date/time.
	// 
	// Returns the number of items (i.e. cache files) deleted. Returns -1 on error.
	// 
	int DeleteOlder(SYSTEMTIME &dateTime);

	// The same as DeleteOlder, except the dateTime is passed as a CkDateTime.
	int DeleteOlderDt(CkDateTimeU &dateTime);

	// The same as DeleteOlder, except the dateTimeStr is passed as a date/time in RFC822
	// format.
	int DeleteOlderStr(const uint16_t *dateTimeStr);

	// Fetches an item from cache.
	// 
	// The key may be any length and may include any characters. It should uniquely
	// identify the cached item. (No two items in the cache should have the same key.)
	// 
	bool FetchFromCache(const uint16_t *key, CkByteData &outBytes);

	// Fetches a text item from the cache and returns it's text content.
	// 
	// The key may be any length and may include any characters. It should uniquely
	// identify the cached item. (No two items in the cache should have the same key.)
	// 
	bool FetchText(const uint16_t *key, CkString &outStr);
	// Fetches a text item from the cache and returns it's text content.
	// 
	// The key may be any length and may include any characters. It should uniquely
	// identify the cached item. (No two items in the cache should have the same key.)
	// 
	const uint16_t *fetchText(const uint16_t *key);

	// Returns the eTag for an item in the cache.
	bool GetEtag(const uint16_t *key, CkString &outStr);
	// Returns the eTag for an item in the cache.
	const uint16_t *getEtag(const uint16_t *key);
	// Returns the eTag for an item in the cache.
	const uint16_t *etag(const uint16_t *key);

	// Returns the expire date/time for an item in the cache.
	bool GetExpiration(const uint16_t *key, SYSTEMTIME &outSysTime);

	// Returns the expiration date/time for an item in the cache as a CkDateTime
	// object.
	// The caller is responsible for deleting the object returned by this method.
	CkDateTimeU *GetExpirationDt(const uint16_t *key);

	// Returns the expiration date/time for an item in the cache in RFC822 string
	// format.
	bool GetExpirationStr(const uint16_t *url, CkString &outStr);
	// Returns the expiration date/time for an item in the cache in RFC822 string
	// format.
	const uint16_t *getExpirationStr(const uint16_t *url);
	// Returns the expiration date/time for an item in the cache in RFC822 string
	// format.
	const uint16_t *expirationStr(const uint16_t *url);

	// Returns the absolute file path of the cache file associated with the key.
	bool GetFilename(const uint16_t *key, CkString &outStr);
	// Returns the absolute file path of the cache file associated with the key.
	const uint16_t *getFilename(const uint16_t *key);
	// Returns the absolute file path of the cache file associated with the key.
	const uint16_t *filename(const uint16_t *key);

	// Returns the directory path of the Nth cache root. (Indexing begins at 0.)
	bool GetRoot(int index, CkString &outStr);
	// Returns the directory path of the Nth cache root. (Indexing begins at 0.)
	const uint16_t *getRoot(int index);
	// Returns the directory path of the Nth cache root. (Indexing begins at 0.)
	const uint16_t *root(int index);

	// Returns true if the item is found in the cache, otherwise returns false.
	bool IsCached(const uint16_t *key);

	// Inserts or replaces an text item in the cache. The eTag is optional and may be
	// set to a zero-length string. Applications may use it as a place to save
	// additional information about the cached item. The key may be any length and may
	// include any characters. It should uniquely identify the cached item. (No two
	// items in the cache should have the same key.)
	bool SaveText(const uint16_t *key, SYSTEMTIME &expireDateTime, const uint16_t *eTag, const uint16_t *itemTextData);

	// The same as SaveText, except the expire date/time is passed as a CkDateTime
	// object.
	bool SaveTextDt(const uint16_t *key, CkDateTimeU &expireDateTime, const uint16_t *eTag, const uint16_t *itemTextData);

	// Inserts or replaces an text item in the cache with no expiration date/time. The
	// eTag is optional and may be set to a zero-length string. Applications may use it
	// as a place to save additional information about the cached item.
	bool SaveTextNoExpire(const uint16_t *key, const uint16_t *eTag, const uint16_t *itemTextData);

	// The same as SaveText, except the expire date/time is passed as a string in
	// RFC822 format.
	bool SaveTextStr(const uint16_t *key, const uint16_t *expireDateTime, const uint16_t *eTag, const uint16_t *itemTextData);

	// Inserts or replaces an item in the cache. The eTag is optional and may be set to
	// a zero-length string. Applications may use it as a place to save additional
	// information about the cached item. (The Chilkat HTTP component, when caching a
	// page, writes the eTag (entity-tag) from the HTTP response header to this field.)
	// 
	// The key may be any length and may include any characters. It should uniquely
	// identify the cached item. (No two items in the cache should have the same key.)
	// 
	bool SaveToCache(const uint16_t *key, SYSTEMTIME &expireDateTime, const uint16_t *eTag, CkByteData &itemData);

	// The same as SaveToCache, except the expire date/time is passed as a CkDateTime
	// object.
	bool SaveToCacheDt(const uint16_t *key, CkDateTimeU &expireDateTime, const uint16_t *eTag, CkByteData &itemData);

	// Inserts or replaces an item in the cache. The cached item will have no
	// expiration. The eTag is optional and may be set to a zero-length string.
	// Applications may use it as a place to save additional information about the
	// cached item.
	bool SaveToCacheNoExpire(const uint16_t *key, const uint16_t *eTag, CkByteData &itemData);

	// The same as SaveToCache, except the expire date/time is passed in RFC822 string
	// format.
	bool SaveToCacheStr(const uint16_t *key, const uint16_t *expireDateTime, const uint16_t *eTag, CkByteData &itemData);

	// Updates the expire date/time for a cached item.
	bool UpdateExpiration(const uint16_t *key, SYSTEMTIME &expireDateTime);

	// The same as UpdateExpiration, except the expireDateTime is passed as a CkDateTime.
	bool UpdateExpirationDt(const uint16_t *key, CkDateTimeU &expireDateTime);

	// The same as UpdateExpiration, except the expireDateTime is passed in RFC822 string format.
	bool UpdateExpirationStr(const uint16_t *key, const uint16_t *expireDateTime);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
