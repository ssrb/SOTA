/************************************************
 *
 * Author: crabfists
 * Date: 7.13.2008
 *
 ************************************************/

#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>

struct customData
{
    const char *name;
    ulong adr;
    unsigned char rw, special;
};

/* this table and some code below based on/copied from WinUAE source code
 * (c) 1995 Bernd Schmidt
 * (c) 2006 Toni Wilen
 */

/* This table was generated from the list of AGA chip names in
 * AGA.guide available on aminet. It could well have errors in it. */


const struct customData custd[] =
{
#if 0
    { "BLTDDAT",  0xdff000 }, /* Blitter dest. early read (dummy address) */
#endif
    { "DMACONR",  0xdff002, 1 }, /* Dma control (and blitter status) read */
    { "VPOSR",    0xdff004, 1 }, /* Read vert most sig. bits (and frame flop */
    { "VHPOSR",   0xdff006, 1 }, /* Read vert and horiz position of beam */
#if 0
    { "DSKDATR",  0xdff008 }, /* Disk data early read (dummy address) */
#endif
    { "JOY0DAT",  0xdff00A, 1 }, /* Joystick-mouse 0 data (vert,horiz) */
    { "JOT1DAT",  0xdff00C, 1 }, /* Joystick-mouse 1 data (vert,horiz) */
    { "CLXDAT",   0xdff00E, 1 }, /* Collision data reg. (read and clear) */
    { "ADKCONR",  0xdff010, 1 }, /* Audio,disk control register read */
    { "POT0DAT",  0xdff012, 1 }, /* Pot counter pair 0 data (vert,horiz) */
    { "POT1DAT",  0xdff014, 1 }, /* Pot counter pair 1 data (vert,horiz) */
    { "POTGOR",   0xdff016, 1 }, /* Pot pin data read */
    { "SERDATR",  0xdff018, 1 }, /* Serial port data and status read */
    { "DSKBYTR",  0xdff01A, 1 }, /* Disk data byte and status read */
    { "INTENAR",  0xdff01C, 1 }, /* Interrupt enable bits read */
    { "INTREQR",  0xdff01E, 1 }, /* Interrupt request bits read */
    { "DSKPTH",   0xdff020, 2, 1 }, /* Disk pointer (high 5 bits) */
    { "DSKPTL",   0xdff022, 2, 2 }, /* Disk pointer (low 15 bits) */
    { "DSKLEN",   0xdff024, 2, 0 }, /* Disk lentgh */
#if 0
    { "DSKDAT",   0xdff026 }, /* Disk DMA data write */
    { "REFPTR",   0xdff028 }, /* Refresh pointer */
#endif
    { "VPOSW",    0xdff02A, 2, 0 }, /* Write vert most sig. bits(and frame flop) */
    { "VHPOSW",   0xdff02C, 2, 0 }, /* Write vert and horiz pos of beam */
    { "COPCON",   0xdff02e, 2, 0 }, /* Coprocessor control reg (CDANG) */
    { "SERDAT",   0xdff030, 2, 0 }, /* Serial port data and stop bits write */
    { "SERPER",   0xdff032, 2, 0 }, /* Serial port period and control */
    { "POTGO",    0xdff034, 2, 0 }, /* Pot count start,pot pin drive enable data */
    { "JOYTEST",  0xdff036, 2, 0 }, /* Write to all 4 joystick-mouse counters at once */
    { "STREQU",   0xdff038, 2, 0 }, /* Strobe for horiz sync with VB and EQU */
    { "STRVBL",   0xdff03A, 2, 0 }, /* Strobe for horiz sync with VB (vert blank) */
    { "STRHOR",   0xdff03C, 2, 0 }, /* Strobe for horiz sync */
    { "STRLONG",  0xdff03E, 2, 0 }, /* Strobe for identification of long horiz line */
    { "BLTCON0",  0xdff040, 2, 0 }, /* Blitter control reg 0 */
    { "BLTCON1",  0xdff042, 2, 0 }, /* Blitter control reg 1 */
    { "BLTAFWM",  0xdff044, 2, 0 }, /* Blitter first word mask for source A */
    { "BLTALWM",  0xdff046, 2, 0 }, /* Blitter last word mask for source A */
    { "BLTCPTH",  0xdff048, 2, 1 }, /* Blitter pointer to source C (high 5 bits) */
    { "BLTCPTL",  0xdff04A, 2, 2 }, /* Blitter pointer to source C (low 15 bits) */
    { "BLTBPTH",  0xdff04C, 2, 1 }, /* Blitter pointer to source B (high 5 bits) */
    { "BLTBPTL",  0xdff04E, 2, 2 }, /* Blitter pointer to source B (low 15 bits) */
    { "BLTAPTH",  0xdff050, 2, 1 }, /* Blitter pointer to source A (high 5 bits) */
    { "BLTAPTL",  0xdff052, 2, 2 }, /* Blitter pointer to source A (low 15 bits) */
    { "BPTDPTH",  0xdff054, 2, 1 }, /* Blitter pointer to destn  D (high 5 bits) */
    { "BLTDPTL",  0xdff056, 2, 2 }, /* Blitter pointer to destn  D (low 15 bits) */
    { "BLTSIZE",  0xdff058, 2, 0 }, /* Blitter start and size (win/width,height) */
    { "BLTCON0L", 0xdff05A, 2, 4 }, /* Blitter control 0 lower 8 bits (minterms) */
    { "BLTSIZV",  0xdff05C, 2, 4 }, /* Blitter V size (for 15 bit vert size) */
    { "BLTSIZH",  0xdff05E, 2, 4 }, /* Blitter H size & start (for 11 bit H size) */
    { "BLTCMOD",  0xdff060, 2, 0 }, /* Blitter modulo for source C */
    { "BLTBMOD",  0xdff062, 2, 0 }, /* Blitter modulo for source B */
    { "BLTAMOD",  0xdff064, 2, 0 }, /* Blitter modulo for source A */
    { "BLTDMOD",  0xdff066, 2, 0 }, /* Blitter modulo for destn  D */
#if 0
    { "Unknown",  0xdff068 }, /* Unknown or Unused */
    { "Unknown",  0xdff06a }, /* Unknown or Unused */
    { "Unknown",  0xdff06c }, /* Unknown or Unused */
    { "Unknown",  0xdff06e }, /* Unknown or Unused */
#endif
    { "BLTCDAT",  0xdff070, 2, 0 }, /* Blitter source C data reg */
    { "BLTBDAT",  0xdff072, 2, 0 }, /* Blitter source B data reg */
    { "BLTADAT",  0xdff074, 2, 0 }, /* Blitter source A data reg */
    { "BLTDDAT",  0xdff076, 2, 0 }, /* Blitter destination reg */
#if 0
    { "SPRHDAT",  0xdff078 }, /* Ext logic UHRES sprite pointer and data identifier */
    { "BPLHDAT",  0xdff07A }, /* Ext logic UHRES bit plane identifier */
#endif
    { "LISAID",   0xdff07C, 1, 8 }, /* Chip revision level for Denise/Lisa */
    { "DSKSYNC",  0xdff07E, 2 }, /* Disk sync pattern reg for disk read */
    { "COP1LCH",  0xdff080, 2, 1 }, /* Coprocessor first location reg (high 5 bits) */
    { "COP1LCL",  0xdff082, 2, 2 }, /* Coprocessor first location reg (low 15 bits) */
    { "COP2LCH",  0xdff084, 2, 1 }, /* Coprocessor second reg (high 5 bits) */
    { "COP2LCL",  0xdff086, 2, 2 }, /* Coprocessor second reg (low 15 bits) */
    { "COPJMP1",  0xdff088, 2 }, /* Coprocessor restart at first location */
    { "COPJMP2",  0xdff08A, 2 }, /* Coprocessor restart at second location */
#if 0
    { "COPINS",   0xdff08C }, /* Coprocessor inst fetch identify */
#endif
    { "DIWSTRT",  0xdff08E, 2 }, /* Display window start (upper left vert-hor pos) */
    { "DIWSTOP",  0xdff090, 2 }, /* Display window stop (lower right vert-hor pos) */
    { "DDFSTRT",  0xdff092, 2 }, /* Display bit plane data fetch start.hor pos */
    { "DDFSTOP",  0xdff094, 2 }, /* Display bit plane data fetch stop.hor pos */
    { "DMACON",   0xdff096, 2 }, /* DMA control write (clear or set) */
    { "CLXCON",   0xdff098, 2 }, /* Collision control */
    { "INTENA",   0xdff09A, 2 }, /* Interrupt enable bits (clear or set bits) */
    { "INTREQ",   0xdff09C, 2 }, /* Interrupt request bits (clear or set bits) */
    { "ADKCON",   0xdff09E, 2 }, /* Audio,disk,UART,control */
    { "AUD0LCH",  0xdff0A0, 2, 1 }, /* Audio channel 0 location (high 5 bits) */
    { "AUD0LCL",  0xdff0A2, 2, 2 }, /* Audio channel 0 location (low 15 bits) */
    { "AUD0LEN",  0xdff0A4, 2 }, /* Audio channel 0 lentgh */
    { "AUD0PER",  0xdff0A6, 2 }, /* Audio channel 0 period */
    { "AUD0VOL",  0xdff0A8, 2 }, /* Audio channel 0 volume */
    { "AUD0DAT",  0xdff0AA, 2 }, /* Audio channel 0 data */
#if 0
    { "Unknown",  0xdff0AC }, /* Unknown or Unused */
    { "Unknown",  0xdff0AE }, /* Unknown or Unused */
#endif
    { "AUD1LCH",  0xdff0B0, 2, 1 }, /* Audio channel 1 location (high 5 bits) */
    { "AUD1LCL",  0xdff0B2, 2, 2 }, /* Audio channel 1 location (low 15 bits) */
    { "AUD1LEN",  0xdff0B4, 2 }, /* Audio channel 1 lentgh */
    { "AUD1PER",  0xdff0B6, 2 }, /* Audio channel 1 period */
    { "AUD1VOL",  0xdff0B8, 2 }, /* Audio channel 1 volume */
    { "AUD1DAT",  0xdff0BA, 2 }, /* Audio channel 1 data */
#if 0
    { "Unknown",  0xdff0BC }, /* Unknown or Unused */
    { "Unknown",  0xdff0BE }, /* Unknown or Unused */
#endif
    { "AUD2LCH",  0xdff0C0, 2, 1 }, /* Audio channel 2 location (high 5 bits) */
    { "AUD2LCL",  0xdff0C2, 2, 2 }, /* Audio channel 2 location (low 15 bits) */
    { "AUD2LEN",  0xdff0C4, 2 }, /* Audio channel 2 lentgh */
    { "AUD2PER",  0xdff0C6, 2 }, /* Audio channel 2 period */
    { "AUD2VOL",  0xdff0C8, 2 }, /* Audio channel 2 volume */
    { "AUD2DAT",  0xdff0CA, 2 }, /* Audio channel 2 data */
#if 0
    { "Unknown",  0xdff0CC }, /* Unknown or Unused */
    { "Unknown",  0xdff0CE }, /* Unknown or Unused */
#endif
    { "AUD3LCH",  0xdff0D0, 2, 1 }, /* Audio channel 3 location (high 5 bits) */
    { "AUD3LCL",  0xdff0D2, 2, 2 }, /* Audio channel 3 location (low 15 bits) */
    { "AUD3LEN",  0xdff0D4, 2 }, /* Audio channel 3 lentgh */
    { "AUD3PER",  0xdff0D6, 2 }, /* Audio channel 3 period */
    { "AUD3VOL",  0xdff0D8, 2 }, /* Audio channel 3 volume */
    { "AUD3DAT",  0xdff0DA, 2 }, /* Audio channel 3 data */
#if 0
    { "Unknown",  0xdff0DC }, /* Unknown or Unused */
    { "Unknown",  0xdff0DE }, /* Unknown or Unused */
#endif
    { "BPL1PTH",  0xdff0E0, 2, 1 }, /* Bit plane pointer 1 (high 5 bits) */
    { "BPL1PTL",  0xdff0E2, 2, 2 }, /* Bit plane pointer 1 (low 15 bits) */
    { "BPL2PTH",  0xdff0E4, 2, 1 }, /* Bit plane pointer 2 (high 5 bits) */
    { "BPL2PTL",  0xdff0E6, 2, 2 }, /* Bit plane pointer 2 (low 15 bits) */
    { "BPL3PTH",  0xdff0E8, 2, 1 }, /* Bit plane pointer 3 (high 5 bits) */
    { "BPL3PTL",  0xdff0EA, 2, 2 }, /* Bit plane pointer 3 (low 15 bits) */
    { "BPL4PTH",  0xdff0EC, 2, 1 }, /* Bit plane pointer 4 (high 5 bits) */
    { "BPL4PTL",  0xdff0EE, 2, 2 }, /* Bit plane pointer 4 (low 15 bits) */
    { "BPL5PTH",  0xdff0F0, 2, 1 }, /* Bit plane pointer 5 (high 5 bits) */
    { "BPL5PTL",  0xdff0F2, 2, 2 }, /* Bit plane pointer 5 (low 15 bits) */
    { "BPL6PTH",  0xdff0F4, 2, 1|8 }, /* Bit plane pointer 6 (high 5 bits) */
    { "BPL6PTL",  0xdff0F6, 2, 2|8 }, /* Bit plane pointer 6 (low 15 bits) */
    { "BPL7PTH",  0xdff0F8, 2, 1|8 }, /* Bit plane pointer 7 (high 5 bits) */
    { "BPL7PTL",  0xdff0FA, 2, 2|8 }, /* Bit plane pointer 7 (low 15 bits) */
    { "BPL8PTH",  0xdff0FC, 2, 1|8 }, /* Bit plane pointer 8 (high 5 bits) */
    { "BPL8PTL",  0xdff0FE, 2, 2|8 }, /* Bit plane pointer 8 (low 15 bits) */
    { "BPLCON0",  0xdff100, 2 }, /* Bit plane control reg (misc control bits) */
    { "BPLCON1",  0xdff102, 2 }, /* Bit plane control reg (scroll val PF1,PF2) */
    { "BPLCON2",  0xdff104, 2 }, /* Bit plane control reg (priority control) */
    { "BPLCON3",  0xdff106, 2|8 }, /* Bit plane control reg (enhanced features) */
    { "BPL1MOD",  0xdff108, 2 }, /* Bit plane modulo (odd planes,or active- fetch lines if bitplane scan-doubling is enabled */
    { "BPL2MOD",  0xdff10A, 2 }, /* Bit plane modulo (even planes or inactive- fetch lines if bitplane scan-doubling is enabled */
    { "BPLCON4",  0xdff10C, 2|8 }, /* Bit plane control reg (bitplane and sprite masks) */
    { "CLXCON2",  0xdff10e, 2|8 }, /* Extended collision control reg */
    { "BPL1DAT",  0xdff110, 2 }, /* Bit plane 1 data (parallel to serial con- vert) */
    { "BPL2DAT",  0xdff112, 2 }, /* Bit plane 2 data (parallel to serial con- vert) */
    { "BPL3DAT",  0xdff114, 2 }, /* Bit plane 3 data (parallel to serial con- vert) */
    { "BPL4DAT",  0xdff116, 2 }, /* Bit plane 4 data (parallel to serial con- vert) */
    { "BPL5DAT",  0xdff118, 2 }, /* Bit plane 5 data (parallel to serial con- vert) */
    { "BPL6DAT",  0xdff11a, 2 }, /* Bit plane 6 data (parallel to serial con- vert) */
    { "BPL7DAT",  0xdff11c, 2|8 }, /* Bit plane 7 data (parallel to serial con- vert) */
    { "BPL8DAT",  0xdff11e, 2|8 }, /* Bit plane 8 data (parallel to serial con- vert) */
    { "SPR0PTH",  0xdff120, 2, 1 }, /* Sprite 0 pointer (high 5 bits) */
    { "SPR0PTL",  0xdff122, 2, 2 }, /* Sprite 0 pointer (low 15 bits) */
    { "SPR1PTH",  0xdff124, 2, 1 }, /* Sprite 1 pointer (high 5 bits) */
    { "SPR1PTL",  0xdff126, 2, 2 }, /* Sprite 1 pointer (low 15 bits) */
    { "SPR2PTH",  0xdff128, 2, 1 }, /* Sprite 2 pointer (high 5 bits) */
    { "SPR2PTL",  0xdff12A, 2, 2 }, /* Sprite 2 pointer (low 15 bits) */
    { "SPR3PTH",  0xdff12C, 2, 1 }, /* Sprite 3 pointer (high 5 bits) */
    { "SPR3PTL",  0xdff12E, 2, 2 }, /* Sprite 3 pointer (low 15 bits) */
    { "SPR4PTH",  0xdff130, 2, 1 }, /* Sprite 4 pointer (high 5 bits) */
    { "SPR4PTL",  0xdff132, 2, 2 }, /* Sprite 4 pointer (low 15 bits) */
    { "SPR5PTH",  0xdff134, 2, 1 }, /* Sprite 5 pointer (high 5 bits) */
    { "SPR5PTL",  0xdff136, 2, 2 }, /* Sprite 5 pointer (low 15 bits) */
    { "SPR6PTH",  0xdff138, 2, 1 }, /* Sprite 6 pointer (high 5 bits) */
    { "SPR6PTL",  0xdff13A, 2, 2 }, /* Sprite 6 pointer (low 15 bits) */
    { "SPR7PTH",  0xdff13C, 2, 1 }, /* Sprite 7 pointer (high 5 bits) */
    { "SPR7PTL",  0xdff13E, 2, 2 }, /* Sprite 7 pointer (low 15 bits) */
    { "SPR0POS",  0xdff140, 2 }, /* Sprite 0 vert-horiz start pos data */
    { "SPR0CTL",  0xdff142, 2 }, /* Sprite 0 position and control data */
    { "SPR0DATA", 0xdff144, 2 }, /* Sprite 0 image data register A */
    { "SPR0DATB", 0xdff146, 2 }, /* Sprite 0 image data register B */
    { "SPR1POS",  0xdff148, 2 }, /* Sprite 1 vert-horiz start pos data */
    { "SPR1CTL",  0xdff14A, 2 }, /* Sprite 1 position and control data */
    { "SPR1DATA", 0xdff14C, 2 }, /* Sprite 1 image data register A */
    { "SPR1DATB", 0xdff14E, 2 }, /* Sprite 1 image data register B */
    { "SPR2POS",  0xdff150, 2 }, /* Sprite 2 vert-horiz start pos data */
    { "SPR2CTL",  0xdff152, 2 }, /* Sprite 2 position and control data */
    { "SPR2DATA", 0xdff154, 2 }, /* Sprite 2 image data register A */
    { "SPR2DATB", 0xdff156, 2 }, /* Sprite 2 image data register B */
    { "SPR3POS",  0xdff158, 2 }, /* Sprite 3 vert-horiz start pos data */
    { "SPR3CTL",  0xdff15A, 2 }, /* Sprite 3 position and control data */
    { "SPR3DATA", 0xdff15C, 2 }, /* Sprite 3 image data register A */
    { "SPR3DATB", 0xdff15E, 2 }, /* Sprite 3 image data register B */
    { "SPR4POS",  0xdff160, 2 }, /* Sprite 4 vert-horiz start pos data */
    { "SPR4CTL",  0xdff162, 2 }, /* Sprite 4 position and control data */
    { "SPR4DATA", 0xdff164, 2 }, /* Sprite 4 image data register A */
    { "SPR4DATB", 0xdff166, 2 }, /* Sprite 4 image data register B */
    { "SPR5POS",  0xdff168, 2 }, /* Sprite 5 vert-horiz start pos data */
    { "SPR5CTL",  0xdff16A, 2 }, /* Sprite 5 position and control data */
    { "SPR5DATA", 0xdff16C, 2 }, /* Sprite 5 image data register A */
    { "SPR5DATB", 0xdff16E, 2 }, /* Sprite 5 image data register B */
    { "SPR6POS",  0xdff170, 2 }, /* Sprite 6 vert-horiz start pos data */
    { "SPR6CTL",  0xdff172, 2 }, /* Sprite 6 position and control data */
    { "SPR6DATA", 0xdff174, 2 }, /* Sprite 6 image data register A */
    { "SPR6DATB", 0xdff176, 2 }, /* Sprite 6 image data register B */
    { "SPR7POS",  0xdff178, 2 }, /* Sprite 7 vert-horiz start pos data */
    { "SPR7CTL",  0xdff17A, 2 }, /* Sprite 7 position and control data */
    { "SPR7DATA", 0xdff17C, 2 }, /* Sprite 7 image data register A */
    { "SPR7DATB", 0xdff17E, 2 }, /* Sprite 7 image data register B */
    { "COLOR00",  0xdff180, 2 }, /* Color table 00 */
    { "COLOR01",  0xdff182, 2 }, /* Color table 01 */
    { "COLOR02",  0xdff184, 2 }, /* Color table 02 */
    { "COLOR03",  0xdff186, 2 }, /* Color table 03 */
    { "COLOR04",  0xdff188, 2 }, /* Color table 04 */
    { "COLOR05",  0xdff18A, 2 }, /* Color table 05 */
    { "COLOR06",  0xdff18C, 2 }, /* Color table 06 */
    { "COLOR07",  0xdff18E, 2 }, /* Color table 07 */
    { "COLOR08",  0xdff190, 2 }, /* Color table 08 */
    { "COLOR09",  0xdff192, 2 }, /* Color table 09 */
    { "COLOR10",  0xdff194, 2 }, /* Color table 10 */
    { "COLOR11",  0xdff196, 2 }, /* Color table 11 */
    { "COLOR12",  0xdff198, 2 }, /* Color table 12 */
    { "COLOR13",  0xdff19A, 2 }, /* Color table 13 */
    { "COLOR14",  0xdff19C, 2 }, /* Color table 14 */
    { "COLOR15",  0xdff19E, 2 }, /* Color table 15 */
    { "COLOR16",  0xdff1A0, 2 }, /* Color table 16 */
    { "COLOR17",  0xdff1A2, 2 }, /* Color table 17 */
    { "COLOR18",  0xdff1A4, 2 }, /* Color table 18 */
    { "COLOR19",  0xdff1A6, 2 }, /* Color table 19 */
    { "COLOR20",  0xdff1A8, 2 }, /* Color table 20 */
    { "COLOR21",  0xdff1AA, 2 }, /* Color table 21 */
    { "COLOR22",  0xdff1AC, 2 }, /* Color table 22 */
    { "COLOR23",  0xdff1AE, 2 }, /* Color table 23 */
    { "COLOR24",  0xdff1B0, 2 }, /* Color table 24 */
    { "COLOR25",  0xdff1B2, 2 }, /* Color table 25 */
    { "COLOR26",  0xdff1B4, 2 }, /* Color table 26 */
    { "COLOR27",  0xdff1B6, 2 }, /* Color table 27 */
    { "COLOR28",  0xdff1B8, 2 }, /* Color table 28 */
    { "COLOR29",  0xdff1BA, 2 }, /* Color table 29 */
    { "COLOR30",  0xdff1BC, 2 }, /* Color table 30 */
    { "COLOR31",  0xdff1BE, 2 }, /* Color table 31 */
    { "HTOTAL",   0xdff1C0, 2|4 }, /* Highest number count in horiz line (VARBEAMEN = 1) */
    { "HSSTOP",   0xdff1C2, 2|4 }, /* Horiz line pos for HSYNC stop */
    { "HBSTRT",   0xdff1C4, 2|4 }, /* Horiz line pos for HBLANK start */
    { "HBSTOP",   0xdff1C6, 2|4 }, /* Horiz line pos for HBLANK stop */
    { "VTOTAL",   0xdff1C8, 2|4 }, /* Highest numbered vertical line (VARBEAMEN = 1) */
    { "VSSTOP",   0xdff1CA, 2|4 }, /* Vert line for VBLANK start */
    { "VBSTRT",   0xdff1CC, 2|4 }, /* Vert line for VBLANK start */
    { "VBSTOP",   0xdff1CE, 2|4 }, /* Vert line for VBLANK stop */
#if 0
    { "SPRHSTRT", 0xdff1D0 }, /* UHRES sprite vertical start */
    { "SPRHSTOP", 0xdff1D2 }, /* UHRES sprite vertical stop */
    { "BPLHSTRT", 0xdff1D4 }, /* UHRES bit plane vertical stop */
    { "BPLHSTOP", 0xdff1D6 }, /* UHRES bit plane vertical stop */
    { "HHPOSW",   0xdff1D8 }, /* DUAL mode hires H beam counter write */
    { "HHPOSR",   0xdff1DA }, /* DUAL mode hires H beam counter read */
#endif
    { "BEAMCON0", 0xdff1DC, 2|4 }, /* Beam counter control register (SHRES,UHRES,PAL) */
    { "HSSTRT",   0xdff1DE, 2|4 }, /* Horizontal sync start (VARHSY) */
    { "VSSTRT",   0xdff1E0, 2|4 }, /* Vertical sync start (VARVSY) */
    { "HCENTER",  0xdff1E2, 2|4 }, /* Horizontal pos for vsync on interlace */
    { "DIWHIGH",  0xdff1E4, 2|4 }, /* Display window upper bits for start/stop */
#if 0
    { "BPLHMOD",  0xdff1E6 }, /* UHRES bit plane modulo */
    { "SPRHPTH",  0xdff1E8 }, /* UHRES sprite pointer (high 5 bits) */
    { "SPRHPTL",  0xdff1EA }, /* UHRES sprite pointer (low 15 bits) */
    { "BPLHPTH",  0xdff1EC }, /* VRam (UHRES) bitplane pointer (hi 5 bits) */
    { "BPLHPTL",  0xdff1EE }, /* VRam (UHRES) bitplane pointer (lo 15 bits) */
    { "RESERVED", 0xdff1F0 }, /* Reserved (forever i guess!) */
    { "RESERVED", 0xdff1F2 }, /* Reserved (forever i guess!) */
    { "RESERVED", 0xdff1F4 }, /* Reserved (forever i guess!) */
    { "RESERVED", 0xdff1F6 }, /* Reserved (forever i guess!) */
    { "RESERVED", 0xdff1F8 }, /* Reserved (forever i guess!) */
    { "RESERVED", 0xdff1Fa }, /* Reserved (forever i guess!) */
#endif
    { "FMODE",    0xdff1FC, 2|8 }, /* Fetch mode register */
    { "NO-OP(NULL)", 0xdff1FE },   /*   Can also indicate last 2 or 3 refresh
					    cycles or the restart of the COPPER after lockup.*/
    { NULL }
};

