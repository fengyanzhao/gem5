/*
 * Copyright (c) Tianjin University
 * All rights reserved
 *
 * Author: Liang Kaiyuan
 */

#include "isox.hh"

CMV::CMV(size_t page_count)
{
    //No implementation.
}

CMV::~CMV(void)
{
    //No implementation.
}

void
CMV::setVector(int index, bool vec)
{
    //No implementation.
}

bool
CMV::getVector(int index)
{
    //No implementation.
    return false;
}

CT::CT(void)
{
    //No implementation.
}

CTEntry
CT::getEntry(int comp_id)
{
    //No implementation.
    struct CTEntry cte;
    return cte;
}

IsoX::IsoX(void)
{
    //No implementation.
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
IsoX::setCPTBASEReg(Addr base)
{
    cpt_base = base;
}

void
IsoX::setCCRIDReg(int id)
{
    ccr_id =id;
}

void
IsoX::setCCRCTReg(CTEntry cte)
{
    ccr_ct = cte;
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
IsoX::inComp(Addr addr)
{
    //No implementation.
    return false;
}





