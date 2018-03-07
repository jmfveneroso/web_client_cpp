// CkScpU.h: interface for the CkScpU class.
//
//////////////////////////////////////////////////////////////////////

// This header is generated for Chilkat v9.5.0

#ifndef _CkScpU_H
#define _CkScpU_H
	
#include "chilkatDefs.h"

#include "CkString.h"
#include "CkClassWithCallbacksU.h"

class CkByteData;
class CkTaskU;
class CkSshU;
class CkBaseProgressU;



#if !defined(__sun__) && !defined(__sun)
#pragma pack (push, 8)
#endif
 

// CLASS: CkScpU
class CK_VISIBLE_PUBLIC CkScpU  : public CkClassWithCallbacksU
{
    private:
	bool m_cbOwned;

	// Don't allow assignment or copying these objects.
	CkScpU(const CkScpU &);
	CkScpU &operator=(const CkScpU &);

    public:
	CkScpU(void);
	virtual ~CkScpU(void);

	static CkScpU *createNew(void);
	

	CkScpU(bool bCallbackOwned);
	static CkScpU *createNew(bool bCallbackOwned);

	
	void CK_VISIBLE_PRIVATE inject(void *impl);

	// May be called when finished with the object to free/dispose of any
	// internal resources held by the object. 
	void dispose(void);

	CkBaseProgressU *get_EventCallbackObject(void) const;
	void put_EventCallbackObject(CkBaseProgressU *progress);


	// BEGIN PUBLIC INTERFACE

	// ----------------------
	// Properties
	// ----------------------
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	bool get_AbortCurrent(void);
	// When set to true, causes the currently running method to abort. Methods that
	// always finish quickly (i.e.have no length file operations or network
	// communications) are not affected. If no method is running, then this property is
	// automatically reset to false when the next method is called. When the abort
	// occurs, this property is reset to false. Both synchronous and asynchronous
	// method calls can be aborted. (A synchronous method call could be aborted by
	// setting this property from a separate thread.)
	void put_AbortCurrent(bool newVal);

	// This is the number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any SSH operation prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	int get_HeartbeatMs(void);
	// This is the number of milliseconds between each AbortCheck event callback. The
	// AbortCheck callback allows an application to abort any SSH operation prior to
	// completion. If HeartbeatMs is 0 (the default), no AbortCheck event callbacks
	// will fire.
	void put_HeartbeatMs(int newVal);

	// This property is only valid in programming environment and languages that allow
	// for event callbacks.
	// 
	// Sets the value to be defined as 100% complete for the purpose of PercentDone
	// event callbacks. The defaut value of 100 means that at most 100 event
	// PercentDone callbacks will occur in a method that (1) is event enabled and (2)
	// is such that it is possible to measure progress as a percentage completed. This
	// property may be set to larger numbers to get more fine-grained PercentDone
	// callbacks. For example, setting this property equal to 1000 will provide
	// callbacks with .1 percent granularity. For example, a value of 453 would
	// indicate 45.3% competed. This property is clamped to a minimum value of 10, and
	// a maximum value of 100000.
	// 
	int get_PercentDoneScale(void);
	// This property is only valid in programming environment and languages that allow
	// for event callbacks.
	// 
	// Sets the value to be defined as 100% complete for the purpose of PercentDone
	// event callbacks. The defaut value of 100 means that at most 100 event
	// PercentDone callbacks will occur in a method that (1) is event enabled and (2)
	// is such that it is possible to measure progress as a percentage completed. This
	// property may be set to larger numbers to get more fine-grained PercentDone
	// callbacks. For example, setting this property equal to 1000 will provide
	// callbacks with .1 percent granularity. For example, a value of 453 would
	// indicate 45.3% competed. This property is clamped to a minimum value of 10, and
	// a maximum value of 100000.
	// 
	void put_PercentDoneScale(int newVal);

