
#include <string>
#include <pcap.h>

class Capturer {

    public:
        Capturer(std::string device = "");
        ~Capturer();

        void open_device();

        std::string getPacketJson();

    protected:

        std::string device;
        pcap_t *handler;

        /* Support to pcap lib */
        char errbuf[PCAP_ERRBUF_SIZE];

};
