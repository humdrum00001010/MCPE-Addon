//
// Created by humdr on 2017-01-08.
//

#ifndef N_ADDON_RAKNET_H
#define N_ADDON_RAKNET_H
namespace RakNet {
    class SystemAddress {
    public:
        char filler[20];
    public:
        void operator=(RakNet::SystemAddress const&);
        bool operator==(RakNet::SystemAddress const&);
        bool operator!=(RakNet::SystemAddress const&);
        bool operator>(RakNet::SystemAddress const&);
        bool operator<(RakNet::SystemAddress const&);
    public:
        int ToInteger(RakNet::SystemAddress const&);
        const char* ToString(bool, char*, char);
        const char* ToString(bool, char);
        const char* ToString_New(bool, char*, char);
        const char* ToString_Old(bool, char*, char);
        int size();
    public:
        SystemAddress();
        SystemAddress(const char*);
        SystemAddress(const char*, unsigned short);
        void CopyPort(RakNet::SystemAddress const&);
        void EqualsExcludingPort(RakNet::SystemAddress const&);
        void FixForIPVersion(RakNet::SystemAddress const&);
        void FromString(const char*, int);
        void FromStringExplicitPort(const char*, unsigned short, int);
        short GetIPPROTO() const;
        int GetIPVersion() const;
        int GetPort() const;
        short GetPortNetworkOrder() const;
        bool IsLANAddress();
        bool IsLinkLocalAddress();
        bool ISLoopback();
        bool IsMulticastAddress();
        bool IsValidIPAddress();
        void SetBinaryAddress(const char*, char);
        void SetPort(unsigned short);
        void SetPortHostOrder(unsigned short);
        void SetPortNetworkOrder(unsigned short);
        void SetToLoopback(unsigned char);
        void SetToLoopback();
    };
}
#endif //N_ADDON_RAKNET_H
