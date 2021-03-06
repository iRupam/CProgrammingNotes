/*

     endian.c
     Used to help determine if your arcitecture is of big endian or little
     endian design.  This determines how data is stored in memory.
     Written by Matthew Campbell for the C Programming group.  (12-12-17)

*/

#include <stdio.h>

/*

     Use LIST_SIZE to set the number of numbers that you wish to display.
     Use REVERSE to display the character string in the reverse order.

*/

#define LIST_SIZE 11
#define REVERSE

char *show_binary( unsigned char byte );

/*

     Make sure LIST_SIZE matches the number of elements you put in
     the list array when defined below as a local variable in main().

*/

int main( void )
{
     char *ptr;
     int count, pos, size;
     int list[ LIST_SIZE ] = { 1, 128, 129, 255, 256, 257, 65535, 65536, 16777216,
                                              2147483647, ( -1 ) };
     union
     {
          int num;
          unsigned char str[ sizeof( int ) ];
     } mix;

     size = sizeof( int );
     printf( "sizeof( int ): %d, sizeof( char * ): %d\n", size, sizeof( char * ) );
     for( pos = 0; pos < LIST_SIZE; pos++ )
     {
          mix.num = list[ pos ];
          printf( "\nmix.num: %d\n binary: ", mix.num );

#ifdef REVERSE
          for( count = ( size - 1 ); count >= 0; count-- )
#else
          for( count = 0; count < size; count++ )
#endif
          {
               printf( "%s  ", show_binary( mix.str[ count ] ) );
          }
          printf( "\naddress: " );

#ifdef REVERSE
          for( count = ( size - 1 ); count >= 0; count-- )
#else
          for( count = 0; count < size; count++ )
#endif
          {
               ptr = &mix.str[ count ];
               printf( "%Xh ", ptr );
          }
          printf( "\n" );
     }
     return 0;
}

char *show_binary( unsigned char byte )
{
     static char output[ 9 ];
     int count;

     for( count = 0; count < 8; count++ )
     {
          output[ count ] = 48;  /* ASCII '0' */
     }
     output[ 8 ] = 0;
     if ( byte & 1 ) 
     {
          output[ 7 ] = 49;
     }
     if ( byte & 2 )
     {
          output[ 6 ] = 49;
     }
     if ( byte & 4 )
     {
          output[ 5 ] = 49;
     }
     if ( byte & 8 )
     {
          output[ 4 ] = 49;
     }
     if ( byte & 16 )
     {
          output[ 3 ] = 49;
     }
     if ( byte & 32 )
     {
          output[ 2 ] = 49;
     }
     if ( byte & 64 )
     {
          output[ 1 ] = 49;
     }
     if ( byte & 128 )
     {
          output[ 0 ] = 49;
     }
     return output;
}

/* EOF endian.c */
