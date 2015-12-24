/*
 * Copyright (c) Tianjin University
 * All rights reserved
 *
 * Author: Liang Kaiyuan
 */

#include "isox.hh"

CMV::CMV(size_t page_cnt, size_t _page_bits)
{
    page_count = page_cnt;
    page_bits = _page_bits;
    vectors = (bool *)calloc(page_cnt, sizeof(bool));
    memset(vectors, 0, page_cnt * sizeof(bool));
}

CMV::~CMV(void)
{
    free(vectors);
}

void
CMV::setVector(Addr paddr, bool vec)
{
    int index = (int)(paddr >> page_bits);
    if (index > page_count)
    {
        //Should never happen.
    }
    vectors[index] = vec;
}

bool
CMV::getVector(Addr paddr)
{
    int index = (int)(paddr >> page_bits);
    if(index > page_count)
    {
        //Should never happen.
    }
    return vectors[index];
}

CT::CT(void)
{
    memset(entries, 0, COMPMAX * sizeof(CTEntry));
}

CTEntry&
CT::getEntry(int comp_id)
{
    return entries[comp_id];
}

IsoX::IsoX(void)
{
    // The values of page count and bits can only be specified during runtime.
    // 65535 and 16 only for testing.
    // The values of them should be set by bootloader or OS.
    init(65535, 16);
}

void
IsoX::init(size_t page_cnt, size_t page_bits)
{
    cmv = new CMV(page_cnt, page_bits);
    ct = new CT();
    psr = false;
    cpt_base = 0x0;
    ccr_id = -1;
}

Addr
IsoX::readCPTBASEReg()
{
    return cpt_base;
}

int
IsoX::readCCRIDReg()
{
    return ccr_id;
}

CTEntry
IsoX::readCCRCTReg()
{
    return ccr_ct;
}

bool
IsoX::readPSRReg()
{
    return psr;
}

void
IsoX::setCCRIDReg(int id)
{
    ccr_id =id;
    ccr_ct = ct->getEntry(id);
    cpt_base = ccr_ct.cpt_base;
}

void
IsoX::setPSRReg(bool mode)
{
    psr = mode;
}

bool
IsoX::isCompMode()
{
    return psr;
}

bool
IsoX::inComp(Addr vaddr)
{
    if (vaddr < ccr_ct.comp_base)
    {
        return false;
    }

    if (vaddr - ccr_ct.comp_base < ccr_ct.comp_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
IsoX::getCMV(Addr paddr)
{
    return cmv->getVector(paddr);
}

void
IsoX::setCMV(Addr paddr, bool vec)
{
    cmv->setVector(paddr, vec);
}

void
IsoX::leaveComp()
{
    psr = false;
}

CTEntry&
IsoX::getEntry(int comp_id)
{
    return ct->getEntry(comp_id);
}

IsoxArgus::IsoxArgus(void)
{
     comp_id=5;
     comp_base=0x000100f4;
     comp_size=0x1000;
     cpt_base=0x00011000;
     cpt_size=0x30;
     phys_addr=0x000100f4;
     page_bits=1;
 //No implementation.
}


