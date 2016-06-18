/*-------------------------------------------------------------------------
 *
 * hio.h
 *	  POSTGRES heap access method input/output definitions.
 *
 *
 * Portions Copyright (c) 1996-2015, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/access/hio.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef HIO_H
#define HIO_H

#include "parser/access/heapam.h"
#include "parser/access/htup.h"
#include "parser/utils/relcache.h"
#include "parser/storage/buf.h"


/*
 * state for bulk inserts --- private___ to heapam.c and hio.c
 *
 * If current_buf isn't InvalidBuffer, then we are holding an extra pin
 * on that buffer.
 *
 * "typedef struct BulkInsertStateData *BulkInsertState" is in heapam.h
 */
typedef struct BulkInsertStateData
{
	BufferAccessStrategy strategy;		/* our BULKWRITE strategy object */
	Buffer		current_buf;	/* current insertion target page */
}	BulkInsertStateData;


extern void RelationPutHeapTuple(Relation relation, Buffer buffer,
					 HeapTuple tuple, bool token);
extern Buffer RelationGetBufferForTuple(Relation relation, Size len,
						  Buffer otherBuffer, int options,
						  BulkInsertState bistate,
						  Buffer *vmbuffer, Buffer *vmbuffer_other);

#endif   /* HIO_H */