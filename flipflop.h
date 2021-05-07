#ifndef FLIPFLOP_H_INCLUDED
#define FLIPFLOP_H_INCLUDED

// Deklarasi simbol tiap Port A-D
typedef enum{ // enum digunakan untuk membuat simbol bernilai seperti yang dilakukan oleh preprocessor #define
    PA, // Port A AVR
    PB, // Port B AVR
    PC, // Port C AVR
    PD  // Port D AVR
}port_id_t; // Menyimpan nama Port

// Macro untuk PORT, DDR, dan PIN
#define port(p) (p==PA?PORTA:(p==PB?PORTB:p==PC?PORTC:PORTD)) // preprocessor untuk menentukan Port A-D sebagai Output
#define ddr(p) _SFR_IO8(_SFR_IO_ADDR(port(p))-1) // #define DDR(x) (*(&x - 1)) // Address Of Input Register Of Port x
#define pin(p) _SFR_IO8(_SFR_IO_ADDR(port(p))-2) // #define PIN(x) (*(&x - 2)) // Address Of Data Direction Register Of Port x

// Perintah untuk mengirim logika 1 ke LED atau untuk menyalakan LED
template<port_id_t p>
static inline void PortSetBit(uint8_t bit){ //bit = save number bit (0/1)
    port(p) |= _BV(bit); // Mengirim logika 1 (port out ON, HIGH) menggunakan Set ke Port Out
}

// Perintah untuk mengirim logika 0 ke LED atau untuk mematikan LED
template<port_id_t p>
static inline void PortClearBit(uint8_t bit){
    port(p) &= ~_BV(bit); // Mengirim logika 0 (port out OFF, LOW) menggunakan Set ke Port Out
}

// Perintah untuk mengubah bit 1 menjadi On dan bit 0 menjadi Off.
template<port_id_t p, uint8_t bit>
class PinOut{
public:
    PinOut(){
        ddr(p) |= _BV(bit); // configure PinOut output(bit)
    }
    static inline void On(){ PortSetBit<p>(bit); }      // Fungsi On atau menyalakan LED
    static inline void Off(){ PortClearBit<p>(bit); }   // Fungsi Off atau mematikan LED
};

#endif // FLIPFLOP_H_INCLUDED
