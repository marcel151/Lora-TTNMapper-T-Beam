// Comment the next line to use ABP authentication on TTN. Leave it as it is to use recommended OTAA
#define OTAA

#ifndef LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
#define LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED

#ifndef OTAA
// UPDATE WITH YOUR TTN KEYS AND ADDR.
// Setting for ABP
static PROGMEM u1_t NWKSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // LoRaWAN NwkSKey, network session key 
static u1_t PROGMEM APPSKEY[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // LoRaWAN AppSKey, application session key 
static const u4_t DEVADDR = 0x00000000 ; // LoRaWAN end-device address (DevAddr)
#else
// Settings from OTAA device
// This EUI must be in little-endian format, so least-significant-byte
// first. When copying an EUI from ttnctl output, this means to reverse
// the bytes. For TTN issued EUIs the last bytes should be 0x00, 0x00,
// 0x00.
static const u1_t PROGMEM DEVEUI[8]={ 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 } ; // Device EUI, hex, lsb
// This should also be in little endian format, see above.
static const u1_t PROGMEM APPEUI[8]={ 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 }; // Application EUI, hex, lsb
// This key should be in big endian format (or, since it is not really a
// number but a block of memory, endianness does not really apply). In
// practice, a key taken from ttnctl can be copied as-is.
// The key shown here is the semtech default key.
static const u1_t PROGMEM APPKEY[16] = { 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11 }; // App Key, hex, msb

void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}
void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}
void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16);}
#endif

#endif //LORA_TTNMAPPER_TBEAM_CONFIG_INCLUDED
