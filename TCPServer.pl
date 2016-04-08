#!/usr/bin/perl -w
## -w enables warnings

use strict;
use IO::Socket::INET;

my $port = shift || die "[!] No port given...\n";; ## Value given from terminal
my $socket = IO::Socket::INET->new(
	LocalPort => $port, ## The connection will stay local
	Proto => 'tcp',
	Listen => SOMAXCONN ) || die "[!] Can not established Socket...\n";;

print "Listening for connectionson $port\n";
## While loop to accept connectons
while (my $client = $socket->accept){
	my $addr = gethostbyaddr($client->peeraddr, AF_INET);
	my $port = $client->peersupport;
	while (<$client>) {
		print "[Client:$port] $_"; #Print the client port and the message received
		print $client "$.: $_";
	}
	close $client || die "[!] Connection unable to close...\n";
	die "[!] Can not connect $!\n";
}
