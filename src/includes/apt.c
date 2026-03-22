/*
  apt.c _ Applet/NS shell interaction
*/

#include <string.h>
#include <3ds/result.h>
#include <3ds/svc.h>
#include <3ds/srv.h>
#include <3ds/ipc.h>

static Handle aptLockHandle;


static Result aptGetServiceHandle(Handle* aptuHandle)
{
	static const char* serviceName;
	static const char* const serviceNameTable[3] = {"APT:S", "APT:A", "APT:U"};

	if (serviceName)
		return srvGetServiceHandleDirect(aptuHandle, serviceName);

	Result ret;
	int i;
	for (i = 0; i < 3; i ++)
	{
		ret = srvGetServiceHandleDirect(aptuHandle, serviceNameTable[i]);
		if (R_SUCCEEDED(ret))
		{
			serviceName = serviceNameTable[i];
			break;
		}
	}

	return ret;
}

static inline int countPrmWords(u32 hdr)
{
	return 1 + (hdr&0x3F) + ((hdr>>6)&0x3F);
}

Result aptSendCommand(u32* aptcmdbuf)
{
	Handle aptuHandle;

	if (aptLockHandle) svcWaitSynchronization(aptLockHandle, U64_MAX);
	Result res = aptGetServiceHandle(&aptuHandle);
	if (R_SUCCEEDED(res))
	{
		u32* cmdbuf = getThreadCommandBuffer();
		memcpy(cmdbuf, aptcmdbuf, 4*countPrmWords(aptcmdbuf[0]));
		res = svcSendSyncRequest(aptuHandle);
		if (R_SUCCEEDED(res))
		{
			memcpy(aptcmdbuf, cmdbuf, 4*countPrmWords(cmdbuf[0]));
			res = aptcmdbuf[1];
		}
		svcCloseHandle(aptuHandle);
	}
	if (aptLockHandle) svcReleaseMutex(aptLockHandle);
	return res;
}

static Result APT_CheckNew3DS_System(bool* out)
{
	u32 cmdbuf[16];
	cmdbuf[0]=IPC_MakeHeader(0x102,0,0); // 0x1020000

	Result ret = aptSendCommand(cmdbuf);
	if (R_SUCCEEDED(ret))
		*out = cmdbuf[2] & 0xFF;

	return ret;
}

Result APT_CheckNew3DS(bool* out)
{
	static bool flagInit, flagValue;
	if (!flagInit)
	{
		*out = false;
		Result ret = APT_CheckNew3DS_System(&flagValue);
		if (R_FAILED(ret)) return ret;
		flagInit = true;
	}

	*out = flagValue;
	return 0;
}