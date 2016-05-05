!/usr/bin/perl -w
#Filename : SocketClient.pl

use strict;
use socket;

#initialize host and port
my $host = shift ||'localhost';
my $port = shift || 7890;
my $server = "localhost";

#create the socket, connect to the port
socket(SOCKET, PF_INET, SOCK_STREAM, (getprotobyname('tcp'))[2])
	or die"Cant create a socket$!\n";
connect (SOCKET, pack_sockaddr_in($port, inet_aton($server)))
	or die "Cant connect to port $port\n";

my $line;
while ($line = <SOCKET>)
{	print "$line\n";	}

close SOCKET or die "close: $!";
