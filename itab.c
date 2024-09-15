/*
 * This file is part of 'pdp', a PDP-11 simulator.
 *
 * For information contact:
 *
 *   Computer Science House
 *   Attn: Eric Edwards
 *   Box 861
 *   25 Andrews Memorial Drive
 *   Rochester, NY 14623
 *
 * Email:  mag@potter.csh.rit.edu
 * FTP:    ftp.csh.rit.edu:/pub/csh/mag/pdp.tar.Z
 * 
 * Copyright 1994, Eric A. Edwards
 *
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies.  Eric A. Edwards makes no
 * representations about the suitability of this software
 * for any purpose.  It is provided "as is" without expressed
 * or implied warranty.
 */

/*
 * itab.c - Instruction decode table.
 */

#include "defines.h"

extern int illegal(pdp_regs *p);
extern int adc(pdp_regs *p);
extern int adcb(pdp_regs *p);
extern int add(pdp_regs *p);
extern int ash(pdp_regs *p);
extern int ashc(pdp_regs *p);
extern int asl(pdp_regs *p);
extern int aslb(pdp_regs *p);
extern int asr(pdp_regs *p);
extern int asrb(pdp_regs *p);
extern int bcc(pdp_regs *p);
extern int bcs(pdp_regs *p);
extern int beq(pdp_regs *p);
extern int bge(pdp_regs *p);
extern int bgt(pdp_regs *p);
extern int bhi(pdp_regs *p);
extern int bic(pdp_regs *p);
extern int bicb(pdp_regs *p);
extern int bis(pdp_regs *p);
extern int bisb(pdp_regs *p);
extern int bit(pdp_regs *p);
extern int bitb(pdp_regs *p);
extern int ble(pdp_regs *p);
extern int blos(pdp_regs *p);
extern int blt(pdp_regs *p);
extern int bmi(pdp_regs *p);
extern int bne(pdp_regs *p);
extern int bpl(pdp_regs *p);
extern int bpt(pdp_regs *p);
extern int br(pdp_regs *p);
extern int bvc(pdp_regs *p);
extern int bvs(pdp_regs *p);
extern int clr(pdp_regs *p);
extern int clrb(pdp_regs *p);
extern int ccc(pdp_regs *p);
extern int cmp(pdp_regs *p);
extern int cmpb(pdp_regs *p);
extern int com(pdp_regs *p);
extern int comb(pdp_regs *p);
extern int dec(pdp_regs *p);
extern int decb(pdp_regs *p);
extern int divide(pdp_regs *p);
extern int emt(pdp_regs *p);
extern int halt(pdp_regs *p);
extern int inc(pdp_regs *p);
extern int incb(pdp_regs *p);
extern int iot(pdp_regs *p);
extern int jmp(pdp_regs *p);
extern int jsr(pdp_regs *p);
extern int mark(pdp_regs *p);
extern int mfpd(pdp_regs *p);
extern int mfpi(pdp_regs *p);
extern int mfps(pdp_regs *p);
extern int mov(pdp_regs *p);
extern int movb(pdp_regs *p);
extern int mtpd(pdp_regs *p);
extern int mtpi(pdp_regs *p);
extern int mtps(pdp_regs *p);
extern int mul(pdp_regs *p);
extern int neg(pdp_regs *p);
extern int negb(pdp_regs *p);
extern int busreset(pdp_regs *p);
extern int rol(pdp_regs *p);
extern int rolb(pdp_regs *p);
extern int ror(pdp_regs *p);
extern int rorb(pdp_regs *p);
extern int rti(pdp_regs *p);
extern int rts(pdp_regs *p);
extern int rtt(pdp_regs *p);
extern int sbc(pdp_regs *p);
extern int sbcb(pdp_regs *p);
extern int scc(pdp_regs *p);
extern int sob(pdp_regs *p);
extern int sub(pdp_regs *p);
extern int swabi(pdp_regs *p);
extern int sxt(pdp_regs *p);
extern int trap(pdp_regs *p);
extern int tst(pdp_regs *p);
extern int tstb(pdp_regs *p);
extern int waiti(pdp_regs *p);
extern int xor(pdp_regs *p);
extern int fis(pdp_regs *p);

struct _itab sitab0[64] = {
	halt, waiti, rti, bpt, iot, busreset, rtt, illegal,
	halt, halt, halt, halt, halt, halt, halt, halt,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal
};

struct _itab sitab1[64] = {
	rts, rts, rts, rts, rts, rts, rts, rts,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
	ccc, ccc, ccc, ccc, ccc, ccc, ccc, ccc,
	ccc, ccc, ccc, ccc, ccc, ccc, ccc, ccc,
	scc, scc, scc, scc, scc, scc, scc, scc,
	scc, scc, scc, scc, scc, scc, scc, scc
};

