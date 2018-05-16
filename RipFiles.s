*******************************************
*** 'STATE OF THE ART' FILE RIPPER	***
*******************************************

; rips out all files from Spaceballs 'State Of The Art' trackmo
; done by StingRay/[S]carab^Scoopex on 11-Jan-2oo5

	include	<./exec_lib.i>
	include	<./dos_lib.i>

START	move.l	$4.w,a6
	moveq	#0,d0
	lea	DOSname(pc),a1
	jsr	_LVOOpenLibrary(a6)
	lea	DOSbase(pc),a0
	move.l	d0,(a0)

	lea	TAB(pc),a2
.rip	move.w	(a2)+,d0
	bmi.b	.done
	move.w	(a2)+,d1
	bsr	BuildName
	mulu.w	#512*11,d0		; offset
	mulu.w	#512*11,d1		; length
	lea	fname(pc),a0
	lea	DISK(pc),a1
	add.l	d0,a1
	move.l	d1,d0
	bsr	DOS_SaveFile
	bra.b	.rip
.done	move.l	$4.w,a6
	move.l	DOSbase(pc),a1
	jsr	_LVOCloseLibrary(a6)
	moveq	#0,d0
	rts

BuildName
	movem.w	d0/d1,-(a7)
	lea	name(pc),a0
	bsr.b	.conv
	addq.w	#1,a0		; skip underscore
	move.w	d1,d0
	bsr.b	.conv
	movem.w	(a7)+,d0/d1
	rts

.conv	moveq	#3-1,d3		; max. 5 digits
	lea	.TAB(pc),a1
.loop	moveq	#-"0",d2
.loop2	sub.w	(a1),d0
	dbcs	d2,.loop2
	neg.b	d2
	move.b	d2,(a0)+
	add.w	(a1)+,d0
	dbf	d3,.loop
	rts

.TAB	dc.w	100
	dc.w	10
	dc.w	1

; first loader: 
TAB	dc.w	2,3		; ext. mem
	dc.w	5,7		; $409dc, loader module
	dc.w	12,6		; ext. +$3dfe
	dc.w	18,3		; ext. +$20000, decrunched to $6cb10, 3bpl picture
	dc.w	21,1		; $52000, code
	dc.w	22,2		; $4d000
	dc.w	24,36		; $1000, replayer+module

; second loader ($52000):
	dc.w	60,6		; $32800
	dc.w	66,4		; ext. +$40000
	dc.w	70,1		; $3e000, code
;
; third loader ($3e000):
	dc.w	71,1		; $50000; code
	dc.w	72,7		; ext. + $30000
;
; fourth loader: ($50000)
	dc.w	79,1		; code, $50000
	dc.w	80,5
;
; fifth loader: ($50000)
	dc.w	85,3		; $45000, code

; 6th loader: ($45000)
	dc.w	91,10		; $6cb10
	dc.w	101,2		; $50000, code
	dc.w	103,5		; ext. +$20000

; 7th loader: ($50000)
	dc.w	0108,1		; $40000, code

; 8th loader: ($40000)
	dc.w	109,1		; $50000, code
	dc.w	110,1		; $45000, code
	dc.w	111,3		; ext. $34080

; 9th loader
	dc.w	85,1		; $40000
 	dc.w	86,4		; ext. +$20000

; 10th loader ($45000)
	dc.w	114,4		; $50000, code
 	dc.w	118,9		; $6cb10

; 11th loader ($50000)
	dc.w	127,7		; $40000, code

; 12th loader ($40000)
	dc.w	134,5		; $4c000, code

; 13th loader ($4c000)
	dc.w	139,7		; $40000, code

; 14th loader ($40000)
	dc.w	146,8		; $4f000, code

; 15th loader ($4f000)
	dc.w	154,6		; $43000
	dc.w	88,2		; $40000, code

	dc.w	-1

DOSbase	dc.l	0
DOSname	dc.b	"dos.library",0
fname	dc.b	"RAM:SOTA"
name	dc.b	"000"
	dc.b	"_"
	dc.b	"000"
	dc.b	".bin",0

	CNOP	0,2

*******************************************
*** SAVE FILE				***
*******************************************

; IN:	a0: File Name
;	a1: File Buffer
;	d0: File Length

; OUT:	d0: Error Flag (0=Error, 1=OK)

DOS_SaveFile
	move.l	DOSbase(pc),a6
	move.l	a1,d5			; save FileBuffer
	move.l	d0,d6			; save FileLength
	move.l	a0,d1			; get FileName
	move.l	#1006,d2		; MODE_NEWFILE
	jsr	_LVOOpen(a6)
	move.l	d0,d7			; save FileHandle
	beq.b	.error
	move.l	d0,d1			; FileHandle
	move.l	d5,d2			; FileBuffer
	move.l	d6,d3			; FileLength
	jsr	_LVOWrite(a6)
	move.l	d7,d1			; get FileHandle
	jsr	_LVOClose(a6)
	moveq	#1,d0			; no Errors
.error	rts

DISK	incbin SOTA.dsk
