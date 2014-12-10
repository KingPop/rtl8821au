/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

#include "../odm_precomp.h"

#if (RTL8812A_SUPPORT == 1)



void odm_ConfigBB_AGC_8812A(struct rtl_dm *pDM_Odm, uint32_t Addr,
	uint32_t Bitmask, uint32_t Data)
{
	rtl_set_bbreg(pDM_Odm->Adapter, Addr, Bitmask, Data);
	/* Add 1us delay between BB/RF register setting. */
	udelay(1);

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigBBWithHeaderFile: [AGC_TAB] %08X %08X\n", Addr, Data));
}

void odm_ConfigBB_PHY_REG_PG_8812A(struct rtl_dm *pDM_Odm, uint32_t Addr,
	uint32_t Bitmask, uint32_t Data)
{
	if (Addr == 0xfe || Addr == 0xffe) {
		msleep(50);
	} else {
		storePwrIndexDiffRateOffset(pDM_Odm->Adapter, Addr, Bitmask, Data);
	}
	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD, ("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X %08X\n", Addr, Bitmask, Data));
}

void odm_ConfigBB_PHY_8812A(struct rtl_dm *pDM_Odm, uint32_t Addr,
	uint32_t Bitmask, uint32_t Data)
{
	if (Addr == 0xfe) {
		msleep(50);
	} else if (Addr == 0xfd) {
		mdelay(5);
	} else if (Addr == 0xfc) {
		mdelay(1);
	} else if (Addr == 0xfb) {
		udelay(50);
	} else if (Addr == 0xfa) {
		udelay(5);
	} else if (Addr == 0xf9) {
		udelay(1);
	} else {
		rtl_set_bbreg(pDM_Odm->Adapter, Addr, Bitmask, Data);
		/*  Add 1us delay between BB/RF register setting. */
		udelay(1);
	}

	ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X\n", Addr, Data));
}

#endif

