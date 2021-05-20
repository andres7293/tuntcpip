#include "IP.H"
#include "Utils.H"

uint8_t IP_Header::getVersion() {
    return ((this->version_headerlen & 0xf0) >> 4);
}

uint8_t IP_Header::getHeaderLen() {
    return (this->version_headerlen & 0x0f);
}

uint8_t IP_Header::getHeaderLenInBytes() {
    return this->getHeaderLen() * 4;
}

uint8_t IP_Header::getFlags() {
    return ((this->flags_fragoffset & 0xE000) >> 13);
}

uint8_t IP_Header::getFragmentOffset() {
    return (this->flags_fragoffset & 0x1FFF);
}

ostream& operator << (ostream& os, IP_Header &h) {
    os   << "IP_Header{"
         << "version_headerlen=0x" << hex << (int) h.version_headerlen << dec
         << ",tos=0x"              << hex << (int) h.tos               << dec
         << ",total_len=0x"        << hex << (int) h.total_len         << dec
         << ",id=0x"               << hex << (int) h.id                << dec
         << ",flags_fragoffset=0x" << hex << (int) h.flags_fragoffset  << dec
         << ",ttl=0x"              << hex << (int) h.ttl               << dec
         << ",protocol=0x"         << hex << (int) h.protocol          << dec
         << ",header_checksum=0x"  << hex << (int) h.header_checksum   << dec
         << ",src_addr=0x"         << hex << (int) h.src_addr          << dec
         << ",dst_addr=0x"         << hex << (int) h.dst_addr          << dec
         << "}";
    return os;
}
