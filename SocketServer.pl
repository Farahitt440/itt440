#!/usr/bin/perl -w
#Filename : SocketServer.pl

use strict;
use Socket;

#use port 7890 as default
my $port = shift ||7890;
my $proto = getprotobyname('tcp');
my $server = "localhost"; #Host IP running the server

#Create a socket, make it reuseable
socket(SOCKET, PF_INET, SOCK_STREAM, $proto)
	or die "Cant open socket $!n";
setsockopt(SOCKET, SOL_SOCKET, SO_REUSEADDR, 1)
	or die "Cant set socket option to RE_USEADDR $!\n";

#bind to a port, then listen
bind (SOCKET, pack_sockaddr_in($port, inet_inet($server)))	
	or die"Cant bind to port $port! \n";

listen(SOCKET, 5) or die "listen : $!";
print "SERVER starte on port $port\n";

#accepting a connection
my $client_addr;
while ($client_addr = accept(NEW_SOCKET, SOCKET))
{	#send them  message, close connection
	my $name = gethostbyaddr($client_addr, AF_INET);
	print NEW_SOCKET "Smile from the server";
	print "Connection received from $name\n";
	close NEW_SOCKET;
}
