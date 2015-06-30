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

#ifndef __BASE_ISOX_HH__
#define __BASE_ISOX_HH__

#include "arch/types.hh"
#include "arch/registers.hh"
#include "base/types.hh"
#include "arch/arm/table_walker.hh"

#define COMPMAX 1024

using namespace std;

/* Compartment Table Entry (CTEntry)
 *
 */
struct CTEntry
{
    Addr comp_base;
    size_t comp_size;
    int page_count;
    std::hash<std::string> comp_hash;
    Addr cpt_base;
    size_t cpt_size;
};

/* Physical Page Compartment Membership Vector (CMV)
 *
 */
class CMV
{
private:
    bool vectors[];
public:
    CMV(size_t page_count);

    ~CMV();

    void setVector(int index, bool vec);

    bool getVector(int index);
};

/* Compartment Table (CT)
 *
 */
class CT
{
private:
public:
    CT(void);

    CTEntry getEntry(int comp_id);
};

class IsoX
{
private:
    /* Compartment membership vector */
    CMV *cmv;

    /* Compartment table*/
    CT *ct;

    /* Register pointing to
     * base address of current compartment
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

    TableWalker *tablewalker;

public:
    IsoX();

    Addr readCPTBASEReg();

    int readCCRIDReg();

    CTEntry readCCRCTReg();

    int readPSRReg();

    void setCPTBASEReg(Addr base);

    void setCCRIDReg(int id);

    void setCCRCTReg(CTEntry cte);

    void setPSRReg(int mode);

    bool isCompMode();

    bool inComp(Addr addr);
};

static IsoX isox;
#endif /*__BASE_ISOX_HH__*/

