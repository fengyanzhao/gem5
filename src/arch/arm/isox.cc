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
    //No implementation.
    Addr addr = (Addr)0;
    return addr;
}

int
IsoX::readCCRIDReg()
{
    //No implementation.
    return 0;
}

CTEntry
IsoX::readCCRCTReg()
{
    //No implementation.
    struct CTEntry cte;
    return cte;
}

int
IsoX::readPSRReg()
{
    //No implementation.
    return 0;
}

void
IsoX::setCPTBASEReg(Addr base)
{
    //No implementation.
}

void
IsoX::setCCRIDReg(int id)
{
    //No implementation.
}

void
IsoX::setCCRCTReg(CTEntry cte)
{
    //No implementation.
}

void
IsoX::setPSRReg(int mode)
{
    //No implementation.
}

bool
IsoX::isCompMode()
{
    //No implementation.
    return false;
}

bool
IsoX::inComp(Addr addr)
{
    //No implementation.
    return false;
}





