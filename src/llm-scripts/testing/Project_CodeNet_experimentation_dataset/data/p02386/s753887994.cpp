#include <stdio.h>
#include <vector>

int judge( const int* number_table1 , const int* number_table2 )
{
	const int right_side_table[ 6 ][ 6 ] =
	{
		//front=
		// 1    2    3    4    5    6
		{ -1 ,  3 ,  5 ,  2 ,  4 , -1 },	//top=1
		{  4 , -1 ,  1 ,  6 , -1 ,  3 },	//2
		{  2 ,  6 , -1 , -1 ,  1 ,  5 },	//3
		{  5 ,  1 , -1 , -1 ,  6 ,  2 },	//4
		{  3 , -1 ,  6 ,  1 , -1 ,  4 },	//5
		{ -1 ,  4 ,  2 ,  5 ,  3 , -1 },	//6
	};

	for( int top = 0 ; top < 6 ; top++ )
	{
		for( int front = 0 ; front < 6 ; front++ )
		{
			int right = right_side_table[ top ][ front ] - 1;
			if( right < 0 )
			{
				continue;
			}
			if( number_table1[ 0 ] != number_table2[ top ] )
			{
				continue;
			}
			if( number_table1[ 1 ] != number_table2[ front ] )
			{
				continue;
			}
			if( number_table1[ 2 ] != number_table2[ right ] )
			{
				continue;
			}
			if( number_table1[ 3 ] != number_table2[ 5 - right ] )
			{
				continue;
			}
			if( number_table1[ 4 ] != number_table2[ 5 - front ] )
			{
				continue;
			}
			if( number_table1[ 5 ] != number_table2[ 5 - top ] )
			{
				continue;
			}
			return 1;
		}
	}
	return 0;
}

struct NumberTableEntry
{
	int table[ 6 ];
};
typedef std::vector<NumberTableEntry> NumberTable;

int main( int argc , char** argv )
{
	NumberTable number_table;

	int data_size;
	scanf( "%d" , &data_size );
	number_table.reserve( data_size );

	for( int i = 0 ; i < data_size ; i++ )
	{
		NumberTableEntry entry;
		scanf( "%d %d %d %d %d %d" ,
			&entry.table[ 0 ] ,
			&entry.table[ 1 ] ,
			&entry.table[ 2 ] ,
			&entry.table[ 3 ] ,
			&entry.table[ 4 ] ,
			&entry.table[ 5 ] );

		number_table.push_back( entry );
	}

	for( NumberTable::const_iterator itr = number_table.begin() ; itr != number_table.end() ; itr++ )
	{
		NumberTable::const_iterator itr2 = itr;
		itr2++;

		for( ; itr2 != number_table.end() ; itr2++ )
		{
			if( judge( &itr->table[ 0 ] , &itr2->table[ 0 ] ) )
			{
				printf( "No\n" );
				return 0;
			}
		}
	}
	printf( "Yes\n" );
	return 0;
}