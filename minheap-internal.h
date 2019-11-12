/*
 * Copyright (c) 2007-2012 Niels Provos and Nick Mathewson
 *
 * Copyright (c) 2006 Maxim Yegorushkin <maxim.yegorushkin@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//公式
//  Key[i]<=key[2i+1]&&Key[i]<=key[2i+2]或者Key[i]>=Key[2i+1]&&key>=key[2i+2]
#ifndef MINHEAP_INTERNAL_H_INCLUDED_
#define MINHEAP_INTERNAL_H_INCLUDED_

#include "event2/event-config.h"
#include "evconfig-private.h"
#include "event2/event.h"
#include "event2/event_struct.h"
#include "event2/util.h"
#include "util-internal.h"
#include "mm-internal.h"

typedef struct min_heap
{
	//保存*event 的数组
	struct event** p;
	//n为元素个数 a为容量
	size_t n, a;
} min_heap_t;

static inline void	     min_heap_ctor_(min_heap_t* s);
static inline void	     min_heap_dtor_(min_heap_t* s);
static inline void	     min_heap_elem_init_(struct event* e);
static inline int	     min_heap_elt_is_top_(const struct event *e);
static inline int	     min_heap_empty_(min_heap_t* s);
static inline size_t	     min_heap_size_(min_heap_t* s);
static inline struct event*  min_heap_top_(min_heap_t* s);
static inline int	     min_heap_reserve_(min_heap_t* s, size_t n);
static inline int	     min_heap_push_(min_heap_t* s, struct event* e);
static inline struct event*  min_heap_pop_(min_heap_t* s);
static inline int	     min_heap_adjust_(min_heap_t *s, struct event* e);
static inline int	     min_heap_erase_(min_heap_t* s, struct event* e);
static inline void	     min_heap_shift_up_(min_heap_t* s, size_t hole_index, struct event* e);
static inline void	     min_heap_shift_up_unconditional_(min_heap_t* s, size_t hole_index, struct event* e);
static inline void	     min_heap_shift_down_(min_heap_t* s, size_t hole_index, struct event* e);

#define min_heap_elem_greater(a, b) \
	(evutil_timercmp(&(a)->ev_timeout, &(b)->ev_timeout, >))

void min_heap_ctor_(min_heap_t* s) { s->p = 0; s->n = 0; s->a = 0; }
void min_heap_dtor_(min_heap_t* s) { if (s->p) mm_free(s->p); }
void min_heap_elem_init_(struct event* e) { e->ev_timeout_pos.min_heap_idx = EV_SIZE_MAX; }
int min_heap_empty_(min_heap_t* s) { return 0 == s->n; }
size_t min_heap_size_(min_heap_t* s) { return s->n; }
struct event* min_heap_top_(min_heap_t* s) { return s->n ? *s->p : 0; }

int min_heap_push_(min_heap_t* s, struct event* e)
{
	//检查最小堆中内存是否够
	if(min_heap_reserve_(s, s->n+1))
		return -1;
	
	
}

struct event* min_heap_pop_(min_heap_t* s)
{

}

int min_heap_elt_is_top_(const struct event *e)
{

}

int min_heap_erase_(min_heap_t* s, struct event* e)
{

}

int min_heap_adjust_(min_heap_t *s, struct event *e)
{

}

//调整分配内存
int min_heap_reserve_(min_heap_t* s, size_t n)
{
		//容量不足
		if(s->a<n){
			struct event **p;
			//如果没有空间分配8  否则扩容两倍
			size_t a=s->a?2*s->a:8;
			//还是不足直接分配 n空间
			if(a<n)
				a=n;
			if(!(p=mm_realloc(s->p, a*sizeof *p)))
				//分配失败
				return -1;
			s->a=a;
			s->p=p;
			
		}
		return 0;
}

void min_heap_shift_up_unconditional_(min_heap_t* s, size_t hole_index, struct event* e)
{
   
}

void min_heap_shift_up_(min_heap_t* s, size_t hole_index, struct event* e)
{
    
}

void min_heap_shift_down_(min_heap_t* s, size_t hole_index, struct event* e)
{
   
}

#endif /* MINHEAP_INTERNAL_H_INCLUDED_ */
