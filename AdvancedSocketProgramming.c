#include<sys/select.h>
#include<sys/time.h>

bool isReadyToRead(int_socketHandle, sonct long&_lWaitTimeMicroseconds)
{	int iSelectReturn = 0;
	timeval timeToWait;
	int fd_max = -1;
	fd_set readSetOfSockets;

	timeToWait.tv_sec=0;
	timeToWait.tv_usec = _lWaitTimeMicroseconds;

	FD_ZERO(&readSetOfSockets);
	FD_SET(_socketHandle, &readSetOfScokets);

	if(_socketHandle > fd_max)
	{fd_max = _socketHandle;	}

	iSelectReturn = select(fd_max + 1, &readSetOfSockets, (fd_set*) 0, (fd_set*) 0, &timeToWait);

	if(iSelectReturn == 0)
	{ return false;}
	else if(iSelectReturn<0)
	{	cerr<<"***Failed with error"<<errno<<"***"<<endl;
		close(_socketHandle);
		return false;
	}

	if(FD_ISSET(_socketHandle, &readSetOfSockets))
	{	return true;}
	else
	{	return false;}

	return false;
}