/*********************************************************************
* Function: init
*
* init is a plugin_t function. It is executed when the plugin is
* initially loaded by IDA.
* Three return codes are possible:
*    PLUGIN_SKIP - Plugin is unloaded and not made available
*    PLUGIN_KEEP - Plugin is kept in memory
*    PLUGIN_OK   - Plugin will be loaded upon 1st use
*
* Check are added here to ensure the plug-in is compatible with
* the current disassembly.
*********************************************************************/
int init(void)
{
	return PLUGIN_OK;
}

/*********************************************************************
* Function: term
*
* term is a plugin_t function. It is executed when the plugin is
* unloading. Typically cleanup code is executed here.
*********************************************************************/
void term(void)
{

	return;
}

void DisassembleWait (unsigned long insn, char* str, int strLen)
{
    int vp, hp, ve, he, bfd, v_mask, h_mask;
	char tmpStr[47] = {0};

    vp = (insn & 0xff000000) >> 24;
    hp = (insn & 0x00fe0000) >> 16;
    ve = (insn & 0x00007f00) >> 8;
    he = (insn & 0x000000fe);
    bfd = (insn & 0x00008000) >> 15;

    /* bit15 can never be masked out*/
    v_mask = vp & (ve | 0x80);
    h_mask = hp & he;
    if (v_mask > 0) 
	{
		qstrncat(str, " vpos ", strLen);
		if (ve != 0x7f) 
		{
			//console_out_f ("& 0x%02x ", ve);
			qsnprintf(tmpStr, 31, "& 0x%02x ", ve);
			qstrncat(str, tmpStr, strLen);
		}
		qsnprintf(tmpStr, 31, ">= 0x%02x", v_mask);
		qstrncat(str, tmpStr, strLen);
    }

    if (he > 0) 
	{
		if (v_mask > 0) 
		{
			qstrncat(str, " and", strLen);
		}

		qstrncat(str, " hpos ", strLen);
		if (he != 0xfe) 
		{
			qsnprintf(tmpStr, 31, "& 0x%02x ", he);
			qstrncat(str, tmpStr, 31);
		}
		qsnprintf(tmpStr, 31, ">= 0x%02x", h_mask);
		qstrncat(str, tmpStr, strLen);
	} 
	else 
	{
		qstrncat(str, ", ignore horizontal.", strLen);
    }

	qsnprintf(tmpStr, 47, "\nVP 0x%02x, VE 0x%02x; HP 0x%02x, HE 0x%02x; BFD %d", vp, ve, hp, he, bfd);
	qstrncat(str, tmpStr, strLen);
}

