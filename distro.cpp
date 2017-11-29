// Defines the distro class

#include "distro.h"
#include <iostream>

// default constructor
Distro::Distro()
{
    name    = "";
    type    = "";
    pkgmgr  = "";
    ver     = "";

    ++count;
}

// overloaded constructor
Distro::Distro( string nm, string typ, string mgr, string vr )
{
    name    = nm;
    type    = typ;
    pkgmgr  = mgr;
    ver     = vr;

    ++count;
}

// setter for name
void Distro::setName( string nm )
{
    name = nm;
}

// setter for type
void Distro::setType( string typ )
{
    type = typ;
}

// setter for package manager
void Distro::setPkg( string mgr )
{
    pkgmgr = mgr;
}

// setter for software version
void Distro::setVer( string vr )
{
    ver = vr;
}

// getter for name
string Distro::getName() const
{
    return name;
}

// getter for type
string Distro::getType() const
{
    return type;
}

// getter for package manager
string Distro::getPkg() const
{
    return pkgmgr;
}

// getter for version
string Distro::getVer() const
{
    return ver;
}

// count of instances
int Distro::count = 0;

int Distro::getCount() const
{
    return count;
}

ostream &operator<<( ostream &stream, Distro dist)
{
    stream  << "Name:\t\t\t" << dist.name 
            << "\nType:\t\t\t" << dist.type 
            << "\nPackage Manager:\t" << dist.pkgmgr
            << "\nVersion:\t\t" << dist.ver << "\n"
            << endl;
}

bool operator==( Distro &dist1, Distro &dist2 ) 
{
    if( dist1.getName() == dist2.getName())
    {
        if( dist1.getVer() == dist2.getVer())
            return true;
        else 
            return false;
    }
    /*
    if( name == dist.name )
    {
        if( ver == dist.ver )
            return true;
        else return false;
    }
    */
    else 
        return false;
}

