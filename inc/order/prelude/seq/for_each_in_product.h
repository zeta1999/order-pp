#ifndef ORDER_PRELUDE_SEQ_FOR_EACH_IN_PRODUCT_H_VAJK20040620
#define ORDER_PRELUDE_SEQ_FOR_EACH_IN_PRODUCT_H_VAJK20040620

/* (C) Copyright Vesa Karvonen 2004.
 *
 *    Distributed under the Boost Software License, Version 1.0.
 */

#define ORDER_DEF_seq_for_each_in_product ORDER_OP_CM(2,8SEQ_FOR_EACH_IN_PRODUCT)
#define ORDER_CM_8SEQ_FOR_EACH_IN_PRODUCT(P,f,s,...)                                                                                        \
(,ORDER_PP_IS_TUPLE(,P##s)(,(,,8SEQ_FOR_EACH_3,(,ORDER_PP_OPEN P##f,8SEQ_FOR_EACH_IN_PRODUCT,ORDER_PP_EAT P##s),ORDER_PP_SEQ_FIRST(,P##s)), \
                           (,)),P##__VA_ARGS__)

#endif