//*********************************************************************
// Function: CopperListSearch
// attempt to decode copper instruction at specified address
//*********************************************************************

bool DecodeCopperInstruction(ea_t ea)
{
	bool bContinue = true;
	flags_t flags = getFlags(ea);
	ulong insn = get_long(ea);

	ulong insn_type = insn & 0x00010001;

	const int SLEN = 256;
	char comment[SLEN] = {0};

	switch (insn_type) 
	{
		case 0x00010000: /* WAIT insn */
			strncpy_s(comment, SLEN-1, "Wait for ", SLEN-1);
			DisassembleWait(insn, comment, SLEN-1);

			if (insn == 0xfffffffe)
			{
				qstrncat(comment, "\nEnd of Copperlist", SLEN);
				bContinue = false;
			}
		break;

		case 0x00010001: /* SKIP insn */
		{
			const char* strSkip = "Skip if";
			strncpy_s(comment, SLEN-1, strSkip, SLEN-1);	

			DisassembleWait(insn, comment, SLEN-1);
		}
		break;

		case 0x00000000:
		case 0x00000001: /* MOVE insn */
		{
			int addr = (insn >> 16) & 0x1fe;
			int i = 0;
			while (custd[i].name) 
			{
				if (custd[i].adr == addr + 0xdff000)
					break;
				i++;
			}
			if (custd[i].name)
				_snprintf(comment, SLEN-1, "%s := 0x%04lx", custd[i].name, insn & 0xffff);
			else
				_snprintf(comment, SLEN-1, "%04x := 0x%04lx", addr, insn & 0xffff);
		}
		break;

		default:
			strncpy_s(comment, SLEN-1, "UNKNOWN INSTRUCTION", 127);
			msg("UNKNOWN INSTRUCTION");
			return false;
	}
	
	set_cmt(ea, comment, false);

	// convert to long word
	if ((isData(flags) && !isDwrd(flags)) || isUnknown(flags))
	{
		if ( doDwrd(ea, 4) == false)
			msg("doDwrd %x failed. isdata %d. isunknown %d\n", ea, isData(flags), isUnknown(flags));
		// set trailing zeroes
		set_lzero(ea, 0);
	}

	return bContinue;
}