	// The paths of the files uploaded or downloaded in the last call to SyncUploadTree
	// or SyncDownloadTree. The paths are listed one per line. In both cases (for
	// upload and download) each line contains the full local file path (not the remote
	// path).
	void get_SyncedFiles(CkString &str);
	// The paths of the files uploaded or downloaded in the last call to SyncUploadTree
	// or SyncDownloadTree. The paths are listed one per line. In both cases (for
	// upload and download) each line contains the full local file path (not the remote
	// path).
	const uint16_t *syncedFiles(void);
	// The paths of the files uploaded or downloaded in the last call to SyncUploadTree
	// or SyncDownloadTree. The paths are listed one per line. In both cases (for
	// upload and download) each line contains the full local file path (not the remote
	// path).
	void put_SyncedFiles(const uint16_t *newVal);

	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will only transfer files having a filename that matches any one of these
	// patterns.
	void get_SyncMustMatch(CkString &str);
	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will only transfer files having a filename that matches any one of these
	// patterns.
	const uint16_t *syncMustMatch(void);
	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will only transfer files having a filename that matches any one of these
	// patterns.
	void put_SyncMustMatch(const uint16_t *newVal);

	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will only traverse into a directory that matches any
	// one of these patterns.
	void get_SyncMustMatchDir(CkString &str);
	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will only traverse into a directory that matches any
	// one of these patterns.
	const uint16_t *syncMustMatchDir(void);
	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will only traverse into a directory that matches any
	// one of these patterns.
	void put_SyncMustMatchDir(const uint16_t *newVal);

	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will not transfer files having a filename that matches any one of these
	// patterns.
	void get_SyncMustNotMatch(CkString &str);
	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will not transfer files having a filename that matches any one of these
	// patterns.
	const uint16_t *syncMustNotMatch(void);
	// Can contain a wildcarded list of filename patterns separated by semicolons. For
	// example, "*.xml; *.txt; *.csv". If set, the SyncTreeUpload and SyncTreeDownload
	// methods will not transfer files having a filename that matches any one of these
	// patterns.
	void put_SyncMustNotMatch(const uint16_t *newVal);

	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will not traverse into a directory that matches any one
	// of these patterns.
	void get_SyncMustNotMatchDir(CkString &str);
	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will not traverse into a directory that matches any one
	// of these patterns.
	const uint16_t *syncMustNotMatchDir(void);
	// Can contain a wildcarded list of directory name patterns separated by
	// semicolons. For example, "a*; b*; c*". If set, the SyncTreeUpload and
	// SyncTreeDownload methods will not traverse into a directory that matches any one
	// of these patterns.
	void put_SyncMustNotMatchDir(const uint16_t *newVal);



	// ----------------------
	// Methods
	// ----------------------
	// Downloads a binary file from the SSH server and returns the contents.
	bool DownloadBinary(const uint16_t *remotePath, CkByteData &outBytes);

	// Creates an asynchronous task to call the DownloadBinary method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadBinaryAsync(const uint16_t *remotePath);

	// Downloads a file from the SSH server returns the contents in an encoded string
	// (using an encoding such as base64).
	bool DownloadBinaryEncoded(const uint16_t *remotePath, const uint16_t *encoding, CkString &outStr);
	// Downloads a file from the SSH server returns the contents in an encoded string
	// (using an encoding such as base64).
	const uint16_t *downloadBinaryEncoded(const uint16_t *remotePath, const uint16_t *encoding);

	// Creates an asynchronous task to call the DownloadBinaryEncoded method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadBinaryEncodedAsync(const uint16_t *remotePath, const uint16_t *encoding);

	// Downloads a file from the remote SSH server to the local filesystem.
	bool DownloadFile(const uint16_t *remotePath, const uint16_t *localPath);

	// Creates an asynchronous task to call the DownloadFile method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadFileAsync(const uint16_t *remotePath, const uint16_t *localPath);

	// Downloads a text file from the SSH server and returns the contents as a string.
	bool DownloadString(const uint16_t *remotePath, const uint16_t *charset, CkString &outStr);
	// Downloads a text file from the SSH server and returns the contents as a string.
	const uint16_t *downloadString(const uint16_t *remotePath, const uint16_t *charset);

