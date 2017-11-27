#include "distro.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string  path;
    string  line;

    Distro **list = new *Distro[50];

    cout << "Enter the path to the file: ";
    getline( cin, path );

    fstream distFile( path );

    if( !distFile )
    {
        cout << "You either entered the incorrect path, the file does not"
             << "exist, or your do not have read/write permissions on the file"
             << endl;

        return -1;
    }

    while( getline( distFile, line ) )
    {
        list[getCount()] = new Distro( strtok( line, "|\n\0" ), strtok( line, "|\n\0" ),
                                       strtok( line, "|\n\0" ), strtok( line, "|\n\0" ));

        cout << "[DEBUG] " << count << " :: " << *list[ getCount() ] << endl;
    }
}


