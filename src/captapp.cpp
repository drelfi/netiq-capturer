
#include "capturer.h"
#include <iostream>
#include <exception>

#include <signal.h>

using namespace std;

bool signaled = false;

void signal_handler(int signum)
{
    cout << "Signal captured. Stopping system..." << endl;
    signaled = true;
}

int main( int argc, char **argv ) {

    
    try {
        shared_ptr<Capturer> c(NULL);

        signal(SIGINT, signal_handler);

        if ( argc > 1 ) {
            c = shared_ptr<Capturer>(new Capturer(argv[1]));
        }
        else {
            c = shared_ptr<Capturer>(new Capturer());
        }

        c->open_device();
        while ( !signaled ) {
            cout << c->getPacketJson() << endl;
        }
    } catch ( logic_error &e ) {
        cerr << e.what() << endl;
    }

};
