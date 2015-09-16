/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2012
 *
 *  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 *  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 *  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 *  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
 *  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
 *  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
 *  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 *  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
 *  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
 *  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
 *  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
 *  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
 *  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
 *
 ****************************************************************************/

/*****************************************************************************
 * Filename:
 * ---------
 *   drvpdn_inline_mt6752_md2.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   PDN Driver (C Inline Implementation) for MT6595
 *      - PDN_SET(), PDN_CLR() is for Bus Clock Gating/Ungating
 *
 * Author:
 * -------
 * -------
 *
 * ===========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Merging from CL#57228
 *
 * removed!
 * removed!
 * Remove MT6752 MD2 AP side PDN control (from MT6589)
 *
 * removed!
 * removed!
 * Fix typo
 *
 * removed!
 * removed!
 * Fix some MD2 build error and code cleanup
 *
 ****************************************************************************/

#ifndef __DRVPDN_INLINE_MT6752_MD2_H__
#define __DRVPDN_INLINE_MT6752_MD2_H__

#if defined(__DRVPDN_INLINE_MT6752_MD1_H__)
    #error "MD1 & MD2 header should not be included at the same time"
#endif

/*****************************************************************************
 * Locally Used Options
 ****************************************************************************/
#define INTERRUPT_PROTECT       1

/*****************************************************************************
 * Include header files
 ****************************************************************************/

#include "reg_base.h"
#include "pdn_hw_mt6752_md2_series.h"

/* dummy */
#define DUMMY_PDN_SET_REGISTER  (0xFFFFFFF0)
#define DUMMY_PDN_CLR_REGISTER  (0x0FFFFFFF)

/*****************************************************************************
 * WR8 PDN enum auto-generated by cpp
 ****************************************************************************/
enum {
    PDN_OPT_32BIT_REG = 0x01,
    PDN_OPT_16BIT_REG = 0x02,
    PDN_OPT_NEVER_OFF = 0x04,
    PDN_OPT_INVERSED_POLARITY = 0x08
};

typedef enum {
    PDN_DMA_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_BOOT_SLV_CON_REG     = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_ABM_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_ADOE_CON_REG         = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_UART1_CON_REG        = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_DBG_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_OSTIMERARM_CON_REG   = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_GPT_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_TOPSM_CON_REG        = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_SIM_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_SIM2_CON_REG         = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_ELM_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_ALC_CON_REG          = DRVPDN_MD_PWR_GLOBAL_CON0,
    PDN_PF_BUFF_CON_REG      = DRVPDN_MD_PWR_GLOBAL_CON0,

    //PDN_BSIPMIC_CON_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_BPIPMIC_CON_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_BSI3G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_BPI3G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_WCDMATIMER_CON_REG   =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_AFC3G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_PFCDEC_CON_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_BYCACC_CON_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_ATB_CON_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CON0,
    //PDN_PFCENC_CON_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CON0,

    PDN_TDMA_CON_REG         =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_DIV_CON_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_FCS_CON_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_GCU_CON_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_AFC2G_T_CON_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_BSI2G_T_CON_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CON2,
    PDN_BPI2G_T_CON_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CON2,

    PDN_BSI2G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON4,
    PDN_BPI2G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON4,
    PDN_AFC2G_CON_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CON4,

    PDN_GCC_CON_REG          =  REG_MD2GCONFIG_CG_CON0,
    PDN_IRDMA_CON_REG        =  REG_MD2GCONFIG_CG_CON0,
    PDN_RXBUF_CON_REG        =  REG_MD2GCONFIG_CG_CON0,
    PDN_TXBUF_CON_REG        =  REG_MD2GCONFIG_CG_CON0,
    PDN_IRDBG_CON_REG        =  REG_MD2GCONFIG_CG_CON0,
    PDN_AHB2SDIO_CON_REG     =  REG_MD2GCONFIG_CG_CON0,

    PDN_APC_PRE_CON_REG      =  REG_MD2GCONFIG_CG_CON2,
    PDN_VAFE_CON_REG         =  REG_MD2GCONFIG_CG_CON2,
    PDN_BFE_CON_REG          =  REG_MD2GCONFIG_CG_CON2,

    PDN_APC_CON_REG          =  REG_MD2GCONFIG_CG_CON4,

    PDN_MAX_CON_REG
} PDN_CON_REG;

