#ifndef _LOG_COMPRESSOR_H
#define _LOG_COMPRESSOR_H

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_TREE_HT  256
#define MAX_CHAR 256
#define READ_LEN 8
#define WRITE_LEN 8
int compress(void *addr_in,int len_in, void*addr_out, int *len_out);

#ifdef __cplusplus
}
#endif
#endif
