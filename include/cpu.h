#ifndef CPU_H
#define CPU_H

#include <map>
#include <iostream>
#include <fstream>
#include <vector>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

using namespace std;

class CPU
{
private:
    typedef void(CPU::*FP)();

    // 16-bit registers
    u16 AF; // Accumulator & Flags
    u16 BC;
    u16 DE;
    u16 HL;
    u16 SP; // Stack Pointer
    u16 PC; // Program Counter/Pointer


    // This is RAM which is ~8kB
    vector<u16> memory(0x1fff);

    // function pointer map, used to go to loaded instruction
    // without use of switch or if-else statements
    map<int, FP> instr;

    void load(char *);
public:
    void run(char *);

    CPU();

    /*********** Instructions *************/

    // 8-bit load instr
    void ld_r_r();
    void ld_r_n();
    void ld_r_hl();
    void ld_hl_r();
    void ld_hl_n();
    void ld_a_bc();
    void ld_a_de();
    void ld_a_nn();
    void ld_bc_a();
    void ld_de_a();
    void ld_nn_a();
    void ld_a_ff00();
    void ld_ff00_a();
    void ld_a_ff00c();
    void ld_ff00c_a();

    void ldi_hl_a();
    void ldi_a_hl();
    
    void ldd_hl_a();
    void ldd_a_hl();


    // 16-bit load instr
    void ld_rr_nn();
    void ld_sp_hl();
    void push_rr();
    void pop_rr();

    // 8-bit arithmetic/logic instr
    void add_a_r();
    void add_a_n();
    void add_a_hl();

    void adc_a_r();
    void adc_a_n();
    void adc_a_hl();

    void sub_r();
    void sub_n();
    void sub_hl();

    void sbc_a_r();
    void sbc_a_n();
    void sbc_a_hl();

    void and_r();
    void and_n();
    void and_hl();

    void xor_r();
    void xor_n();
    void xor_hl();

    void or_r();
    void or_n();
    void or_hl();

    void cp_r();
    void cp_n();
    void cp_hl();

    void inc_r();
    void inc_hl();

    void dec_r();
    void dec_hl();

    void daa();
    void cpl();

    // 16-bit arithmetic/logical instr
    void add_hl_rr();
    void inc_rr();
    void dec_rr();
    void add_sp_dd();
    void hl_spdd();
};

#endif