typedef enum {
    PDN_DMA_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_BOOT_SLV_SET_REG     = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_ABM_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_ADOE_SET_REG         = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_UART1_SET_REG        = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_DBG_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_OSTIMERARM_SET_REG   = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_GPT_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_TOPSM_SET_REG        = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_SIM_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_SIM2_SET_REG         = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_ELM_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_ALC_SET_REG          = DRVPDN_MD_PWR_GLOBAL_SET0,
    PDN_PF_BUFF_SET_REG      = DRVPDN_MD_PWR_GLOBAL_SET0,

    //PDN_BSIPMIC_SET_REG      =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_BPIPMIC_SET_REG      =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_BSI3G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_BPI3G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_WCDMATIMER_SET_REG   =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_AFC3G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_PFCDEC_SET_REG       =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_BYCACC_SET_REG       =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_ATB_SET_REG          =  DRVPDN_MODEM2G_CONFIG_CG_SET0,
    //PDN_PFCENC_SET_REG       =  DRVPDN_MODEM2G_CONFIG_CG_SET0,

    PDN_TDMA_SET_REG         =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_DIV_SET_REG          =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_FCS_SET_REG          =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_GCU_SET_REG          =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_AFC2G_T_SET_REG      =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_BSI2G_T_SET_REG      =  DRVPDN_MODEM2G_CONFIG_CG_SET2,
    PDN_BPI2G_T_SET_REG      =  DRVPDN_MODEM2G_CONFIG_CG_SET2,

    PDN_BSI2G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET4,
    PDN_BPI2G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET4,
    PDN_AFC2G_SET_REG        =  DRVPDN_MODEM2G_CONFIG_CG_SET4,

    PDN_GCC_SET_REG          =  REG_MD2GCONFIG_CG_SET0,
    PDN_IRDMA_SET_REG        =  REG_MD2GCONFIG_CG_SET0,
    PDN_RXBUF_SET_REG        =  REG_MD2GCONFIG_CG_SET0,
    PDN_TXBUF_SET_REG        =  REG_MD2GCONFIG_CG_SET0,
    PDN_IRDBG_SET_REG        =  REG_MD2GCONFIG_CG_SET0,
    PDN_AHB2SDIO_SET_REG     =  REG_MD2GCONFIG_CG_SET0,

    PDN_APC_PRE_SET_REG      =  REG_MD2GCONFIG_CG_SET2,
    PDN_VAFE_SET_REG         =  REG_MD2GCONFIG_CG_SET2,
    PDN_BFE_SET_REG          =  REG_MD2GCONFIG_CG_SET2,

    PDN_APC_SET_REG          =  REG_MD2GCONFIG_CG_SET4,

    PDN_MAX_SET_REG
} PDN_SET_REG;

typedef enum {
    PDN_DMA_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_BOOT_SLV_CLR_REG     = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_ABM_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_ADOE_CLR_REG         = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_UART1_CLR_REG        = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_DBG_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_OSTIMERARM_CLR_REG   = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_GPT_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_TOPSM_CLR_REG        = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_SIM_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_SIM2_CLR_REG         = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_ELM_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_ALC_CLR_REG          = DRVPDN_MD_PWR_GLOBAL_CLR0,
    PDN_PF_BUFF_CLR_REG      = DRVPDN_MD_PWR_GLOBAL_CLR0,

    //PDN_BSIPMIC_CLR_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_BPIPMIC_CLR_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_BSI3G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_BPI3G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_WCDMATIMER_CLR_REG   =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_AFC3G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_PFCDEC_CLR_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_BYCACC_CLR_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_ATB_CLR_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,
    //PDN_PFCENC_CLR_REG       =  DRVPDN_MODEM2G_CONFIG_CG_CLR0,

    PDN_TDMA_CLR_REG         =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_DIV_CLR_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_FCS_CLR_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_GCU_CLR_REG          =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_AFC2G_T_CLR_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_BSI2G_T_CLR_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,
    PDN_BPI2G_T_CLR_REG      =  DRVPDN_MODEM2G_CONFIG_CG_CLR2,

    PDN_BSI2G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR4,
    PDN_BPI2G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR4,
    PDN_AFC2G_CLR_REG        =  DRVPDN_MODEM2G_CONFIG_CG_CLR4,

    PDN_GCC_CLR_REG          =  REG_MD2GCONFIG_CG_CLR0,
    PDN_IRDMA_CLR_REG        =  REG_MD2GCONFIG_CG_CLR0,
    PDN_RXBUF_CLR_REG        =  REG_MD2GCONFIG_CG_CLR0,
    PDN_TXBUF_CLR_REG        =  REG_MD2GCONFIG_CG_CLR0,
    PDN_IRDBG_CLR_REG        =  REG_MD2GCONFIG_CG_CLR0,
    PDN_AHB2SDIO_CLR_REG     =  REG_MD2GCONFIG_CG_CLR0,

    PDN_APC_PRE_CLR_REG      =  REG_MD2GCONFIG_CG_CLR2,
    PDN_VAFE_CLR_REG         =  REG_MD2GCONFIG_CG_CLR2,
    PDN_BFE_CLR_REG          =  REG_MD2GCONFIG_CG_CLR2,

    PDN_APC_CLR_REG          =  REG_MD2GCONFIG_CG_CLR4,

    PDN_MAX_CLR_REG
} PDN_CLR_REG;

