// The thing I like and would like to keep track off

#include <string>

using namespace std;

class Distro
{
    protected:
        string name, type, pkgmgr, ver;

        static int count;

    public:

        // constructors
    
        Distro();
        Distro(string nm, string typ, string mgr, string vr);

        // methods

        void setName ( string nme );
        void setType ( string typ );
        void setPkg  ( string mgr );
        void setVer  ( string vr  );

        string getName() const;
        string getType() const;
        string getPkg () const;
        string getVer () const;
        
        int getCount() const;

        // operator overloads
    
        friend ostream &operator<<( ostream &stream, Distro dist );

        friend bool operator==( Distro dist1, Distro dist2 );
};
