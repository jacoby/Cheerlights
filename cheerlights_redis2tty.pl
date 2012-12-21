#!/usr/bin/perl

use 5.010 ;
use strict ;
use warnings ;
use Data::Dumper ;
use Carp ;
use Cwd ;
use Redis ;
use Device::SerialPort ;
use LWP::UserAgent ;
use JSON ;
$|++ ;

# every second
#   check redis for current color
#   write output to tty

my $portvalue = '/dev/ttyACM0' ;
my $port      = Device::SerialPort->new( "$portvalue" ) ;

$port->databits( 8 ) ;
$port->baudrate( 9600 ) ;
$port->parity( "none" ) ;
$port->stopbits( 1 ) ;
sleep 3 ;

while ( 1 ) {

    my $r = Redis->new() ;
    my $color = $r->get( 'color' ) ;
    $r->set( 'color', $color ) ;
    $port->write( $color ) ;
    $r->quit ;
    sleep 1 ;
    }