typedef enum {

    PDN_DMA_REG_BIT          =  MD_PWR_GLOBAL_CON0_DMA,
    PDN_BOOT_SLV_REG_BIT     =  MD_PWR_GLOBAL_CON0_BOOT_SLV,
    PDN_ABM_REG_BIT          =  MD_PWR_GLOBAL_CON0_ABM,
    PDN_ADOE_REG_BIT         =  MD_PWR_GLOBAL_CON0_ADOE,
    PDN_UART1_REG_BIT        =  MD_PWR_GLOBAL_CON0_UART,
    PDN_DBG_REG_BIT          =  MD_PWR_GLOBAL_CON0_DBG,
    PDN_OSTIMERARM_REG_BIT   =  MD_PWR_GLOBAL_CON0_OSTIMER,
    PDN_GPT_REG_BIT          =  MD_PWR_GLOBAL_CON0_GPT,
    PDN_TOPSM_REG_BIT        =  MD_PWR_GLOBAL_CON0_TOPSM,
    PDN_SIM_REG_BIT          =  MD_PWR_GLOBAL_CON0_SIM1,
    PDN_SIM2_REG_BIT         =  MD_PWR_GLOBAL_CON0_SIM2,
    PDN_ELM_REG_BIT          =  MD_PWR_GLOBAL_CON0_ELM,
    PDN_ALC_REG_BIT          =  MD_PWR_GLOBAL_CON0_ALC,
    PDN_PF_BUFF_REG_BIT      =  MD_PWR_GLOBAL_CON0_PF_BUFF,

    //PDN_BSIPMIC_REG_BIT      =  MODEM2G_CONFIG_CG_CON0_BSIPMIC,
    //PDN_BPIPMIC_REG_BIT      =  MODEM2G_CONFIG_CG_CON0_BPIPMIC,
    //PDN_BSI3G_REG_BIT        =  MODEM2G_CONFIG_CG_CON0_BSI3G,
    //PDN_BPI3G_REG_BIT        =  MODEM2G_CONFIG_CG_CON0_BPI3G,
    //PDN_WCDMATIMER_REG_BIT   =  MODEM2G_CONFIG_CG_CON0_WCDMATIMER,
    //PDN_AFC3G_REG_BIT        =  MODEM2G_CONFIG_CG_CON0_AFC3G,
    //PDN_PFCDEC_REG_BIT       =  MODEM2G_CONFIG_CG_CON0_PFCDEC,
    //PDN_BYCACC_REG_BIT       =  MODEM2G_CONFIG_CG_CON0_BYCACC,
    //PDN_ATB_REG_BIT          =  MODEM2G_CONFIG_CG_CON0_ATB,
    //PDN_PFCENC_REG_BIT       =  MODEM2G_CONFIG_CG_CON0_PFCENC,

    PDN_TDMA_REG_BIT         =  MODEM2G_CONFIG_CG_CON2_TDMA,
    PDN_DIV_REG_BIT          =  MODEM2G_CONFIG_CG_CON2_DIV,
    PDN_FCS_REG_BIT          =  MODEM2G_CONFIG_CG_CON2_FCS,
    PDN_GCU_REG_BIT          =  MODEM2G_CONFIG_CG_CON2_GCU,
    PDN_AFC2G_T_REG_BIT      =  MODEM2G_CONFIG_CG_CON2_AFC2G_T,
    PDN_BSI2G_T_REG_BIT      =  MODEM2G_CONFIG_CG_CON2_BSI2G_T,
    PDN_BPI2G_T_REG_BIT      =  MODEM2G_CONFIG_CG_CON2_BPI2G_T,

    PDN_BSI2G_REG_BIT        =  MODEM2G_CONFIG_CG_CON4_BSI2G,
    PDN_BPI2G_REG_BIT        =  MODEM2G_CONFIG_CG_CON4_BPI2G,
    PDN_AFC2G_REG_BIT        =  MODEM2G_CONFIG_CG_CON4_AFC2G,

    PDN_GCC_REG_BIT          =  MD2GCONFIG_CG_CON0_GCC,
    PDN_IRDMA_REG_BIT        =  MD2GCONFIG_CG_CON0_IRDMA,
    PDN_RXBUF_REG_BIT        =  MD2GCONFIG_CG_CON0_RXBUF,
    PDN_TXBUF_REG_BIT        =  MD2GCONFIG_CG_CON0_TXBUF,
    PDN_IRDBG_REG_BIT        =  MD2GCONFIG_CG_CON0_IRDBG,
    PDN_AHB2SDIO_REG_BIT     =  MD2GCONFIG_CG_CON0_AHB2SDIO,

    PDN_APC_PRE_REG_BIT      =  MD2GCONFIG_CG_CON2_APC_PRE,
    PDN_VAFE_REG_BIT         =  MD2GCONFIG_CG_CON2_VAFE,
    PDN_BFE_REG_BIT          =  MD2GCONFIG_CG_CON2_BFE,

    PDN_APC_REG_BIT          =  MD2GCONFIG_CG_CON4_APC,

    PDN_MAX_REG_BIT
} PDN_REG_BIT;