int dositab0( p )
register pdp_regs *p;
{
	return (sitab0[p->ir&077].func)( p );
}

int dositab1( p )
register pdp_regs *p;
{
	return (sitab1[p->ir&077].func)( p );
}

struct _itab itab[1024] = {
/*000*/	dositab0, jmp, dositab1, swabi, br, br, br, br,
/*001*/	bne, bne, bne, bne, beq, beq, beq, beq,
/*002*/	bge, bge, bge, bge, blt, blt, blt, blt,
/*003*/	bgt, bgt, bgt, bgt, ble, ble, ble, ble,
/*004*/	jsr, jsr, jsr, jsr, jsr, jsr, jsr, jsr,
/*005*/	clr, com, inc, dec, neg, adc, sbc, tst,
/*006*/	ror, rol, asr, asl, mark, illegal, illegal, sxt,
/*007*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*010*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*011*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*012*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*013*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*014*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*015*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*016*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*017*/	mov, mov, mov, mov, mov, mov, mov, mov,
/*020*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*021*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*022*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*023*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*024*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*025*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*026*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*027*/	cmp, cmp, cmp, cmp, cmp, cmp, cmp, cmp,
/*030*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*031*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*032*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*033*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*034*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*035*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*036*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*037*/	bit, bit, bit, bit, bit, bit, bit, bit,
/*040*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*041*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*042*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*043*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*044*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*045*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*046*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*047*/	bic, bic, bic, bic, bic, bic, bic, bic,
/*050*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*051*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*052*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*053*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*054*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*055*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*056*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*057*/	bis, bis, bis, bis, bis, bis, bis, bis,
/*060*/	add, add, add, add, add, add, add, add,
/*061*/	add, add, add, add, add, add, add, add,
/*062*/	add, add, add, add, add, add, add, add,
/*063*/	add, add, add, add, add, add, add, add,
/*064*/	add, add, add, add, add, add, add, add,
/*065*/	add, add, add, add, add, add, add, add,
/*066*/	add, add, add, add, add, add, add, add,
/*067*/	add, add, add, add, add, add, add, add,
#ifdef EIS_ALLOWED
/*070*/	mul, mul, mul, mul, mul, mul, mul, mul,
/*071*/	divide, divide, divide, divide, divide, divide, divide, divide,
/*072*/	ash, ash, ash, ash, ash, ash, ash, ash,
/*073*/	ashc, ashc, ashc, ashc, ashc, ashc, ashc, ashc,
#else
/*070*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*071*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
#ifdef SHIFTS_ALLOWED
/*072*/ ash, ash, ash, ash, ash, ash, ash, ash,
/*073*/ ashc, ashc, ashc, ashc, ashc, ashc, ashc, ashc,
#else
/*072*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*073*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
#endif
#endif
/*074*/	xor, xor, xor, xor, xor, xor, xor, xor,
/*075*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*076*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*077*/	sob, sob, sob, sob, sob, sob, sob, sob,
/*100*/	bpl, bpl, bpl, bpl, bmi, bmi, bmi, bmi,
/*101*/	bhi, bhi, bhi, bhi, blos, blos, blos, blos,
/*102*/	bvc, bvc, bvc, bvc, bvs, bvs, bvs, bvs,
/*103*/	bcc, bcc, bcc, bcc, bcs, bcs, bcs, bcs,
/*104*/	emt, emt, emt, emt, trap, trap, trap, trap,
/*105*/	clrb, comb, incb, decb, negb, adcb, sbcb, tstb,
/*106*/	rorb, rolb, asrb, aslb, mtps, illegal, illegal, mfps,
/*107*/	illegal, illegal, illegal, illegal, illegal, illegal, illegal, illegal,
/*110*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*111*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*112*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*113*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*114*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*115*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*116*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*117*/	movb, movb, movb, movb, movb, movb, movb, movb,
/*120*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*121*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*122*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*123*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*124*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*125*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*126*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*127*/	cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb, cmpb,
/*130*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*131*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*132*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*133*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*134*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*135*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*136*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*137*/	bitb, bitb, bitb, bitb, bitb, bitb, bitb, bitb,
/*140*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*141*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*142*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*143*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*144*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*145*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*146*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*147*/	bicb, bicb, bicb, bicb, bicb, bicb, bicb, bicb,
/*150*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*151*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*152*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*153*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*154*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*155*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*156*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*157*/	bisb, bisb, bisb, bisb, bisb, bisb, bisb, bisb,
/*160*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*161*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*162*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*163*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*164*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*165*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*166*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*167*/	sub, sub, sub, sub, sub, sub, sub, sub,
/*170*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*171*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*172*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*173*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*174*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*175*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*176*/	fis, fis, fis, fis, fis, fis, fis, fis,
/*177*/	fis, fis, fis, fis, fis, fis, fis, fis
};