	// Creates an asynchronous task to call the DownloadString method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *DownloadStringAsync(const uint16_t *remotePath, const uint16_t *charset);

	// Downloads files from the SSH server to a local directory tree. Synchronization
	// modes include:
	// 
	//     mode=0: Download all files
	//     mode=1: Download all files that do not exist on the local filesystem.
	//     mode=2: Download newer or non-existant files.
	//     mode=3: Download only newer files. If a file does not already exist on the
	//     local filesystem, it is not downloaded from the server.
	//     mode=5: Download only missing files or files with size differences.
	//     mode=6: Same as mode 5, but also download newer files.
	//     
	// 
	bool SyncTreeDownload(const uint16_t *remoteRoot, const uint16_t *localRoot, int mode, bool bRecurse);

	// Creates an asynchronous task to call the SyncTreeDownload method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *SyncTreeDownloadAsync(const uint16_t *remoteRoot, const uint16_t *localRoot, int mode, bool bRecurse);

	// Uploads a directory tree from the local filesystem to the SSH server.
	// Synchronization modes include:
	// 
	//     mode=0: Upload all files
	//     mode=1: Upload all files that do not exist on the FTP server.
	//     mode=2: Upload newer or non-existant files.
	//     mode=3: Upload only newer files. If a file does not already exist on the FTP
	//     server, it is not uploaded.
	//     mode=4: transfer missing files or files with size differences.
	//     mode=5: same as mode 4, but also newer files.
	// 
	bool SyncTreeUpload(const uint16_t *localBaseDir, const uint16_t *remoteBaseDir, int mode, bool bRecurse);

	// Creates an asynchronous task to call the SyncTreeUpload method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *SyncTreeUploadAsync(const uint16_t *localBaseDir, const uint16_t *remoteBaseDir, int mode, bool bRecurse);

	// Uploads binary data to a file on the SSH server.
	bool UploadBinary(const uint16_t *remotePath, CkByteData &binData);

	// Creates an asynchronous task to call the UploadBinary method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UploadBinaryAsync(const uint16_t *remotePath, CkByteData &binData);

	// Uploads the binary data to a file on the remote SSH server. The binary data is
	// passed in encoded string representation (such as base64, or hex).
	bool UploadBinaryEncoded(const uint16_t *remotePath, const uint16_t *encodedData, const uint16_t *encoding);

	// Creates an asynchronous task to call the UploadBinaryEncoded method with the
	// arguments provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UploadBinaryEncodedAsync(const uint16_t *remotePath, const uint16_t *encodedData, const uint16_t *encoding);

	// Uploads a file from the local filesystem to the remote SSH server.
	bool UploadFile(const uint16_t *localPath, const uint16_t *remotePath);

	// Creates an asynchronous task to call the UploadFile method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UploadFileAsync(const uint16_t *localPath, const uint16_t *remotePath);

	// Uploads the contents of a string to a file on the remote SSH server.
	bool UploadString(const uint16_t *remotePath, const uint16_t *textData, const uint16_t *charset);

	// Creates an asynchronous task to call the UploadString method with the arguments
	// provided. (Async methods are available starting in Chilkat v9.5.0.52.)
	// The caller is responsible for deleting the object returned by this method.
	CkTaskU *UploadStringAsync(const uint16_t *remotePath, const uint16_t *textData, const uint16_t *charset);

	// Uses the SSH connection of sshConnection for the SCP transfers. All of the connection and
	// socket related properties, proxy properites, timeout properties, session log,
	// etc. set on the SSH object apply to the SCP methods (because internally it is
	// the SSH object that is used to do the work of the file transfers).
	// 
	// Note: There is no UnlockComponent method in the SCP class because it is the SSH
	// object that must be unlocked. When the SSH object is not unlocked, this method
	// will return false to indicate failure.
	// 
	bool UseSsh(CkSshU &sshConnection);





	// END PUBLIC INTERFACE


};
#if !defined(__sun__) && !defined(__sun)
#pragma pack (pop)
#endif


	
#endif
