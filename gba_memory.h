/* gameplaySP
 *
 * Copyright (C) 2006 Exophase <exophase@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef MEMORY_H
#define MEMORY_H

#include "libretro.h"
extern int use_libretro_save_method;

#define DMA_CHAN_CNT   4

typedef enum
{
  DMA_START_IMMEDIATELY = 0,
  DMA_START_VBLANK      = 1,
  DMA_START_HBLANK      = 2,
  DMA_START_SPECIAL     = 3,
  DMA_INACTIVE          = 4
} dma_start_type;

typedef enum
{
  DMA_16BIT = 0,
  DMA_32BIT = 1
} dma_length_type;

typedef enum
{
  DMA_NO_REPEAT = 0,
  DMA_REPEAT    = 1
} dma_repeat_type;

typedef enum
{
  DMA_INCREMENT = 0,
  DMA_DECREMENT = 1,
  DMA_FIXED     = 2,
  DMA_RELOAD    = 3
} dma_increment_type;

typedef enum
{
  DMA_NO_IRQ      = 0,
  DMA_TRIGGER_IRQ = 1
} dma_irq_type;

typedef enum
{
  DMA_DIRECT_SOUND_A,
  DMA_DIRECT_SOUND_B,
  DMA_NO_DIRECT_SOUND
} dma_ds_type;

typedef struct
{
  u32 source_address;
  u32 dest_address;
  u32 length;
  dma_repeat_type repeat_type;
  dma_ds_type direct_sound_channel;
  dma_increment_type source_direction;
  dma_increment_type dest_direction;
  dma_length_type length_type;
  dma_start_type start_type;
  dma_irq_type irq;
} dma_transfer_type;

typedef enum
{
  REG_DISPCNT = 0x000,
  REG_DISPSTAT = 0x002,
  REG_VCOUNT = 0x003,
  REG_BG0CNT = 0x004,
  REG_BG1CNT = 0x005,
  REG_BG2CNT = 0x006,
  REG_BG3CNT = 0x007,
  REG_BG0HOFS = 0x08,
  REG_BG0VOFS = 0x09,
  REG_BG1HOFS = 0x0A,
  REG_BG1VOFS = 0x0B,
  REG_BG2HOFS = 0x0C,
  REG_BG2VOFS = 0x0D,
  REG_BG3HOFS = 0x0E,
  REG_BG3VOFS = 0x0F,
  REG_BG2PA = 0x10,
  REG_BG2PB = 0x11,
  REG_BG2PC = 0x12,
  REG_BG2PD = 0x13,
  REG_BG2X_L = 0x14,
  REG_BG2X_H = 0x15,
  REG_BG2Y_L = 0x16,
  REG_BG2Y_H = 0x17,
  REG_BG3PA = 0x18,
  REG_BG3PB = 0x19,
  REG_BG3PC = 0x1A,
  REG_BG3PD = 0x1B,
  REG_BG3X_L = 0x1C,
  REG_BG3X_H = 0x1D,
  REG_BG3Y_L = 0x1E,
  REG_BG3Y_H = 0x1F,
  REG_WIN0H = 0x20,
  REG_WIN1H = 0x21,
  REG_WIN0V = 0x22,
  REG_WIN1V = 0x23,
  REG_WININ = 0x24,
  REG_WINOUT = 0x25,
  REG_BLDCNT = 0x28,
  REG_BLDALPHA = 0x29,
  REG_BLDY = 0x2A,
  // Sound control registers
  REG_SOUND1CNT_L = 0x30,
  REG_SOUND1CNT_H = 0x31,
  REG_SOUND1CNT_X = 0x32,
  REG_SOUND2CNT_L = 0x34,
  REG_SOUND2CNT_H = 0x36,
  REG_SOUND3CNT_L = 0x38,
  REG_SOUND3CNT_H = 0x39,
  REG_SOUND3CNT_X = 0x3A,
  REG_SOUND4CNT_L = 0x3C,
  REG_SOUND4CNT_H = 0x3E,
  REG_SOUNDCNT_L = 0x40,
  REG_SOUNDCNT_H = 0x41,
  REG_SOUNDCNT_X = 0x42,
  // DMA control
  REG_DMA0SAD = 0x58,
  REG_DMA0DAD = 0x5A,
  REG_DMA0CNT_L = 0x5C,
  REG_DMA0CNT_H = 0x5D,
  REG_DMA1SAD = 0x5E,
  REG_DMA1DAD = 0x60,
  REG_DMA1CNT_L = 0x62,
  REG_DMA1CNT_H = 0x63,
  REG_DMA2SAD = 0x64,
  REG_DMA2DAD = 0x66,
  REG_DMA2CNT_L = 0x68,
  REG_DMA2CNT_H = 0x69,
  REG_DMA3SAD = 0x6A,
  REG_DMA3DAD = 0x6C,
  REG_DMA3CNT_L = 0x6E,
  REG_DMA3CNT_H = 0x6F,
  // Timers
  REG_TM0D = 0x80,
  REG_TM0CNT = 0x81,
  REG_TM1D = 0x82,
  REG_TM1CNT = 0x83,
  REG_TM2D = 0x84,
  REG_TM2CNT = 0x85,
  REG_TM3D = 0x86,
  REG_TM3CNT = 0x87,
  REG_P1 = 0x098,
  REG_P1CNT = 0x099,
  REG_RCNT = 0x9A,
  REG_IE = 0x100,
  REG_IF = 0x101,
  REG_IME = 0x104,
  REG_HALTCNT = 0x180
} hardware_register;

typedef enum
{
  FLASH_DEVICE_UNDEFINED       = 0x00,
  FLASH_DEVICE_MACRONIX_64KB   = 0x1C,
  FLASH_DEVICE_AMTEL_64KB      = 0x3D,
  FLASH_DEVICE_SST_64K         = 0xD4,
  FLASH_DEVICE_PANASONIC_64KB  = 0x1B,
  FLASH_DEVICE_MACRONIX_128KB  = 0x09
} flash_device_id_type;

typedef enum
{
  FLASH_MANUFACTURER_MACRONIX  = 0xC2,
  FLASH_MANUFACTURER_AMTEL     = 0x1F,
  FLASH_MANUFACTURER_PANASONIC = 0x32,
  FLASH_MANUFACTURER_SST       = 0xBF
} flash_manufacturer_id_type;

u8 function_cc read_memory8(u32 address);
u32 read_memory8s(u32 address);
u32 function_cc read_memory16(u32 address);
u16 function_cc read_memory16_signed(u32 address);
u32 read_memory16s(u32 address);
u32 function_cc read_memory32(u32 address);
cpu_alert_type function_cc write_memory8(u32 address, u8 value);
cpu_alert_type function_cc write_memory16(u32 address, u16 value);
cpu_alert_type function_cc write_memory32(u32 address, u32 value);
u32 function_cc read_eeprom(void);
void function_cc write_eeprom(u32 address, u32 value);
u8 read_backup(u32 address);
void function_cc write_backup(u32 address, u32 value);
void function_cc write_rtc(u32 address, u32 value);

/* EDIT: Shouldn't this be extern ?! */
extern const u32 waitstate_cycles_sequential[16][3];

