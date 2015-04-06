
#include "capturer.h"
#include <iostream>
#include <exception>

using namespace std;

//string Capturer::device;
//pcap_t *Capturer::handler;


/* Support to pcap lib */
//char Capturer::errbuf[PCAP_ERRBUF_SIZE];


Capturer::Capturer(string device) : handler(NULL)
{
    if (device.length() == 0) {
        char *dev;
        dev = pcap_lookupdev(errbuf);

        if (dev == NULL) {
            throw invalid_argument("Couldn't find default device");
        }
        this->device = string(dev);
    }
    else
        this->device = device;

    cout << "Capturer created on " << this->device << endl;
}

Capturer::~Capturer()
{
    if ( handler ) {
        cout << "Closing dev..." << endl;
        pcap_close(handler);
    }
}


void Capturer::open_device() {
    this->handler = pcap_open_live( this->device.c_str(), BUFSIZ, 1, 1000, errbuf);

    if (this->handler == NULL) {
        throw logic_error(string("Couldn't open device: ") + errbuf );
    }
}

string Capturer::getPacketJson() 
{
    const u_char *packet;
    struct pcap_pkthdr header;

    packet = pcap_next(this->handler, &header);

    //ip = (struct sniff_ip *)(packet + SIZE_ETHERNET);

    cout << "Captured a packet of " << header.len << " bytes" << endl;

    return "";
}


