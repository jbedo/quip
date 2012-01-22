/*
 * This file is part of quip.
 *
 * Copyright (c) 2011 by Daniel C. Jones <dcjones@cs.washington.edu>
 *
 */


/*
 * assembler:
 * A dumb approximate de-novo assembler.
 *
 */


#ifndef QUIP_ASSEMBLER
#define QUIP_ASSEMBLER

#include "quip.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct assembler_t_ assembler_t;

assembler_t* assembler_alloc(
        quip_writer_t writer, void* writer_data,
        size_t assemble_k, size_t align_k, bool quick);
void         assembler_free(assembler_t*);

void assembler_add_seq(assembler_t*, const char* seq, size_t seqlen);
void assembler_assemble(assembler_t* A);


/* disassemble */
typedef struct disassembler_t_ disassembler_t;

disassembler_t* disassembler_alloc(quip_reader_t reader, void* reader_data);
void            disassembler_free(disassembler_t*);

void disassembler_read(disassembler_t*, seq_t* x, size_t n);

#endif