extern u32 gamepak_size;
extern char gamepak_title[13];
extern char gamepak_code[5];
extern char gamepak_maker[3];
extern char gamepak_filename[512];

cpu_alert_type dma_transfer(unsigned dma_chan);
u8 *memory_region(u32 address, u32 *memory_limit);
u32 load_gamepak(const struct retro_game_info* info, const char *name);
u32 load_backup(char *name);
s32 load_bios(char *name);
void update_backup(void);
void init_memory(void);
void init_gamepak_buffer(void);
void memory_term(void);
u8 *load_gamepak_page(u32 physical_index);

extern u32 oam_update;
extern u32 gbc_sound_update;
extern u32 gbc_sound_wave_update;
extern dma_transfer_type dma[DMA_CHAN_CNT];

extern u8 open_gba_bios_rom[1024*16];
extern u32 bios_read_protect;
extern u16 palette_ram[512];
extern u16 oam_ram[512];
extern u16 palette_ram_converted[512];
extern u16 io_registers[512];
extern u8 vram[1024 * 96];
extern u8 bios_rom[1024 * 16];
// Double buffer used for SMC detection
extern u8 ewram[1024 * 256 * 2];
extern u8 iwram[1024 * 32 * 2];

extern u8 *memory_map_read[8 * 1024];

extern u32 reg[64];

extern flash_device_id_type flash_device_id;

typedef enum
{
  BACKUP_SRAM,
  BACKUP_FLASH,
  BACKUP_EEPROM,
  BACKUP_NONE
} backup_type_type;

typedef enum
{
  SRAM_SIZE_32KB,
  SRAM_SIZE_64KB
} sram_size_type;

typedef enum
{
  FLASH_BASE_MODE,
  FLASH_ERASE_MODE,
  FLASH_ID_MODE,
  FLASH_WRITE_MODE,
  FLASH_BANKSWITCH_MODE
} flash_mode_type;

typedef enum
{
  FLASH_SIZE_64KB,
  FLASH_SIZE_128KB
} flash_size_type;


extern backup_type_type backup_type;
extern sram_size_type sram_size;
extern flash_size_type flash_size;

typedef enum
{
  EEPROM_512_BYTE,
  EEPROM_8_KBYTE
} eeprom_size_type;

typedef enum
{
  EEPROM_BASE_MODE,
  EEPROM_READ_MODE,
  EEPROM_READ_HEADER_MODE,
  EEPROM_ADDRESS_MODE,
  EEPROM_WRITE_MODE,
  EEPROM_WRITE_ADDRESS_MODE,
  EEPROM_ADDRESS_FOOTER_MODE,
  EEPROM_WRITE_FOOTER_MODE
} eeprom_mode_type;

extern eeprom_size_type eeprom_size;

extern u8 gamepak_backup[1024 * 128];

// Page sticky bit routines
extern u32 gamepak_sticky_bit[1024/32];
static inline void touch_gamepak_page(u32 physical_index)
{
  u32 idx = (physical_index >> 5) & 31;
  u32 bof = physical_index & 31;

  gamepak_sticky_bit[idx] |= (1 << bof);
}

static inline void clear_gamepak_stickybits(void)
{
  memset(gamepak_sticky_bit, 0, sizeof(gamepak_sticky_bit));
}

unsigned memory_write_savestate(u8 *dst);
bool memory_read_savestate(const u8*src);

#endif
