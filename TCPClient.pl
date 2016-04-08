#!/usr/bin/perl -w

use strict;
use IO::Socket::INET;

my $server = shift; ## If this were remote it would be an IP, but locally now
my $port = shift; ## Same as before

my $socket = IO::Socket::INET->new(
	PeerAddr	=>$server,
	PeerPort	=>$port,
	Proto		=> 'tcp') || die "[!] Can not connect to $server;

print "Establishing connection to $server:$port\n";

## Our interactive loop
while (<STDIN>){
	print $socket $-;
	print scalar <$socket>;
}
close $socket || die "[!] Can not close connection...\n";
