#include "distro.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void append     ( Distro **list, fstream &distFile );
void buildList  ( Distro **list, fstream &distFile );
void displayList( Distro **list );

//Broken
bool duplicate  ( Distro **list, Distro dist );

int main()
{
    string  path;

    fstream distFile;

    Distro **list = new Distro*[ 50 ];

    while( true )
    {
        cout << "\nEnter the path to the file: ";
        getline( cin, path );

        distFile.open( path );

        if( !distFile )
        {
            cout << "\nYou either entered the incorrect path, the file does not"
                 << "exist, or your do not have read/write permissions on the file"
                 << " or the directory " << endl;
        }
        else 
        {
            buildList( list, distFile );
            distFile.close();
            break;
        }
    }

    int input;

    while( true )
    {
        cout << "\n1.\tDisplay list \n2.\tAdd Entry \n3.\tQuit"
             << "\nWhat do you want to do?: " << endl;
        cin >> input;

        cin.clear();

        switch( input )
        {
           case 1:
                displayList( list );
                break;

            case 2:
                distFile.open( path, ios::app );

                if( !distFile  )
                    cout << "There was an error, opening the file.";
                else
                    append( list, distFile );

                distFile.close();
                break;

            case 3:
                // cleanup
                for( int i = 0; i < Distro::count; i++ )
                    delete list[i];

                delete list;

                cout << "Exiting!" << endl;

                return 0;

            default:
                cout << "Not a valid response!" << endl;
        }
    }
    
   
}


void append( Distro **list, fstream &distFile )
{
    int exit;

    string line, name, type, pkgmgr, ver;


    while( true ) 
    {

        // TODO build in bounds checking

        cin.ignore();

        cout << "What is the name of the distribution?: ";
        getline( cin, name );

        cout << "What type of distribution is it [ Binary || Compiling ]: ";
        getline( cin, type );

        cout << "What is the name of the package manager?: ";
        getline( cin, pkgmgr ); 

        cout << "What is the current release version?: ";
        getline( cin, ver );

        // TODO build in test to make sure there are no duplicates
        list[ Distro::count -1 ] = new Distro( name, type, pkgmgr, ver );

        if( duplicate( list, *list[ Distro::count -1 ] ))
        {
            cout << "\nERROR: Duplicate entry, skiping." << endl;
            delete list[ Distro::count -1 ]; 
            --Distro::count;
        }
        else
        {
            line = name + "|" + type + "|" + pkgmgr + "|" + ver + "\n";
            distFile << line;
        }

        cout << "\nEntries: " << Distro::count << " out of 50" << endl;
        cout << "Press 1 to quit or other to enter another : ";
        cin >> exit;

        if( exit == 1 ) break;
    }    
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


bool duplicate( Distro **list, Distro dist )
{
    for( int i = 0; i < Distro::count; i++ )
    {
        if( *list[i] == dist )
            return true;
    }

    return false;
}
