#!/usr/bin/perl

use 5.010 ;
use strict ;
use warnings ;
use Carp ;
use Redis ;
use LWP::UserAgent ;
use JSON ;

# every 30 seconds
#   check to see if the source feed has changed
#   write output to redis

my $url      = "http://api.thingspeak.com/channels/1417/feed.json" ;
my $agent    = new LWP::UserAgent ;
my $request  = new HTTP::Request( 'GET', $url ) ;
my $response = $agent->request( $request ) ;
my $status   = $response->as_string ;
my $color ;
if ( $response->is_success ) {
    my $content = $response->content ;
    my $object  = decode_json( $content ) ;
    my @feeds =
        sort { $b->{ entry_id } <=> $a->{ entry_id } }
        @{ $object->{ feeds } } ;
    $color = $feeds[ 0 ]->{ field1 } ;
    }
my $r = Redis->new() ;
my $r_color = $r->get( 'color' ) || '' ;
if ( $color ne $r_color ) {
    $r->set( 'color', $color ) ;
    }
$r->quit ;