typedef enum {
    PDN_DMA_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_BOOT_SLV_REG_WIDTH   =  PDN_OPT_32BIT_REG,
    PDN_ABM_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_ADOE_REG_WIDTH       =  PDN_OPT_32BIT_REG,
    PDN_UART1_REG_WIDTH      =  PDN_OPT_32BIT_REG | PDN_OPT_NEVER_OFF,
    PDN_DBG_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_OSTIMERARM_REG_WIDTH =  PDN_OPT_32BIT_REG,
    PDN_GPT_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_TOPSM_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    PDN_SIM_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_SIM2_REG_WIDTH       =  PDN_OPT_32BIT_REG,
    PDN_ELM_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_ALC_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_PF_BUFF_REG_WIDTH    =  PDN_OPT_32BIT_REG,

    //PDN_BSIPMIC_REG_WIDTH    =  PDN_OPT_32BIT_REG,
    //PDN_BPIPMIC_REG_WIDTH    =  PDN_OPT_32BIT_REG,
    //PDN_BSI3G_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    //PDN_BPI3G_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    //PDN_WCDMATIMER_REG_WIDTH =  PDN_OPT_32BIT_REG,
    //PDN_AFC3G_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    //PDN_PFCDEC_REG_WIDTH     =  PDN_OPT_32BIT_REG,
    //PDN_BYCACC_REG_WIDTH     =  PDN_OPT_32BIT_REG,
    //PDN_ATB_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    //PDN_PFCENC_REG_WIDTH     =  PDN_OPT_32BIT_REG,

    PDN_TDMA_REG_WIDTH       =  PDN_OPT_32BIT_REG,
    PDN_DIV_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_FCS_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_GCU_REG_WIDTH        =  PDN_OPT_32BIT_REG,
    PDN_AFC2G_T_REG_WIDTH    =  PDN_OPT_32BIT_REG,
    PDN_BSI2G_T_REG_WIDTH    =  PDN_OPT_32BIT_REG,
    PDN_BPI2G_T_REG_WIDTH    =  PDN_OPT_32BIT_REG,
    
    PDN_BSI2G_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    PDN_BPI2G_REG_WIDTH      =  PDN_OPT_32BIT_REG,
    PDN_AFC2G_REG_WIDTH      =  PDN_OPT_32BIT_REG,

    PDN_GCC_REG_WIDTH        =  PDN_OPT_16BIT_REG,
    PDN_IRDMA_REG_WIDTH      =  PDN_OPT_16BIT_REG,
    PDN_RXBUF_REG_WIDTH      =  PDN_OPT_16BIT_REG,
    PDN_TXBUF_REG_WIDTH      =  PDN_OPT_16BIT_REG,
    PDN_IRDBG_REG_WIDTH      =  PDN_OPT_16BIT_REG,
    PDN_AHB2SDIO_REG_WIDTH   =  PDN_OPT_16BIT_REG,

    PDN_APC_PRE_REG_WIDTH    =  PDN_OPT_16BIT_REG,
    PDN_VAFE_REG_WIDTH       =  PDN_OPT_16BIT_REG,
    PDN_BFE_REG_WIDTH        =  PDN_OPT_16BIT_REG,

    PDN_APC_REG_WIDTH        =  PDN_OPT_16BIT_REG,

    PDN_MAX_REG_WIDTH
} PDN_REG_WIDTH;

/*****************************************************************************
 * Define data structures
 ****************************************************************************/

/*****************************************************************************
 * Define macros
 ****************************************************************************/

