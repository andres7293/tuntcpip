#include <gtest/gtest.h>
#include "../IPv4.H"

const uint8_t ip_header_raw[] = {0x45, 0x00, 0x00, 0x54, 0xf2, 0xc8, 0x40, 0x00, 0x40, 0x01, 0x49, 0xde, 0x7f, 0x00, 0x00, 0x01, 0x7f, 0x00, 0x00, 0x01, 0x08, 0x00, 0x4f, 0xff, 0x61, 0xfa, 0x00, 0x01, 0x8f, 0xe1, 0x7f, 0x60, 0x00, 0x00, 0x00, 0x00, 0x76, 0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37};

TEST(IP_Header, parse_header) {
    IP_Header ip_header;
    ip_header.parse((uint8_t *) ip_header_raw);

    ASSERT_EQ(4, ip_header.getVersion());
    ASSERT_EQ(5, ip_header.getHeaderLen());
    ASSERT_EQ(0, ip_header.header.tos);
    ASSERT_EQ(0xf2c8, ip_header.header.id);
    ASSERT_EQ(0b010, ip_header.getFlags());
    ASSERT_EQ(0, ip_header.getFragmentOffset());
    ASSERT_EQ(64, ip_header.header.ttl);
    ASSERT_EQ(1, ip_header.header.protocol);
    ASSERT_EQ(0x49de, ip_header.header.header_checksum);
    ASSERT_EQ(0x7f000001, ip_header.header.src_addr);
    ASSERT_EQ(0x7f000001, ip_header.header.dst_addr);
}

TEST(IP_Header, getProtocol) {
    IP_Header ip_header;
    ip_header.parse((uint8_t *) ip_header_raw);

    ASSERT_EQ(IPv4_Protocol::ICMP, ip_header.getProtocol());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