//*********************************************************************
// Function: CopperListSearch
// Llooks for a copper list given a start address. If finds one it
// returns the address of the last instruction.
// If it does not find one it returns BADADDR
//*********************************************************************
ea_t CopperListSearch(ea_t ea)
{
	ea_t addr = ea;
	
	while (addr != BADADDR)
	{
		ulong value = get_long(addr);
		if (value == 0xfffffffe)
			return addr;

		flags_t flags = getFlags(addr);
		if (isCode(flags))
			return BADADDR; 

		addr = nextaddr(addr);
	}

	return BADADDR;
}

/*********************************************************************
* Function: run
*
* run is a plugin_t function. It is executed when the plugin is run.
*
* The argument 'arg' can be passed by adding an entry in
* plugins.cfg or passed manually via IDC:
*
*   success RunPlugin(string name, long arg);
*********************************************************************/
void run(int arg)
{
	//  Uncomment the following code to allow plugin unloading.
	//  This allows the editing/building of the plugin without
	//  restarting IDA.
	//
	//  1. to unload the plugin execute the following IDC statement:
	//        RunPlugin("AmigaCopper", 415);
	//  2. Make changes to source code and rebuild within Visual Studio
	//  3. Copy plugin to IDA plugin dir
	//     (may be automatic if option was selected within wizard)
	//  4. Run plugin via the menu, hotkey, or IDC statement
	//

	#ifdef _DEBUG
	if (arg == 415)
 	{
 		PLUGIN.flags |= PLUGIN_UNL;
 		msg("Unloading Annotate copperlist plugin...\n");
		return;
 	}
	#endif

	ea_t copListStart = get_screen_ea();
	msg("Searching for copperlist from address %x...\n", copListStart);
	
	ea_t copListEnd = CopperListSearch(copListStart);

	if (copListEnd == BADADDR)
	{
		msg("Could not find copperlist.\n");
		return;
	}

	msg("Found copperlist. Start = 0x%x, Last instruction = 0x%x, Size = %d bytes. Annotating...\n", copListStart, copListEnd, copListEnd-copListStart+4);

	// convert all bytes to unknowns to start with
	do_unknown_range(copListStart, copListEnd-copListStart, false);

	ea_t addr = copListStart;
	while (addr != BADADDR)
	{
		if (DecodeCopperInstruction(addr) == false)
			break;

		addr = nextaddr(addr);
	}

	msg("Done\n");
 	
	return;
}

char comment[] 	= "Short one line description about the plugin";
char help[] 	= "My plugin:\n"
                  "\n"
                  "Multi-line\n"
                  "description\n";

/* Plugin name listed in (Edit | Plugins) */
char wanted_name[] 	= "Annotate copper list";

/* plug-in hotkey */
char wanted_hotkey[] 	= "Alt+1";

/* defines the plugins interface to IDA */
plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  0,              // plugin flags
  init,           // initialize
  term,           // terminate. this pointer may be NULL.
  run,            // invoke plugin
  comment,        // comment about the plugin
  help,           // multiline help about the plugin
  wanted_name,    // the preferred short name of the plugin
  wanted_hotkey   // the preferred hotkey to run the plugin
};

