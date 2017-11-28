#include "distro.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void append     ( Distro **list, fstream &distFile );
void buildList  ( Distro **list, fstream &distFile );
void displayList( Distro **list );

int main()
{
    string  path;

    fstream distFile;

    Distro **list = new Distro*[ 50 ];

    while( true )
    {
        cout << "Enter the path to the file: ";
        getline( cin, path );

        distFile.open( path );

        if( !distFile )
        {
            cout << "You either entered the incorrect path, the file does not"
                 << "exist, or your do not have read/write permissions on the file"
                 << " or the directory " << endl;

         }
        else break;
    }

    buildList( list, distFile );

    displayList( list );

    // cleanup

    distFile.close();

    for( int i = 0; i < Distro::count; i++ )
        delete list[i];

    delete list;

    return 0;

}


void append( Distro **list, fstream &distFile )
{
    // TODO build in bounds checking
    string name, type, pkgmgr, ver;

    cout << "What is the name of the distribution?: " << endl;
    getline( cin, name );

    cout << "What type of distribution is it [ Binary || Compiling ]: " << endl;
    getline( cin, type );

    cout << "What is the name of the package manager?: " << endl;
    getline( cin, pkgmgr ); 

    cout << "What is the current release version?: " << endl;
    getline( cin, ver );

    // TODO build in test to make sure there are no duplicates
    list[ Distro::count ] = new Distro( name, type, pkgmgr, ver );

    //distFile << name + "|" + type "|" + pkgmgr << "|" + ver + "\n";

    

}

void buildList( Distro **list, fstream &distFile )
{
    int beg, end, delim;
    string line, name, pkgmgr, type, ver;

    // TODO rewrite using strtok() and string::str_c()
    while( getline( distFile, line ))
    {
        beg   = 0;
        end   = line.length() - 1;
        delim = line.find( '|' );

        name = line.substr( 0, delim );

        beg   = ++delim;
        line  = line.substr( beg, end );
        delim = line.find( '|' );

        type = line.substr( 0, delim );

        beg   = ++delim;
        line  = line.substr( beg, end );
        delim = line.find( '|' );

        pkgmgr = line.substr( 0, delim );

        ver = line.substr( ++delim, end  );

        list[ Distro::count - 1 ] = new Distro( name, type, pkgmgr, ver );

        // debug
        // cout  << *list[ Distro::count ] << endl;
    }
}


void displayList( Distro **list )
{
    cout << "List Made: " << Distro::count << " objects"<< endl;

    for( int i = 0; i < Distro::count; i++ )
        cout << *list[ i ] << endl;
}
