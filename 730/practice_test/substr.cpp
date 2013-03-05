#include <iostream>
#include <string>

using namespace std;

string getSubSequence( string t, string s )
{
	string subSeq; 
	string ret;
	int t_i = 0;
	int s_i = 0;

	for( ; t_i < t.length(); t_i++ ) 
	{
		for( int i = t_i; i < t.length(); i++ )
		{
			for( int j = s_i; j < s.length(); j++ )
			{
				if( t[i] == s[j] )
				{
					s_i = j + 1;
					subSeq.push_back( t[i] );
					break;
				}
			}
		}
		if( subSeq.length() > ret.length() )
		{
			ret = subSeq;
		}
		subSeq.clear();
		s_i = 0;
	}
	return ret;
}

int main()
{
	cout << getSubSequence( string( "CGAACT" ), string( "AACGACTGC" ) );
	cout << endl;

	return 0;
}
