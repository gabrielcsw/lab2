#ifndef player_H
#define player_H

#include <string>
using std::string;

#include <ostream>
using std::ostream;

class player {
    private:
        string nome;
        int total;
        bool parar;
        bool perdeu;
    public: 
        player ();  
        string getNome ();
        void setNome (string n);
        int getTotal ();
        void setTotal (int t);
        bool getParar ();
        void setParar (bool p);
        bool getperdeu ();
        void setperdeu (bool e);
        friend ostream& operator << (ostream &os, player &j);
        player& operator = (player const &j);
};

#endif
