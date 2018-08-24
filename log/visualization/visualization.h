#ifndef _LOG_RECORDER_H
#define _LOG_RECORDER_H
#ifdef __cplusplus
extern "C" {
#endif
#define MAXSIZE 128
#define MAXLEN  10240
#define record_node_len sizeof(record_node)
#define record_element_len sizeof(record_element)
	typedef struct _record_element
	{
		unsigned short year;
		unsigned char month;
		unsigned char day;
		unsigned char hour;
		unsigned char min;
		unsigned char sec;
		unsigned int type;
		unsigned int key;
		unsigned int oper;
		unsigned int len;
		char data[0];
	}record_element;

	typedef struct _record_node
	{
		unsigned char in_use;
		unsigned short how_many_blocks;
		unsigned int next_offset;
		unsigned int block_offset;

	}record_node;

int visualization(void* addr, int len, int block_size);
#ifdef __cplusplus
}
#endif
#endif