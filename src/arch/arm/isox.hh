/*
 * Copyright (c) Tianjin University
 * All rights reserved
 *
 * Author: Liang Kaiyuan
 */


/**
 * @file
 *
 * Iso-X component and data structure
 */

#ifndef __ARCH_ARM_ISOX_HH__
#define __ARCH_ARM_ISOX_HH__

#include "arch/types.hh"
#include "arch/registers.hh"
#include "base/types.hh"
#include "arch/arm/table_walker.hh"

#define COMPMAX 1024

using namespace std;

/* Compartment Table Entry (CTEntry)
 *
 */
typedef struct CTEntry
{
    Addr comp_base;
    size_t comp_size;
    int page_count;
    std::hash<std::string> comp_hash;
    Addr cpt_base;
    size_t cpt_size;
}CTEntry;

/* Physical Page Compartment Membership Vector (CMV)
 *
 */
class CMV
{
private:
    /* The number of physical pages*/
    size_t page_count;

    /* The bits of physical page*/
    size_t page_bits;

    bool *vectors;
public:
    CMV(size_t page_count, size_t page_bits);

    ~CMV();

    void setVector(Addr paddr, bool vec);

    bool getVector(Addr paddr);
};

/* Compartment Table (CT)
 *
 */
class CT
{
private:
    CTEntry entries[COMPMAX];
public:
    CT(void);

    CTEntry& getEntry(int comp_id);
};

class IsoX
{
private:
    /* Compartment membership vector */
    CMV *cmv;

    /* Compartment table*/
    CT *ct;

    /* Register pointing to
     * base address of current compartment page table
     */
    Addr cpt_base;

    /* Register storing ID of current compartment */
    int ccr_id;

    /* Register storing CT entry
     * corresponding to current active compartment
     */
    CTEntry ccr_ct;

    /* Processor state register*/
    bool psr;

public:
    IsoX();

    /** Initialize Iso-X
     * @page_cnt The number of physical pages used to initialize CMV
     * @page_bits The bits of physical page used to initialize CMV
     */
    void init(size_t page_cnt, size_t page_bits);

    CTEntry& getEntry(int comp_id);

    Addr readCPTBASEReg();

    int readCCRIDReg();

    CTEntry readCCRCTReg();

    bool readPSRReg();

    void setCPTBASEReg(Addr base);

    void setCCRIDReg(int id);

    void setPSRReg(bool mode);

    bool isCompMode();

    bool inComp(Addr vaddr);

    bool getCMV(Addr paddr);

    void setCMV(Addr paddr, bool vec);
};

static IsoX isox;

/* Arguments for Isox Instructions
 *
 */
class IsoxArgus
{
private:
public:
    IsoxArgus();
    int comp_id;
    Addr comp_base;
    size_t comp_size;
    Addr cpt_base;
    size_t cpt_size;
    Addr virt_addr;
    Addr phys_addr;
    int page_perms;
};
static IsoxArgus isoxargus;
#endif /*__ARCH_ARM_ISOX_HH__*/

