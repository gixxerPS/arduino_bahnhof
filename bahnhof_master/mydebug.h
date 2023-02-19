
// einkommentieren um debugausgaben zu aktivieren
//#define MYDEBUG

#ifdef MYDEBUG
	#define DEBUG_PRINT(...) { Serial.print(__VA_ARGS__); }
	#define DEBUG_PRINTLN(...) { Serial.println(__VA_ARGS__); }
#else
	#define DEBUG_PRINT(...) {}
	#define DEBUG_PRINTLN(...) {}
#endif