/*
 * PDN_SET(kal_uint32 dev): power down device
 * @dev: device ID (EX: PDN_UART1)
 */
#define PDN_SET(dev) do {                                                                       \
        if(DUMMY_PDN_SET_REGISTER == (kal_uint32)dev##_SET_REG) {                               \
            register kal_uint32 mask;                                                           \
            mask = SaveAndSetIRQMask();                                                         \
            if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {                                          \
                register kal_uint32 reg_val;                                                    \
                reg_val = *(volatile kal_uint32 *)(dev##_CON_REG);                              \
                if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) {                               \
                    reg_val &= ~(kal_uint32)(dev##_REG_BIT);                                    \
                } else {                                                                        \
                    reg_val |= (kal_uint32)(dev##_REG_BIT);                                     \
                }                                                                               \
                *(volatile kal_uint32 *)(dev##_CON_REG) = reg_val;                              \
            } else {                                                                            \
                register kal_uint16 reg_val;                                                    \
                reg_val = *(volatile kal_uint16 *)(dev##_CON_REG);                              \
                if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) {                               \
                    reg_val &= ~(kal_uint16)(dev##_REG_BIT);                                    \
                } else {                                                                        \
                    reg_val |= (kal_uint16)(dev##_REG_BIT);                                     \
                }                                                                               \
                *(volatile kal_uint16 *)(dev##_CON_REG) = reg_val;                              \
            }                                                                                   \
            RestoreIRQMask(mask);                                                               \
        } else {                                                                                \
            if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {                                          \
                *(volatile kal_uint32 *)(dev##_SET_REG) = (kal_uint32)(dev##_REG_BIT);          \
            } else {                                                                            \
                *(volatile kal_uint16 *)(dev##_SET_REG) = (kal_uint16)(dev##_REG_BIT);          \
            }                                                                                   \
        }                                                                                       \
    } while (0)

/*
 * PDN_CLR(kal_uint32 dev): power up device
 * @dev: device ID (EX: PDN_UART1)
 */
#define PDN_CLR(dev) do {                                                                       \
        if(DUMMY_PDN_CLR_REGISTER == (kal_uint32)dev##_CLR_REG) {                               \
            register kal_uint32 mask;                                                           \
            mask = SaveAndSetIRQMask();                                                         \
            if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {                                          \
                register kal_uint32 reg_val;                                                    \
                reg_val = *(volatile kal_uint32 *)(dev##_CON_REG);                              \
                if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) {                               \
                    reg_val |= (kal_uint32)(dev##_REG_BIT);                                     \
                } else {                                                                        \
                    reg_val &= ~(kal_uint32)(dev##_REG_BIT);                                    \
                }                                                                               \
                *(volatile kal_uint32 *)(dev##_CON_REG) = reg_val;                              \
            } else {                                                                            \
                register kal_uint16 reg_val;                                                    \
                reg_val = *(volatile kal_uint16 *)(dev##_CON_REG);                              \
                if(dev##_REG_WIDTH & PDN_OPT_INVERSED_POLARITY) {                               \
                    reg_val |= (kal_uint16)(dev##_REG_BIT);                                     \
                } else {                                                                        \
                    reg_val &= ~(kal_uint16)(dev##_REG_BIT);                                    \
                }                                                                               \
                *(volatile kal_uint16 *)(dev##_CON_REG) = reg_val;                              \
            }                                                                                   \
            RestoreIRQMask(mask);                                                               \
        } else {                                                                                \
            if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {                                          \
                *(volatile kal_uint32 *)(dev##_CLR_REG) = (kal_uint32)(dev##_REG_BIT);          \
            } else {                                                                            \
                *(volatile kal_uint16 *)(dev##_CLR_REG) = (kal_uint16)(dev##_REG_BIT);          \
            }                                                                                   \
        }                                                                                       \
    } while (0)

/*
 * PDN_STS(kal_uint32 dev, type s, type): get device power down status
 * @dev: device ID (EX: PDN_UART1)
 * @s: returned power down status
 * @t: type of s
 */
#define PDN_STS(dev, s, t) do {                                                                 \
        /* default PDN_STATUS */                                                                \
        if (dev##_REG_WIDTH & PDN_OPT_32BIT_REG) {                                              \
            (s) = (t)(*(volatile kal_uint32 *)(dev##_CON_REG) & dev##_REG_BIT);                 \
        } else {                                                                                \
            (s) = (t)(*(volatile kal_uint16 *)(dev##_CON_REG) & dev##_REG_BIT);                 \
        }                                                                                       \
    } while(0)

#endif /* !__DRVPDN_INLINE_MT6752_MD2_H__ */